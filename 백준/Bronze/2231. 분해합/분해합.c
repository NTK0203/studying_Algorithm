#include <stdio.h>

void dividingsum(int);

int main()
{
    int num;
    scanf("%d",&num);
    dividingsum(num);
}

void dividingsum(int num)
{
    for (int j=1;j<num;j++)
    {
        int i=j,t=j;
        while (i>0)
        {
            t=t+i%10;
            i=i/10;
        }

        if (t==num)
        {
            printf("%d",j);
            num=0;
            break;
        }
        if (num==j)
        {
            break;
        }
    }
    if (num!=0)
    {
        printf("0");
    }
}