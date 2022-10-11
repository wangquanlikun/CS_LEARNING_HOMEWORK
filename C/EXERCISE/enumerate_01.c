#include<stdio.h>
int main()
{
    int a, b, c, d, e;
    int aa, bb, cc, dd, ee;
    for (aa = 1; aa <= 5;aa++)
    {
        for (bb = 1; bb <= 5;bb++)
        {
            if(bb!=aa)
            for (cc = 1; cc <= 5;cc++)
            {
                if(cc!=aa&cc!=bb)
                for (dd = 1; dd <= 5;dd++)
                {
                    if(dd!=aa&&dd!=bb&&dd!=cc)
                    for (ee = 1; ee <= 5;ee++)
                    {
                        if(ee!=aa&&ee!=bb&&ee!=cc&&ee!=dd)
                        {
                            a = aa, b = bb, c = cc, d = dd, e = ee;
                            printf("A:%d B:%d C:%d D:%d E:%d\n", a, b, c, d, e);
                        }
                    }
                    
                }
            }
        }
    }
    return 0;
}
