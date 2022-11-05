//两个正整数中，彼此的全部约数之和（本身除外）与另一方相等
#include <stdio.h>

int isAmicable(int number1 , int number2 ) ;

int main()
{
    int        t , num1 , num2 ;
    
    scanf( "%d" , &t ) ;
    
    while ( t -- )
    {
        scanf( "%d%d", &num1 , &num2);
        if ( isAmicable( num1 , num2 ) )    
            printf("YES\n");
        else
            printf("NO\n");        
    }
  
    return 0;
}

/* 请在这里填写答案 */
int Sum(int a)
{
    int sum=0;
    int i;
    for(i=1;i<=a/2;i++)
    {
        if(a%i==0)
            sum=sum+i;
    }
    return sum;
}

int isAmicable(int number1 , int number2 )
{
    int p;
    if(Sum(number1)==number2&&Sum(number2)==number1)
        p=1;
    else
        p=0;
    return p;
}