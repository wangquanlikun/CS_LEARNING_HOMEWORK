#include <stdio.h>

//将n进制转换为m进制 
int numConvert(int,int,int) ; 

int main()
{
    int        number , m , n ;
    
    scanf("%d%d%d",&number,&n,&m);

    printf("%d\n",numConvert(number,n,m));
    return 0 ;
}


/* 请在这里填写答案 */
int len(int n)
{
    int len;
    for (len = 1;;len++)
    {
        if(n/10==0)
            break;
        else
            n = n / 10;
    }
    return len;
}
int numConvert(int number,int n,int m)
{
    //n to 10
    int len1=len(number);
    int i1,ans_10=0;
    int bit1,p1=1;
    for(i1=1;i1<=len1;i1++)
    {
        bit1=number%10;
        ans_10=ans_10+bit1*p1;
        p1=p1*n;
        number=number/10;
    }
    //10 to m
    int ans_m=0;
    int bit2,p2=1;
    do
    {
        bit2=ans_10%m;
        ans_10=ans_10/m;
        ans_m=ans_m+bit2*p2;
        p2=p2*10;
    }while(ans_10!=0);
    return ans_m;
}