//学生的属性包括姓名、学号、5门课程的成绩、平均成绩与总成绩。已知一个学生的姓名、学号与5门课程的成绩，你的任务是计算该学生的平均成绩与总成绩，并将该学生的5门课程成绩按照从高到底进行排序，最后将这个同学的完整信息输出
#include<stdio.h>
struct lib
{
    char name[21];
    char id[21];
    int score[5];
    double ave;
    int total;
};
void order(int p[])
{
    int i1,i2;
    for(i1=1;i1<5;i1++)
    {
        for(i2=0;i2<4;i2++)
        {
            if(p[i2]<p[i2+1])
            {
                int cache=p[i2];
                p[i2]=p[i2+1];
                p[i2+1]=cache;
            }
        }
    }
    return;
}
int main()
{
    struct lib a;
    struct lib *ptr;
    ptr=&a;
    gets(a.name);
    scanf("%s%d%d%d%d%d",a.id,&a.score[0],&a.score[1],&a.score[2],&a.score[3],&a.score[4]);
    int i;
    a.total=0;
    for(i=0;i<5;i++)
        a.total+=a.score[i];
    double cache=a.total;
    a.ave=cache/5;
    printf("Name:%s\n",ptr->name);
    printf("ID:%s\n",ptr->id);
    printf("Score:");
    order(a.score);
    for(i=0;i<5;i++)
    {
        printf("%d",ptr->score[i]);
        if(i==4)
            printf("\n");
        else
            printf(" ");
    }
    printf("average:%.2lf ",ptr->ave);
    printf("total:%d",ptr->total);
    return 0;
}