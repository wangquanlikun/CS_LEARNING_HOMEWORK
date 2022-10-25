//函数被调用例子如下：
#include<stdio.h>

int reverseNum(int) ; 

int main()
{
    int        num ;

    scanf("%d",&num);
    printf("The reverse form of number %d is %d.\n",num,reverseNum(num)) ;

    return 0;
}

/* 请在这里填写答案 */
int reverseNum(int n)
{
    int input=n;
    int len;
    for (len = 1;;len++)
    {
        if(input/10==0)
            break;
        else
            input = input / 10;
    }
    int i,ans=0,p1=1,p2=1,k;
    for(i=1;i<len;i++)
    {
        p1=p1*10;
    }
    for(i=1;i<=len;i++)
    {
        k=n/p1;
        ans=ans+k*p2;
        n=n%p1;
        p2=p2*10;
        p1=p1/10;
    }
    return ans;
}