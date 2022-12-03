//已知正整数n，n的范围不确定。从键盘读入n个字符串，每个字符串的长度小于1000，要保存到动态数组中。为了能访问到所有的字符串，需要建立一个长度为n的动态指针数组，用于保存n个字符数组的内存地址。在读入每个字符串时，用一个长度为1000的字符数组作为缓冲数组，将字符串读入并求出长度后，再动态分配空间，将缓冲数组中的字符串复制到新分配的动态空间中，并将动态空间的首地址保存到指针数组中。读完n个字符串后你要将这n个字符串按照ASCII码顺序升序排序，然后再打印到屏幕上。字符串中可能包含大小写字母“A-Z”、“a—z”与空格字符。每个字符串以换行符结束输入
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void pai(char *ptr[],int n);
void swap(char *m[],int n);
int main()
{
    int n;
    scanf("%d",&n);
    getchar();//清除回车符
    char **a;
    a=malloc(sizeof(char *)*n);
    int i;
    char cache[1000];
    for(i=0;i<n;i++)
    {
        gets(cache);
        int p=strlen(cache);
        a[i]=malloc(sizeof(char)*(p+1));
        int q;
        for(q=0;q<p;q++)
            a[i][q]=cache[q];
        a[i][p]='\0';
    }
    pai(a,n);
    for (int i = 0; i <n ; i++) {
        puts(a[i]);
    }
    return 0;
}

void swap(char *m[],int n)
{
    char *a;
    a=m[n];
    m[n]=m[n+1];
    m[n+1]=a;
}
void pai(char *ptr[],int n)
{
    int c;
    for (int i = 1; i <=n-1 ; i++) {
        for (int j = 0; j <n-i ; j++) {
            c=strcmp(ptr[j],ptr[j+1]);
            if (c>0){
                swap(ptr,j);
            }
        }
    }
}
