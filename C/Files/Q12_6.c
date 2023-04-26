#include<stdio.h>
#include<stdlib.h>
int main()
{
    FILE *fPtr;
    fPtr=fopen("dict.dic","rb");
    rewind(fPtr);//文件指针复位

    char a,aa[5];
    short b,bb[5];
    int c,cc[5];
    long d,dd[5];
    long long e,ee[5];
    float g,gg[5];
    double h,hh[5];
    int i;

    int tasknum, k;
    scanf("%d", &tasknum);
    for (k = 1; k <= tasknum&&(!feof(fPtr));k++)
    {
        fread(&a, sizeof(a), 1, fPtr);
        fread(&b, sizeof(b), 1, fPtr);
        fread(&c, sizeof(c), 1, fPtr);
        fread(&d, sizeof(d), 1, fPtr);
        fread(&e, sizeof(e), 1, fPtr);
        fread(&g, sizeof(g), 1, fPtr);
        fread(&h, sizeof(h), 1, fPtr);
        fread(aa, sizeof(a), 5, fPtr);
        fread(bb, sizeof(b), 5, fPtr);
        fread(cc, sizeof(c), 5, fPtr);
        fread(dd, sizeof(d), 5, fPtr);
        fread(ee, sizeof(e), 5, fPtr);
        fread(gg, sizeof(g), 5, fPtr);
        fread(hh, sizeof(h), 5, fPtr);
    }

    printf("%c\n", a);
    printf("%hd\n", b);
    printf("%d\n", c);
    printf("%ld\n", d);
    printf("%lld\n", e);
    printf("%f\n", g);
    printf("%lf\n", h);

    for (i = 0; i <= 4&&aa[i]!='\0';i++)
    {
        printf("%c", aa[i]);
    }
    printf("\n");
    for (i = 0; i <= 3; i++)
        printf("%hd ", bb[i]);
    printf("%hd\n", bb[4]);
    for (i = 0; i <= 3; i++)
        printf("%d ", cc[i]);
    printf("%d\n", cc[4]);
    for (i = 0; i <= 3; i++)
        printf("%ld ", dd[i]);
    printf("%ld\n", dd[4]);
    for (i = 0; i <= 3; i++)
        printf("%lld ", ee[i]);
    printf("%lld\n", ee[4]);
    for (i = 0; i <= 3; i++)
        printf("%f ", gg[i]);
    printf("%f\n", gg[4]);
    for (i = 0; i <= 3; i++)
        printf("%lf ", hh[i]);
    printf("%lf", hh[4]);
    fclose(fPtr);
    return 0;
}