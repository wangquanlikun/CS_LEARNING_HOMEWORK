//屏蔽词库是一个ASCII码文件，这个文件中只含有单词，每个单词占一行，每个单词中只可能有大小写字母与空格。题目中和谐词库的文件名为dict.dic。（屏蔽词库中每个词汇长度小于10，屏蔽词汇个数不超过10.）
//你的任务是将输入中的所有和谐词库中的词语全部替换成“!@#$%^&*”（按住键盘shift和数字1至8），然后输出
#include<stdio.h>
#include<stdlib.h>
#include<string.h>



void adjust(char str[111],char fxxk[12][12],int fxxknum);
void print(char str[111]);
int main()
{
    FILE *fPtr;
    fPtr = fopen("dict.dic", "r");
    rewind(fPtr);//文件指针复位
    int i, k;
    char fxxk[12][12]={'\0'};//屏蔽词
    int fxxknum;//屏蔽词个数
    for (i = 0; i <= 12&&(!feof(fPtr));i++)
        fgets(fxxk[i], 10 * sizeof(char), fPtr);
    fxxknum = i - 1;
    fclose(fPtr);

    char input[111];
    fgets(input, 111 * sizeof(char), stdin);
    while(!feof(stdin))
    {
        adjust(input,fxxk,fxxknum);
        fgets(input, 111 * sizeof(char), stdin);
    }
    return 0;
}

void adjust(char str[111],char fxxk[12][12],int fxxknum)
{
    int i, k;
    for (i = 0; i < fxxknum;i++)
    {
        // 这时屏蔽词的字符串是fxxk[i];
        k = 0;
        while(k<111&&str[k]!='\n')
        {
            if(str[k]!=fxxk[i][0])
                k++;
            else if(str[k]==fxxk[i][0])
            {
                int cachek = k;
                int k2 = 0;
                int p = 1;//如果p=0就是没有比对上
                while(1)
                {
                    if(fxxk[i][k2]=='\n')
                        break;
                    if(str[k]!=fxxk[i][k2])
                    {
                        p = 0;
                        break;
                    }
                    else if(str[k]==fxxk[i][k2])
                    {
                        k++;
                        k2++;
                    }
                }
                if(p==0)
                    k = cachek + 1;
                else if(p==1)
                {
                    for (k2 = cachek; k2 <= k - 1; k2++)
                    {
                        int remain = cachek % 10;
                        str[k2] = remain + '0';//这是一种校验码机制。因为屏蔽词最长为10，设置0~9共十种的校验码可以防止两个屏蔽词挨着时只输出一遍 !@#$%^&* 
                    }
                }
            }
        }
    }
    print(str);
    return;
}
void print(char str[111])
{
    int i;
    for (i = 0; i < 111&&str[i]!='\n';)
    {
        if(str[i]<'0'||str[i]>'9')
        {
            printf("%c", str[i]);
            i++;
        }
        else
        {
            char cache = str[i];
            printf("!@#$%%^&*");
            while(str[i]==cache)//同上的校验码检验。非常好用(￣y▽,￣)╭ 
                i++;
        }
    }
    printf("\n");
    return;
}