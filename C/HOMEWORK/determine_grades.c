#include<stdio.h>
int main()
{
    int i;
    scanf("%d",&i);
    if(i<0||i>100)
        printf("The score is out of range!");
    else if(i>=90)
        printf("A");
    else if(i<90&&i>=80)
        printf("B");
    else if(i<80&&i>=70)
        printf("C");
    else if(i<70&&i>=60)
        printf("D");
    else if(i<60)
        printf("E");
    return 0;
}
