//请设计一个函数，参数为一个单词（字符串），假设max是单词中出现次数最多的字母的出现次数，min是单词中出现次数最少的字母的出现次数，如果max-min是一个质数，则返回则max-min，否则返回-1

#include<stdio.h>

#define        MAXLEN        110

//判断一个整数是否为质数的函数不需要实现，要求直接调用下边的函数来判断
int        isPrime( int n ) ;//判断一个整数是否是质数，是则返回1，否则返回0 
int        getResult( char word[] ) ;

int main()
{
    char    word[MAXLEN] ;

    scanf( "%s" , word ) ;            
    printf( "%d\n" , getResult( word ) );

    return 0;
}

/* 请在这里填写答案 */
int getResult( char word[] )
{
    int i;
    int sta[128]={0};
    for(i=0;i<MAXLEN;i++)
    {
        char c=word[i];
        if(c=='\0')
            break;
        else if(c!='\0')
            sta[c]++;
    }
    for(i=='a';i<='z';i++)
    {
        if(sta[i]!=0)
            break;
    }
    int ii;
    int max=sta[i];
    int min=sta[i];
    for(ii=i;ii<='z';ii++)
    {
        if(sta[ii]!=0)
        {
            if(sta[ii]>max)
                max=sta[ii];
            if(sta[ii]<min)
                min=sta[ii];
        }
    }
    if(isPrime(max-min)==1)
        return max-min;
    else
        return -1;
}