#include<bits/stdc++.h>
#define LL long long
void out(__int128 x)
{
    if (x >= 10) out(x / 10);
    putchar(x % 10 + '0');
}
int main()
{
    LL A, B;
    while (scanf("%lld %lld", &A, &B) == 2)
    {
        __int128 a = A, b = B;
        __int128 ans = a / b;
        if (a % b != 0 && ((a < 0 && b > 0) || (a > 0 && b < 0))) ans--;
        if (ans < 0) 
        {
            putchar('-');
            ans = -ans;
        }
        out(ans); puts("");
    }
    return 0;
}