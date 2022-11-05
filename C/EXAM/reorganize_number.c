//按规定重新组合一个整数。重组的规则为：我们给定一个位置，该位置前的数字不变，指定位置的数字挪到个位，该位置后边的数字依次向前挪一位。
#include <stdio.h>

long long recombination(long long num , int position) ; 

int main()
{
    long long    num ;
    int            position ;
    
    scanf( "%lld%d" , &num , &position );
    printf( "%lld\n" , recombination( num , position) ) ;
    
    return 0;
}

/* 请在这里填写答案 */
int Len(long long num)
{
    int len=1;
    for(;;)
    {
        if(num/10==0)
            break;
        else
        {
            num=num/10;
            len++;
        }
    }
    return len;
}

long long recombination(long long num , int position)
{
    int len=Len(num);
    int mirror_position=len-position+1;
    long long ans_num=num;
    int i;
    long long p=10;
    for(i=1;i<mirror_position;i++)
    {
        p=p*10;
    }
    p=p/10;
    ans_num=(ans_num/p)*p;
    p=p*10;
    ans_num=(ans_num/p)*p+(ans_num-((ans_num/p)*p))/(p/10);
    for(i=1,p=10;i<mirror_position;i++)
    {
        ans_num=(num%10)*p+ans_num;
        num=num/10;
        p=p*10;
    }
    return ans_num;
}