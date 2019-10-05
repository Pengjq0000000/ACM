#include<bits/stdc++.h>
#define LL long long
using namespace std;
LL cal(LL x)
{
    return x / 2017;
}
int main()
{
    LL a, b, c, d;
    while (scanf("%lld %lld %lld %lld", &a, &b, &c, &d) == 4)
    {
        LL num1 = cal(b) - cal(a - 1), num2 = cal(d) - cal(c - 1);
        LL ans = num1 * (d - c + 1) + num2 * (b - a + 1) - num1 * num2;
        printf("%lld\n", ans);
    }
    return 0;
}