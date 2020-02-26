#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
const int mod = 1e9 + 7;
ll x[MAXN], y[MAXN];
inline ll add(ll x, ll y) {return (x + y) % mod;}
inline ll mul(ll x, ll y) {return (x * y) % mod;}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    ll sum = 0;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%lld", &x[i]);
        sum = add(sum, mul(x[i] - x[i - 1], mul(i - 1, n - i + 1)));
    }
    ll ans = 0;
    for (int i = 1; i <= m; i++)
    {
        scanf("%lld", &y[i]);
        ans = add(ans, mul(sum, mul(y[i] - y[i - 1], mul(i - 1, m - i + 1))));
    }
    printf("%lld\n", ans);
    return 0;
}