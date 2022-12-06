//有n名学生，每个学生的属性包括姓名与总成绩。已知学生的姓名与总成绩，你的任务是将学生的信息按照以下方式排序：首先比较总成绩，总成绩高的在前面，总成绩低的在后面，当总成绩相同时，你要比较学生的姓名，姓名字典序小的同学在前面，姓名字典序大的同学在后面
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct name
{
    char name[21];
    int score;
};

void order(struct name a[],int n)
{
    int i1,i2;
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<n-1;i2++)
        {
            if(a[i2].score<a[i2+1].score)
            {
                struct name cache=a[i2];
                a[i2]=a[i2+1];
                a[i2+1]=cache;
            }
            else if(a[i2].score==a[i2+1].score)
            {
                if(strcmp(a[i2].name,a[i2+1].name)>0)
                   {
                       struct name cache=a[i2];
                       a[i2]=a[i2+1];
                       a[i2+1]=cache;
                   }
            }
        }
    }
}

int main()
{
    int n,k;
    scanf("%d",&n);
    struct name a[n];
    for(k=0;k<n;k++)
    {
        getchar();
        scanf("%s %d",a[k].name,&a[k].score);
    }
    order(a,n);
    for(k=0;k<n;k++)
    {
        printf("Name:%s\n",a[k].name);
        printf("total:%d",a[k].score);
        printf("\n\n");
    }
    return 0;
}