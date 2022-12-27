#include<stdio.h>

#define        MAX        100

int findMin(int numbers[], int first, int n) ;

int main()
{
    int        i , n , numbers[MAX];
    
    scanf( "%d" , &n ) ;
    for ( i = 0 ; i < n ; i++ )
        scanf( "%d" , &numbers[i] ) ;
    printf( "min = %d\n" , findMin( numbers , 0 , n ) ) ;

    return 0;
} 


/* 请在这里填写答案 */
int findMin(int numbers[], int first, int n)
{
    if(first==n-1)
    {
        printf("%d\n",numbers[first]);
        return numbers[first];
    }
    else
    {
        int min=findMin(numbers,first+1,n);
        if(numbers[first]<min)
            min=numbers[first];
        printf("%d\n",min);
        return min;
    }
}