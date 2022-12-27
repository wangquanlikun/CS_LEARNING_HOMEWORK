#include<stdio.h>

#define        MAX        100

void insert( int A[] , int B[] , int lenA , int lenB , int pos) ;
void create( int array[] , int num ) ;

int main()
{
    int        A[MAX] , B[MAX] ;
    int        i , m , n , pos ;
    
    scanf( "%d%d%d" , &m , &n , &pos ) ;
    create( A , m) ;
    create( B , n) ;
    insert( A , B , m , n , pos ) ;
    
    for ( i = 0 ; i < m + n ; i ++ )
    {
        if ( i == m + n - 1 ) printf("%d\n" , A[i]) ;
        else printf("%d " , A[i]) ;
    }

    return 0;
} 


/* 请在这里填写答案 */
void create( int array[] , int num )
{
    int i;
    for(i=0;i<num;i++)
        scanf("%d",&array[i]);
    return;
}
void insert( int A[] , int B[] , int lenA , int lenB , int pos)
{
    int i1,i2;
    for(i1=0;i1<lenB;i1++)
    {
        for(i2=lenA-1;i2>=pos;i2--)
            A[i2+1]=A[i2];
        A[i2+1]=B[i1];
        lenA++;
        pos++;
    }
}