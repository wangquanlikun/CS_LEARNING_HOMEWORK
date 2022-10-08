#include<stdio.h>
#define MOVE 3
int main()
{
    char input,output;
    while((input=getchar())!='\n')
    {
        output=input+3;
        if((input>='a'&&input<='z')&&output>'z')
            output=output-26;
        if((input>='A'&&input<='Z')&&output>'Z')
            output=output-26;
        printf("%c",output);
    }
    return 0;
}
