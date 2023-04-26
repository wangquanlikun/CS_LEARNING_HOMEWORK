//过滤注释
//C语言的注释分为两种，第一种：在一行源代码中“//”后的内容为注释内容。第二种:“/*”与“*/”之间的内容为注释内容。第三种：程序中只出现了“/*”，没有“*/”与之对应，那么将“/*”后的全部内容都要过滤掉。注意，只要是注释内容，那么注释内容中的字符应该全部忽略，即不起任何的作用。例如“/*”与“*/”之间如果再有“//”，那么“//”不应起作用；如果“//”再有“/*”，那么“/*”也不应起作用。
//你的任务是先打开一个名字为dict.dic的文本文件，该文件中前5行每行为1个整数，从第6行开始为5段C语言的源代码。那5个数字代表这5段源代码结束的行数，比如如果第一行的整数为20，第二行的整数为60，则表示从第6行到第20为第一段代码，从第21行到第60为第二段代码。然后根据输入要求将源代码中所有注释过滤掉。
#include<stdio.h>
#include<stdlib.h>
void filroperation(FILE *fPtr,int a[5]);
int main()
{
    FILE *fPtr;
    fPtr = fopen("dict.dic", "r");
    rewind(fPtr);//文件指针复位
    int a[5];//5个数字代表这5段源代码结束的行数
    int k;
    for (k = 0; k < 5;k++)
        fscanf(fPtr, "%d", &a[k]);
    filroperation(fPtr,a);
    fclose(fPtr);
    return 0;
}
void filroperation(FILE *fPtr,int a[5])
{
    int line = 6, i = 0;
    int printnum;
    scanf("%d", &printnum);//输出第几组代码
    char c;
    int p = 0;//p=1意味着在/**/之间，p=2意味着在//之后
    int k = 0;//k=1意味着已经读入了一个/
    fgetc(fPtr);
    c = fgetc(fPtr);
    while(!feof(fPtr))
    {
        if(c=='\n')
            line++;
        if(line==a[i]+1)//这一组代码读完了
        {
            i++;
            if(printnum==i+1)
                c = fgetc(fPtr);
            if(k==1&&c=='\n'&&printnum==i)
            {
                printf("/%c", c);
            }
            k = 0;
            p = 0;
        }
        if(i+1>printnum)
            return;

        if(p==0)
        {
            if(k==0)
            {
                if(c!='/'&&printnum==i+1)
                    printf("%c", c);
                else if(c=='/')
                    k = 1;
            }
            else if(k==1)
            {
                if(c=='/')
                {
                    k = 0;
                    p = 2;
                }
                else if(c=='*')
                {
                    k = 0;
                    p = 1;
                }
                else
                {
                    k = 0;
                    if(printnum==i+1)
                        printf("/%c",c);//has read‘/’但是不匹配的情况，比如a/b的使用等
                }
            }
        }
        else if(p==1)
        {
            if(k==0&&c=='*')
                k = 1;
            else if(k==1&&c=='/')
            {
                p = 0;
                k = 0;
            }
            else if(k==1&&c=='*')
                k = 1;
            else if(k==1&&c!='/')
                k = 0;
        }
        else if(p==2)
        {
            if(c=='\n')
            {
                p = 0;
                if(printnum==i+1)
                    printf("\n");
            }
        }

        c = fgetc(fPtr);
    }
    return;
}