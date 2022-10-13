#include<stdio.h>
int main()
{
    long long input;
    scanf("%lld", &input);
    int i, p;
    int k;
    int cache;
    printf("%lld=", input);
    return1:
    for (i=2;i<=input&&input!=1;i=i+1)
    {
		p=1; 
		for(k=2;k<i;k=k+1)
		{
			if(i % k == 0)
			{
				p=0;
				break;
			}
		}
		if(p == 1)
		{
            cache = i;
        }
        if(input%i==0)
        {
            input = input / i;
            printf("%d ", i);
            goto return1;
        }
    }
    return 0;
}