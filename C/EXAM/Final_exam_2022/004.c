#include <stdio.h>
#include <stdlib.h>

typedef struct piece
{
    int x;
    int y;
} PIECE;//保存一个棋子坐标的结构 

PIECE * getMemory( int n ) ;
int        check( PIECE * pieces , int n ) ;

int main()
{
    PIECE    *pieces ;
    int        i ;
    const    int  num = 5 ;

    pieces = getMemory( num ) ;
    if ( pieces == NULL )
        return -1 ; //这里的return是因为没有获得内存而直接结束程序。
        
    for( i = 0 ; i < num ; i++ )
    {
        scanf( "%d%d" , &pieces[i].x, &pieces[i].y ) ;
    } 
    
    if ( check( pieces , num ) )  printf("WIN\n");
    else            printf("NO\n");
    
    for( i = 0 ; i < num ; i++ )
    {
        printf( "%d %d\n" , pieces[i].x, pieces[i].y ) ;
    } 
    
    free( pieces ) ;

    return 0;
} 



/* 请在这里填写答案 */
PIECE * getMemory( int n )
{
    PIECE *ptr=malloc(sizeof(PIECE)*n);
    return ptr;
}

int check( PIECE * pieces , int n )
{
    int space[30][30]={0};
    int i,i2;
    int adjust=0;
    for(i=0;i<5;i++)
        space[(pieces[i].x)+5][(pieces[i].y)+5]=1;
    int m=(pieces[0].x)+5;
    int q=(pieces[0].y)+5;
    
    for(i2=-4;i2<=0;i2++)
    {
        if(space[m+i2][q]==1&&space[m+4+i2][q]==1&&space[m+3+i2][q]==1&&space[m+2+i2][q]==1&&space[m+1+i2][q]==1)
        {
            adjust=1;
            break;
        }
    }
    for(i2=-4;i2<=0;i2++)
    {
        if(space[m][q+i2]==1&&space[m][q+4+i2]==1&&space[m][q+3+i2]==1&&space[m][q+2+i2]==1&&space[m][q+1+i2]==1)
        {
            adjust=1;
            break;
        }
    }
    int k1,k2;
    for(k1=1;k1<=5;k1++)
    {
        for(k2=0;k2<4;k2++)
        {
            if((pieces[k2].x>pieces[k2+1].x)||((pieces[k2].x==pieces[k2+1].x)&&(pieces[k2].y>pieces[k2+1].y)))
            {
                PIECE cache;
                cache=pieces[k2];
                pieces[k2]=pieces[k2+1];
                pieces[k2+1]=cache;
            }
        }
    }
    return adjust;
}