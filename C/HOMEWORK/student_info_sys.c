/*创建学生信息管理系统，具体要求如下：
学生信息包括：学号 姓名 数学成绩 英语成绩 计算机成绩
功能1：添加学生信息
执行1时，输入学号，姓名，三门科目成绩；如果添加学生成功则输出“Add success”，如果学生已存在则输出“Students already exist”
功能2：删除学生信息
执行2时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出“Delete success”
功能3：更改学生成绩信息
执行3时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，输出“Update success”
功能4：显示学生平均分成绩
执行4时，输入学号信息；如果学生不存在，输出“Students do not exist”，如果存在，则输出学生信息，如下格式：
Student ID:2019989890
Name:Jerry
Average Score:89.3
其中平均分为三门科目相加除以3，保留一位小数，每行之间换行。*/
#include<stdio.h>
#include<string.h>
struct stu
{
    char id[11];
    char name[11];
    int score[3];
};
int findstu(struct stu a[],int exist,char id[11],int order)
{
    int k,p=0;
    for(k=0;k<exist;k++)
    {
        if(strcmp(id,a[k].id)==0)
        {
            p=1;
            break;
        }
    }
    if(order==2&&p==1)
        a[k].id[0]='X';//删除已存在的学生信息.保证无法检索
    else if(order==3&&p==1)//更新学生信息
        scanf("%d%d%d",&a[k].score[0],&a[k].score[1],&a[k].score[2]);
    else if(order==4&&p==1)//输出学生信息
    {
        printf("Student ID:%s\n",a[k].id);
        printf("Name:%s\n",a[k].name);
        float total=a[k].score[0]+a[k].score[1]+a[k].score[2];
        float ave=total/3;
        printf("Average Score:%.1f\n",ave);
    }
    return p;
}

int main()
{
    int num;
    scanf("%d",&num);
    int k,exist=0;
    struct stu a[num];
    for(k=0;k<num;k++)
    {
        int order;
        scanf("%d ",&order);
        scanf("%s",a[exist].id);
        
        if(order==1)
        {
            if(findstu(a,exist,a[exist].id,1)==1)
            {
                getchar();
                scanf("%s",a[exist].name);
                scanf("%d%d%d",&a[exist].score[0],&a[exist].score[1],&a[exist].score[2]);//读取多余的内容
                printf("Students already exist\n");
            }
            else if(findstu(a,exist,a[exist].id,1)==0)
            {
                getchar();
                scanf("%s",a[exist].name);
                scanf("%d%d%d",&a[exist].score[0],&a[exist].score[1],&a[exist].score[2]);
                exist++;
                printf("Add success\n");
            }
        }
        
        else if(order==2)
        {
            if(findstu(a,exist,a[exist].id,2)==1)
                printf("Delete success\n");
            else if(findstu(a,exist,a[exist].id,2)==0)
                printf("Students do not exist\n");
        }
        
        else if(order==3)
        {
            if(findstu(a,exist,a[exist].id,3)==1)
                printf("Update success\n");
            else if(findstu(a,exist,a[exist].id,3)==0)
            {
                int a, b, c;
                scanf("%d%d%d", &a, &b, &c);//读取多余的内容
                printf("Students do not exist\n");
            }
        }
        
        else if(order==4)
        {
            if(findstu(a,exist,a[exist].id,4)==1)
                ;
            else if(findstu(a,exist,a[exist].id,4)==0)
                printf("Students do not exist\n");
        }
    }
    return 0;
}