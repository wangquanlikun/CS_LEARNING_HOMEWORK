#include<stdio.h>
int main()
{
    char c[200+1];
    int ans = 0;
    gets(c);
    int i;
    for (i = 0; c[i]!='\0';i++)
    {
        if(c[i]=='a'||c[i]=='d'||c[i]=='g'||c[i]=='j'||c[i]=='m'||c[i]=='p'||c[i]=='t'||c[i]=='w'||c[i]==' ')
            ans = ans + 1;
        else if(c[i]=='b'||c[i]=='e'||c[i]=='h'||c[i]=='k'||c[i]=='n'||c[i]=='q'||c[i]=='u'||c[i]=='x')
            ans = ans + 2;
        else if(c[i]=='c'||c[i]=='f'||c[i]=='i'||c[i]=='l'||c[i]=='o'||c[i]=='r'||c[i]=='v'||c[i]=='y')
            ans = ans + 3;
        else if(c[i]=='s'||c[i]=='z')
            ans = ans + 4;
    }
    printf("%d", ans);
    return 0;
}
