#include<stdio.h>
int main()
{
    int count0 = 0, count1 = 0;
    char c;
    int interval = 0, longest_interval = interval;
    int flag1 = 0;
    while((c=getchar())!='#')
    {
        if(c=='0')
        {
            count0++;
            if(flag1==1)
            {
                interval++;
                if(interval>longest_interval)
                    longest_interval = interval;
            }
            else if(flag1==0)
                ;
        }
        else if(c=='1')
        {
            count1++;
            flag1 = 1;
            interval = 0;
        }
    }
    printf("%d %d %d", count0, count1, longest_interval);
    return 0;
}