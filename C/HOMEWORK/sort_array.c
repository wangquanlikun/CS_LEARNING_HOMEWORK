//设计函数，实现对整型数组的排序。
//设计了辅助函数后，函数被调用的例子如下：
#include<stdio.h>

void bubbleSort(int a[],int n);

//输出数组中所有元素 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[10010] ;
    
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    bubbleSort(num,n) ; 
    outputData(num,n) ;
    return 0 ;
}


/* 请在这里填写答案 */
void bubbleSort(int a[],int n)
{
    int i1,i2;
    for(i1=1;i1<=n-1;i1++)
    {
        for(i2=0;i2<n-1;i2++)
        {
            if(a[i2]>a[i2+1])
            {
                int cache=a[i2];
                a[i2]=a[i2+1];
                a[i2+1]=cache;
            }
        }
    }
}

void outputData(int data[],int elementCount)
{
    int i;
    for(i=0;i<elementCount;i++)
    {
        if(i==0)
            printf("%d",data[i]);
        else
            printf(" %d",data[i]);
    }
}