#include <stdio.h>
//写一个根据学生成绩来确定综合成绩排名的程序
typedef struct
{
    char    id[16]  ;//学生账号 
    int        total ;    //综合成绩 
    int        ce ;    //机试成绩 
    int        ws ;    //加权成绩 
}STUDENT;

void Sort(STUDENT a[],int size) ; 
void Swap(STUDENT * s1,STUDENT * s2) ;
int  Comp(STUDENT * s1,STUDENT * s2) ;

int main()
{
    STUDENT    stu[100] ;
    int        i , n ;
    
    
    scanf("%d",&n) ;
    for(i=0;i<n;i++)
    {
        scanf("%s%d%d",stu[i].id,&stu[i].ce,&stu[i].ws) ;
        stu[i].total = stu[i].ce+stu[i].ws ;
    }
            
    Sort(stu,n) ;
    for(i=0;i<n;i++)
        printf("%s %d %d %d\n",stu[i].id,stu[i].total,stu[i].ce,stu[i].ws) ;
    
    return 0;    
}

/* 请在这里填写答案 */
void Swap(STUDENT * s1,STUDENT * s2)
{
    STUDENT a;
    a=*s1;
    *s1=*s2;
    *s2=a;
    return;
}
int Comp(STUDENT * s1,STUDENT * s2)
{
    int p;
    if(s1->total>=s2->total)
    {
        if(s1->total>s2->total)
            p=1;
        else if(s1->total=s2->total)
        {
            if(s1->ce>s2->ce)
                p=1;
            else
                p=0;
        }
    }
    else if(s1->total<s2->total)
        p=0;
    return p;
}
void Sort(STUDENT a[],int size)
{
    int i1,i;
    for(i1=0;i1<size;i1++)
    {
        for(i=0;i<size-1;i++)
        {
            STUDENT *s1=&a[i],*s2=&a[i+1];
            if(Comp(s1,s2)==0)
                Swap(s1,s2);
        }
    }
}