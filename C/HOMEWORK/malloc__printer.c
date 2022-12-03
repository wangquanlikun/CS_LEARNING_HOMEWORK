#include<stdio.h>
#include<stdlib.h>

char ** create1(int n) ;
void create2( char ** strPtr , int n ) ;
void fill(char ** strPtr , int n) ;


int main()
{
    int        n, i;
    char**    strPtr ;

    scanf("%d", &n );
    strPtr = create1( n * 2 + 1 ) ;
    create2( strPtr ,  n * 2 + 1 ) ;
    fill(strPtr , n) ;

    for (i = 0; i < 2 * n + 1; i++)
    {
        printf("%s\n" , strPtr[i]);
    }
    
    for ( i = 0 ; i < n * 2 + 1 ; i++ )
        free(strPtr[i]) ;
    free(strPtr) ;

    return 0;
}

/* 请在这里填写答案 */
char ** create1(int n)
{
    char **c;
    c=malloc(sizeof(char *)*n);
    return c;
}

void create2( char ** strPtr , int n )
{
    int i;
    for(i=0;i<n;i++)
    {
        strPtr[i]=malloc(sizeof(char)*(n+1));
    }
    return;
}

void fill(char ** strPtr , int n)
{
    int i1,i2,i3,i4;
    
    for(i2=0;i2<n;i2++)
        strPtr[0][i2]=' ';
    strPtr[0][n]='X';
    strPtr[0][n+1]='\0';
    
    for(i1=1;i1<n;i1++)
    {
        for(i2=0;i2<n-i1;i2++)
            strPtr[i1][i2]=' ';
        strPtr[i1][i2]='/';
        i2++;
        for(i4=i2;i4<i2+2*i1-1;i4++)
            strPtr[i1][i4]=' ';
        strPtr[i1][i4]='\\';
        strPtr[i1][i4+1]='\0';
    }
    
    strPtr[n][0]='X';
    for(i2=1;i2<2*n;i2++)
        strPtr[n][i2]=' ';
    strPtr[n][2*n]='X';
    strPtr[n][2*n+1]='\0';
    
    for(i1=2*n-1,i3=1;i1>n;i1--,i3++)
    {
        for(i2=0;i2<n-i3;i2++)
            strPtr[i1][i2]=' ';
        strPtr[i1][i2]='\\';
        i2++;
        for(i4=i2;i4<i2+2*i3-1;i4++)
            strPtr[i1][i4]=' ';
        strPtr[i1][i4]='/';
        strPtr[i1][i4+1]='\0';
    }
    
    for(i2=0;i2<n;i2++)
        strPtr[2*n][i2]=' ';
    strPtr[2*n][n]='X';
    strPtr[2*n][n+1]='\0';
    
    return;
}
