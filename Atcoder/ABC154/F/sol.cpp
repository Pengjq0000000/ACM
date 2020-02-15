#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 2e6 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int sub(int x, int y) {int res = x - y; if (res < 0) res += mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b >>= 1;
    }
    return res;
}
int fac[MAXN], inv[MAXN];
inline int C(int n, int m) {return mul(fac[n], mul(inv[m], inv[n - m]));}
int main()
{
    int N = 2e6 + 2;
    fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N] = ksm(fac[N], mod - 2); for (int i = N; i >= 1; --i) inv[i - 1] = mul(inv[i], i);
    int r1, c1, r2, c2; scanf("%d%d%d%d", &r1, &c1, &r2, &c2);
    int ans = 0;
    for (int i = c1; i <= c2; i++) 
        ans = add(ans, sub(C(r2 + i + 1, i + 1), C(r1 + i, i + 1)));
    printf("%d\n", ans);
    return 0;
}