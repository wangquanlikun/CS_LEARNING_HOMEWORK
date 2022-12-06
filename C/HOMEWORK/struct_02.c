//有n名学生，每个学生的信息包括姓名、学号、5门课程的成绩，平均成绩与总成绩。已知学生的姓名、学号与5门课程的成绩，你的任务是计算每个学生的平均成绩与总成绩，并将它们输出
#include<stdio.h>
struct lib
{
    char name[21];
    char id[21];
    int score[5];
    double ave;
    int total;
};

int main()
{
    int k, n;
    scanf("%d", &n);
    struct lib a[n];
    for (k = 0; k < n;k++)
    {
    getchar();
    gets(a[k].name);
    scanf("%s%d%d%d%d%d",a[k].id,&a[k].score[0],&a[k].score[1],&a[k].score[2],&a[k].score[3],&a[k].score[4]);
    int i;
    a[k].total=0;
    for(i=0;i<5;i++)
        a[k].total+=a[k].score[i];
    double cache=a[k].total;
    a[k].ave=cache/5;
    printf("Name:%s\n",a[k].name);
    printf("ID:%s\n",a[k].id);
    printf("Score:");
    for(i=0;i<5;i++)
    {
        printf("%d",a[k].score[i]);
        if(i==4)
            printf("\n");
        else
            printf(" ");
    }
    printf("average:%.2lf ",a[k].ave);
    printf("total:%d",a[k].total);
    printf("\n\n");
    }
    return 0;
}