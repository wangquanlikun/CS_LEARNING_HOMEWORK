//函数被调用的例子如下：
#include <stdio.h>

//判断一个数是否为完全数的函数
int isPerfect(int);//函数原型

//打印完全数的函数 
void printPerfect(int);

int main()
{
    int i,a,b,count;
    
    scanf("%d%d",&a,&b);
    count = 0 ;//a,b两数间完全数的数量，初始化为0 
    for(i=a;i<=b;i++)
    {
        if (isPerfect(i))  //如果是完全数 
        {
            printPerfect(i) ;//打印该完全数 
            count ++ ;  //计数器加1 
        }        
    }
    printf("The total number is %d.\n",count);//输出a,b两数间完全数的数量 
    return 0 ;
}
/* 请在这里填写答案 */
int isPerfect(int n)
{
    int adjust=0;
    int a,sum=0;
    for(a=1;a<=n/2;a++)
    {
        if(n%a==0)
            sum=sum+a;
        if(sum>n)
            break;
    }
    if(n==sum)
        adjust=1;
    return adjust;
}

void printPerfect(int n)
{
    int a,p=0;
    printf("%d=",n);
    for(a=1;a<=n/2;a++)
    {
        if(n%a==0)
        {
            if(p>=1)
                printf("+");
            printf("%d",a);
            p++;
        }
    }
    printf("\n");
}