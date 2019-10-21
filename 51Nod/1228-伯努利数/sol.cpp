#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
const int maxn = 2007;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(ll x, ll y) {ll res = x * y; res -= res / mod * mod; return res;}
int ksm(ll a, int b)
{
    int res = 1; a = mul(a, 1);
    while (b) 
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    assert(res >= 0);
    return res;
}
int B[maxn], fac[maxn], inv[maxn];
int C(int n, int m)
{
    if (n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}
int main()
{
    fac[0] = 1; for (int i = 1; i <= 2005; i++) fac[i] = mul(fac[i - 1], i);
    inv[2005] = ksm(fac[2005], mod - 2);
    for (int i = 2005; i >= 1; i--) inv[i - 1] = mul(inv[i], i);
    B[0] = 1;
    for (int n = 1; n <= 2005; n++) 
    {
        int tmp = 0;
        for (int k = 0; k < n; k++) tmp = add(tmp, mul(B[k], C(n + 1, k))); 
        B[n] = mod - mul(ksm(n + 1, mod - 2), tmp);
    }
    int T; scanf("%d", &T);
    while (T--)
    {
        ll n; int k; scanf("%lld%d", &n, &k);
        int ans = ksm(k + 1, mod - 2), tmp = 0;
        for (int i = 0, A, x; i <= k; i++)
        {
            A = (i & 1) ? ksm(mod - 1, i) : 1;
            x = mul(C(k + 1, i), ksm(n, k + 1 - i));
            tmp = add(tmp, mul(B[i], mul(A, x)));
        }
        ans = mul(ans, tmp);
        printf("%d\n", ans);
    }
    return 0;
}