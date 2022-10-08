#include<stdio.h>
int main()
{
    int line;
    scanf("%d",&line);
    int i;
    int num;
    int count;
    for(i=1;i<=line;i++)
    {
        count = 0;
        for(;;)
        {
            scanf("%d",&num);
            if(num==-1)
                break;
            int p=1;
            int i;
            for (i = 2; i < num;i++)
                {
                    if(num%i==0)
                    {
                        p = 0;
                        break;
                    }
                }
        if(p==1)
        count=count+1;
        }
        printf("%d\n",count);
    }
    return 0;
}
