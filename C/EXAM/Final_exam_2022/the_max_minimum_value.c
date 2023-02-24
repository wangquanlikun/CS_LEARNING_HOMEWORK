#include<stdio.h>
void sort(int p[],int max);
int check(int loc[], int M, int max,int b);

int main()
{
    int a, b;//输入a个数据，代表a个篮子，在其中放入b个球。求两球之间最小距离的最大值
    int k;
    scanf("%d%d", &a, &b);
    int basket_loc[a+1];
    for (k = 1; k <= a;k++)
        scanf("%d",&basket_loc[k]);
    
    sort(basket_loc, a);//对已有位置进行排序

    //找到二分搜索的边界,即找到最小距离的最小可能取值和最大可能取值
    int min = basket_loc[2] - basket_loc[1];
    for (k = 1; k <= a - 1; k++)
    {
        if(basket_loc[k+1]-basket_loc[k]<min)
            min = basket_loc[k + 1] - basket_loc[k];
    }//遍历数组找到相邻两个位置的最小距离
    //一共有b个球，所以有 b-1 个间隔，最大的可能取值便是最平均的取值。所以根据给定数组最大值与最小值之差与间隔数的比值计算出平均距离，就是给定的最大可能取值
    int max = (basket_loc[a] - basket_loc[1]) / (b - 1);

    //进行二分查找
    int L = min, R = max;
    //确定好了边界后，每次二分搜索时需要判断当前计算值是否满足条件，这里引入 check 函数，对当前计算出的最小距离进行验证
    while(L<R)
    {
        int M = (L + R + 1) / 2;
        if(check(basket_loc,M,a,b))
            L = M;
        else
            R = M - 1;
    }
    printf("%d", R);
    return 0;
}

void sort(int p[],int max)
{
    int a1, a2, cache;
    for (a1 = 1; a1 <= max;a1++)
    {
        for (a2 = 1; a2 <= max - 1; a2++)
        {
            if(p[a2]>p[a2+1])
            {
                cache = p[a2];
                p[a2] = p[a2 + 1];
                p[a2 + 1] = cache;
            }
        }
    }
    return;
}

int check(int loc[], int M, int max,int b)
//遍历数组，若找到两位置之间距离大于等于最小距离，则计数值加 1，最后只需要判断总计数值是否大于等于给定间隔数 b-1 即可
{
    int p = 0;
    int i, pre = 1;
    for (i = 1 + 1; i <= max;i++)
    {
        if((loc[i]-loc[pre])>=M)
        {
            p++;
            pre = i;
        }
        if(p==b-1)
            break;
    }
    return p == b - 1;
}