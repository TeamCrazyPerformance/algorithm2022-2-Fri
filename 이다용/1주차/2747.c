#include <stdio.h>

int main()
{
    int a=0, b=1;
    int n,temp;
    scanf("%d",&n);
    for(int i=2;i<=n;i++)
    {
        temp=b; b=a+b; a=temp;
    }
    printf("%d",b);
    return 0;
    
}
