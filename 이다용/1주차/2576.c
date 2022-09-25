#include <stdio.h>
int main()
{
    int I,min=100,sum=0;
    for(int i=0;i<7;i++)
    {
        scanf("%d",&I);
        if (I%2==1)
        {
            sum += I;
            if(I<=min){min=I;}
        }
    }
    if (sum==0){printf("-1");}
    else {printf("%d\n%d",sum,min);}
    return 0;
}
