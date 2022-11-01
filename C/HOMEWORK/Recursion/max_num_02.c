//写一个函数可以读入n（0<n<100）个整数，并求出这n个整数中的最大值
#include <stdio.h>

int findMax(int n) ;

int main()
{   
    int n ; 
    
    scanf("%d", &n); 
    printf("%d\n" , findMax( n ) ) ; 
    
    return 0;
}

/* 请在这里填写答案 */
int findMax(int n)
{
    int in,in_2;
    if(n>=1)
    {
        scanf("%d",&in);
        in_2=findMax(n-1);
        if(in_2>=in)
            return in_2;
        else if(in_2<in)
            return in;
    }
    else if(n==1)
        scanf("%d",&in);
        return in;
}
