#include<stdio.h>
#include<math.h>
int main()
{
    int n,i1,i2,ans=0;
    scanf("%d",&n);
    int fire[n];
    for(i1=0;i1<n;i1++)
        scanf("%d",&fire[i1]);
    for(i1=0;i1<n;i1++)
    {
        for(i2=0;i2<n;i2++)
        {
            if(i1!=i2)
                ans+=fabs(fire[i1]-fire[i2]);
        }
    }
    printf("%d",ans);
    return 0;
}