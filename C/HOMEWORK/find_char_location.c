//设计函数 char *locatesubstr(char *str1,char *str2)，查找str2指向的字符串在str1指向的字符串中首次出现的位置，返回指向该位置的指针。若str2指向的字符串不包含在str1指向的字符串中，则返回空指针NULL
#include <stdio.h>

char *locatesubstr(char *str1,char *str2);
int main()
{
    char str1[505],str2[505];
    char *p;
    gets(str1);
    gets(str2);
    p=locatesubstr(str1,str2);
    
    if(p==NULL)    printf("NULL!\n");
    else    puts(p);
    
    return 0;
}

/* 请在这里填写答案 */
char *locatesubstr(char *str1,char *str2)
{
    char *a;
    int p=0;
    for(a=str1;*a!='\0';a++)
    {
        if(*a=='\0')
            break;
        if(*a==*str2)
        {
            p=1;
            char *b;
            char *d;
            for(b=a,d=str2;;b++,d++)
            {
                if(*b=='\0'||*d=='\0')
                {
                    if(*b=='\0'&&*d!='\0')
                        p=0;
                    break;
                }
                else if(*b!=*d)
                    p=0;
            }
            if(p==1)
                break;
        }
    }
    if(*str2=='\0')
    {
        p=1;
        a=str1;
    }
    if(p==1)
        return a;
    else if(p==0)
        return NULL;
}
