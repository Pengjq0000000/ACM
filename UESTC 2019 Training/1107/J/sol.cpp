#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll a[30010], c[30010];
int n; ll k; 
bool check(ll x)
{
    ll cnt = 0;
    for (int i = 1; i <= n + 1; i++) c[i] = a[i];
    for (int i = 1; i <= n; i++)
    {
        cnt += c[i] / x;
        c[i] %= x;
        if (c[i] + c[i + 1] >= x) 
        {
            cnt++; c[i + 1] -= x - c[i];
        }
    }
    return cnt >= k;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%lld", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        a[n + 1] = 0;
        ll l = 0, r = 1e16;
        while (l < r)
        {
            ll mid = (l + r + 1) >> 1;
            if (check(mid)) l = mid;
            else r = mid - 1;
        }
        printf("%lld\n", k * l);
    }
    return 0;
}