#include<stdio.h>
#define MAXLEN 110
int isPrime(int n);
int getResult(char word[]);

int main()
{
    char word[MAXLEN];

    scanf("%s", word);
    if(getResult(word)==0)
        printf("No Answer\n");
    else
        printf("Lucky Word\n");
    printf("%d\n", getResult(word));

    return 0;
}

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
        return 0;
}

int isPrime(int n)
{
    int i;
    int p = 1;
    for (i = 2; i * i <= n;i++)
    {
        if(n%2==0)
        {
            p = 0;
            break;
        }
    }
    if(n==0||n==1)
        p = 0;
    return p;
}
