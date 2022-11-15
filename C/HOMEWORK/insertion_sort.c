//使用插入排序算法，将数组a的前n个元素按照升序的方式排序
//函数被调用的例子如下
#include<stdio.h>

//插入排序（升序） 
//参数说明：数组，数组中已有元素个数 
void InsertSort(int a[],int n);

int main()
{
    int        n , i,    num[1000] ;
    
    scanf( "%d" , &n ); 
    for( i = 0 ; i < n ; i++ ) 
        scanf( "%d", &num[i] ) ;
    InsertSort( num , n ) ; 
    return 0 ;
}

/* 请在这里填写答案 */
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
    printf("\n");
}

void InsertSort(int a[],int n)
{
    int i,j,cache;
    for(i=1;i<n;i++)
    {
        cache=a[i];
        for(j=i;j>0&&a[j-1]>cache;j--)
            a[j]=a[j-1];
        a[j]=cache;
        outputData(a,n);
    }
}