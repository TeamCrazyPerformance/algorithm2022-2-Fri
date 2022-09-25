#include <stdio.h>
#include <string.h>
int main()
{
    char S[100];
    scanf("%s",S);
    int a;
    int b=strlen(S);
    for(int i=97;i<=122;i++)
    {
        a=0;
        for(int j=0;j<b;j++)
        {
            if(S[j]==i)
            {
                a++;
            }
        }
        printf("%d ",a);
    }
    return 0;
}
