//某公司有四个销售员(代号1—4)，负责销售五种产品(代号1—5)。每个销售员都把当天售出的每种产品各写一张便条交上来。每张便条包含销售员的代号、产品的代号、这种产品的销售额。我们搜集到了每个月的所有便条，你的任务是根据这些便条，计算出每人、每种产品的总销售额。处理完销售信息后，以表格形式打印出结果。用列代表销售员，行代表产品。每种产品的销售总额输出到该行的最右边，每个销售员的销售总额输出到该列的最下边
#include<stdio.h>
int main()
{
    int n;
    scanf("%d",&n);
    float info[5][6]={0};
    int i;
    int a,b;
    float c;
    float ans=0;
    for(i=1;i<=n;i++)
    {
        scanf("%d%d%f",&a,&b,&c);
        info[a][b]+=c;
        ans+=c;
    }
    int i1,i2;
    for(i2=1;i2<=5;i2++)
    {
        for(i1=1;i1<=4;i1++)
        {
            printf("%.1f\t",info[i1][i2]);
        }
        printf("%.1f\n",info[1][i2]+info[2][i2]+info[3][i2]+info[4][i2]);
    }
    for(i1=1;i1<=4;i1++)
    {
        printf("%.1f\t",info[i1][1]+info[i1][2]+info[i1][3]+info[i1][4]+info[i1][5]);
    }
    printf("%.1f",ans);
}