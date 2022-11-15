//选择排序算法对数组a的前n个元素按照升序的方式排序
//函数被调用的例子如下

#include<stdio.h>

//选择排序（升序） 
//参数说明：数组，数组中已有元素个数 
void selectSort(int data[],int elementCount) ;

//函数功能：找数组中的最小值元素，并返回其下标 
//参数说明：数组名，查找起始位置下标，查找终止位置下标
int findMin(int data[], int startLoc, int endLoc) ; 

//输出数组中所有元素 
//参数说明：数组，数组中已有元素个数 
void outputData(int data[],int elementCount) ;

int main()
{
    int        n , i,    num[1010] ;
    
    scanf("%d",&n); 
    for( i = 0 ; i < n ; i++ ) 
        scanf("%d",&num[i]) ;
    selectSort(num,n) ; 
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

int findMin(int data[], int startLoc, int endLoc)
{
    int i,i_min=startLoc;
    int min=data[startLoc];
    for(i=startLoc;i<=endLoc;i++)
    {
        if(data[i]<min)
        {
            min=data[i];
            i_min=i;
        }
    }
    return i_min;
}

void selectSort(int data[],int elementCount)
{
    int i,cache;
    for(i=0;i<elementCount-1;i++)
    {
        int min=findMin(data,i,elementCount-1);
        if(data[i]>data[min])
        {
            cache=data[i];
            data[i]=data[min];
            data[min]=cache;
        }
        outputData(data,elementCount);
    }
}