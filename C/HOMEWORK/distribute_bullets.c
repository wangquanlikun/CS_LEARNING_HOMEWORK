//在某次实弹射击训练中，班长让战士们围成一圈发子弹。首先，班长给每个人发若干发子弹，然后按如下方法将每个战士手中的子弹进行调整：所有的战士检查自己手中的子弹数，如果子弹数为奇数，则向班长再要一颗。然后每个战士再同时将自己手中的子弹分一半给下一个战士（最后一个战士将手中的子弹分一半给第1个战士)。这种调整会一直进行下去，直到所有战士手中的子弹数相等为止。现请你写一个函数模拟这个调整的过程

#include<stdio.h>

#define        LEN        100

//调整函数 
void distribute(int * bullets , int size , int number ) ;

int main()
{
    int        bullets[LEN] ;
    int        n , m , i ;    
         
    scanf("%d" , &n ) ;    //读入战士总数 
    for( i = 0 ; i < n ; i++ )
    {
        scanf("%d" , &bullets[i] ) ;//读入每个战士手中初始的子弹数 
    }
    scanf("%d" , &m ) ;//读入调整的次数（m>0) 
    distribute(bullets , n , m ) ;//调整 
    for( i = 0 ; i < n - 1 ; i++ )//输出调整后结果 
    {
        printf("%d " , bullets[i] ) ;
    }
    printf("%d\n" , bullets[i] ) ;
    
    return 0;    
}


/* 请在这里填写答案 */
void distribute(int * bullets , int size , int number )
{
    int i;
    for(i=1;i<=number;i++)
    {
        int i2;
        int cache[size];
        for(i2=0;i2<size;i2++)
        {
            if(bullets[i2]%2!=0)
                bullets[i2]+=1;
            cache[i2]=bullets[i2]/2;
            bullets[i2]/=2;
        }
        for(i2=0;i2<size;i2++)
        {
            if(i2!=0)
                bullets[i2]=bullets[i2]+cache[i2-1];
            else if(i2==0)
                bullets[i2]=bullets[i2]+cache[i2-1+size];
        }
    }
}