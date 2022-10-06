#include<stdio.h>
#define MAX 1000
int main()
{
	int i,k;
	int p;
	int max;
	scanf("%d", &max);

	for(i=2;i<=max;i=i+1)
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
			printf("%d ",i);
		}
	}
	return (0);
} 
