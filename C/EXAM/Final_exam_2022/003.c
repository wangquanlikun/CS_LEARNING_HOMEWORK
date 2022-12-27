
#include<stdio.h>

int        code( char s[] ) ;

int main()
{
    int        T;
    char    s[64] ;

    scanf( "%d" , &T );      
    while( T-- )
    {
        scanf("%s",s);
        printf( "%d\n" , code(s) ) ;
    }
    
    return 0;
} 



/* 请在这里填写答案 */
int code(char s[])
{
    int len=0,i;
    char c='A';
    int p=-1;//p状态判断，如果是一样的不重复输出
    for(i=0;c!='\0';i++)
    {
        c=s[i];
        if(c=='\0')
        {
            printf("\n");
            break;
        }
        else if((c=='B'||c=='F'||c=='P'||c=='V')&&p!=1)
        {
            printf("1");
            p=1;
            len++;
        }
        else if((c=='C'||c=='G'||c=='J'||c=='K'||c=='Q'||c=='S'||c=='X'||c=='Z')&&p!=2)
        {
            printf("2");
            p=2;
            len++;
        }
        else if((c=='D'||c=='T')&&p!=3)
        {
            printf("3");
            p=3;
            len++;
        }
        else if((c=='L')&&p!=4)
        {
            printf("4");
            p=4;
            len++;
        }
        else if((c=='M'||c=='N')&&p!=5)
        {
            printf("5");
            p=5;
            len++;
        }
        else if((c=='R')&&p!=6)
        {
            printf("6");
            p=6;
            len++;
        }
        else if(c=='A'||c=='E'||c=='I'||c=='O'||c=='U'||c=='H'||c=='W'||c=='Y')
            p=0;
    }
    return len;
}