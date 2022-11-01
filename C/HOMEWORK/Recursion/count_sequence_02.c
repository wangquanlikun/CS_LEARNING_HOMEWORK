//数列 S=1+a+a^2+…+a^(n+1)
#include <stdio.h>

int    evaluation(int n,int a) ;
int main()
{
       int        n , a ; 
       
       scanf("%d%d",&n,&a);       
       printf("%d\n",evaluation(n,a));

    return 0;
}

/* 请在这里填写答案 */
int an(int a,int n)
{
    if(n==0)
        return 1;
    else
        return a*an(a,n-1);
}
int evaluation(int n,int a)
{
    if(n==-1)
        return 1;
    else if(n>=0)
        return evaluation(n-1,a)+an(a,n+1);
}
