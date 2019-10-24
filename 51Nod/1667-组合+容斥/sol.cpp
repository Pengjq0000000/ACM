#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int d[20], M, k1, k2, inv[21];
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
int C(int n, int m)
{
    if (n < 0 || m < 0 || n < m) return 0;
    int res = 1;
    for (int i = 1; i <= m; i++) res = mul(res, mul(n - i + 1, inv[i]));
    return res;
}
int all;
int cal(int n)
{
    int res = 0;
    for (int s = 0; s < (1 << (k1 + k2)); s++)
    {
        int m = M;
        for (int i = 1; i <= k1 + k2; i++) 
            if (s & (1 << (i - 1))) m -= d[i] + 1;
        if (__builtin_popcount(s) & 1) res = add(res, mod - C(n + m - 1, n - 1));
        else res = add(res, C(n + m - 1, n - 1));
    }
    return mul(res, all);
}
int main()
{
    inv[0] = 1; for (int i = 1; i <= 20; i++) inv[i] = ksm(i, mod - 2);
    int T; scanf("%d", &T);
    while (T--)
    {
        M = 0;
        scanf("%d", &k1);
        for (int i = 1, l, r; i <= k1; i++) 
        {
            scanf("%d%d", &l, &r);
            M -= l; d[i] = r - l;
        } 
        scanf("%d", &k2);
        for (int i = k1 + 1, l, r; i <= k1 + k2; i++)
        {
            scanf("%d%d", &l, &r);
            M += r; d[i] = r - l;
        }
        all = 1;
        for (int i = 1; i <= k1 + k2; i++) all = mul(all, d[i] + 1);
        all = ksm(all, mod - 2);
        int ans0 = cal(k1 + k2);
        int ansB = add(cal(k1 + k2 + 1), mod - ans0);
        int ansA = add(1 + mod - ans0, mod - ansB);
        printf("%d %d %d\n", ansA, ans0, ansB);
    }
    
    return 0;
}