#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll x[100];
int cnt;
ll cal(ll t)
{
    ll base = 1, res = 0;
    for (int i = 1; i <= cnt; i++)
    {
        res += base * x[i];
        base *= t;
    }
    return res;
}
int main()
{
    ll t, a, b;
    scanf("%lld%lld%lld", &t, &a, &b);
    if (t == 1 && t == a && a == b) {puts("inf"); return 0;}
    ll tmp = b;
    int ans = 0;
    if (a > 1) while (tmp) x[++cnt] = tmp % a, tmp /= a;
    if (a == b) ans++;
    if (cal(t) == a && cal(a) == b) ans++;
    ll bs = 1;
    while (a > 1 && b > a && b % a == 0) 
    {
        b /= a;
        if (b * bs == a) ans++; 
        bs *= t;
    }
    printf("%d\n", ans);
    return 0;
}