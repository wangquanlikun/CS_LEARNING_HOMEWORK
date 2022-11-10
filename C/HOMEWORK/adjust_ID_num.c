//判断一个身份证号码的最后一位是否与上述规则相符
#include<stdio.h>
int main()
{
    int n,i;
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        char num[18+1];
        scanf("%s",num);
        char adjust;
        int ii;
        for(ii=0;ii<17;ii++)
        {
            num[ii]=num[ii]-'0';
        }
        int a=(num[0]*7+num[1]*9+num[2]*10+num[3]*5+num[4]*8+num[5]*4+num[6]*2+num[7]*1+num[8]*6+num[9]*3+num[10]*7+num[11]*9+num[12]*10+num[13]*5+num[14]*8+num[15]*4+num[16]*2)%11;
        if(a==0)
            adjust='1';
        else if(a==1)
            adjust='0';
        else if(a==2)
            adjust='X';
        else if(a==3)
            adjust='9';
        else if(a==4)
            adjust='8';
        else if(a==5)
            adjust='7';
        else if(a==6)
            adjust='6';
        else if(a==7)
            adjust='5';
        else if(a==8)
            adjust='4';
        else if(a==9)
            adjust='3';
        else if(a==10)
            adjust='2';
        if(num[17]==adjust)
            printf("right\n");
        else if(num[17]!=adjust)
            printf("wrong\n");
    }
    return 0;
}