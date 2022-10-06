#include<stdio.h>
#define EXIST 5
int main()
{
    int i, grade, id;
    int max, max_id;
    scanf("%d %d", &grade, &id);
    max = grade;
    max_id = id;
    for (i = 1; i < EXIST;i++)
    {
        scanf("%d %d", &grade, &id);
        if(grade>max)
        {
            max = grade;
            max_id = id;
        }
    }
    printf("id=%d\tgrade=%d", max_id, max);
}