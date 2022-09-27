#include <stdio.h>
int main()
{
    int a, sum = 0;
    scanf("%d", &a);
    for ( int i = 1; i <= a; i*=10) // logn
    {
        sum += a-i+1; //1~a 까지 i의자리가 존재하는 수만큼 sum에 더함 ex: 120 1의자리:120, 10의 자리 111, 100의자리 21 => sum =252
    }
    printf("%d", sum);
    return 0;
}
// 참조: https://gusdnr69.tistory.com/89
