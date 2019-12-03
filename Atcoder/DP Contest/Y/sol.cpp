#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 3007;
const int mod = 1e9 + 7;
const int N = 2e5;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
pii p[MAXN];
int fac[N + 1], inv[N + 1], dp[MAXN];
inline int C(int n, int m) 
{
    if (n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}
int main()
{
    fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N] = ksm(fac[N], mod - 2); for (int i = N; i; --i) inv[i - 1] = mul(inv[i], i);
    int H, W, n; scanf("%d%d%d", &H, &W, &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].fir, &p[i].sec);
    sort(p + 1, p + 1 + n);
    for (int i = 1, x, y; i <= n; i++)
    {
        x = p[i].fir, y = p[i].sec;
        dp[i] = C(x - 1 + y - 1, x - 1);
        for (int j = 1; j < i; j++) if (p[j].fir <= x && p[j].sec <= y)
            dp[i] = add(dp[i], mod - mul(dp[j], C(x - p[j].fir + y - p[j].sec, x - p[j].fir)));
    }
    int ans = C(H - 1 + W - 1, H - 1);
    for (int i = 1; i <= n; i++) ans = add(ans, mod - mul(dp[i], C(H - p[i].fir + W - p[i].sec, H - p[i].fir)));
    printf("%d\n", ans);
    return 0;
}