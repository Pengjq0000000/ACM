#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
const int MAXN = 2e6 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int fac[MAXN], inv[MAXN];
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
inline int C(int n, int m) {return mul(fac[n], mul(inv[m], inv[n - m]));}
int main()
{
    int x, y; scanf("%d%d", &x, &y);
    int a = (2 * y - x) / 3, b = (2 * x - y) / 3;
    if (a * 3 != 2 * y - x || b * 3 != 2 * x - y || a < 0 || b < 0) 
    {
        puts("0");
        return 0;
    }
    int N = 2000000;
    fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N] = ksm(fac[N], mod - 2); for (int i = N; i; --i) inv[i - 1] = mul(inv[i], i);
    printf("%d\n", C(a + b, b));
    return 0;
}