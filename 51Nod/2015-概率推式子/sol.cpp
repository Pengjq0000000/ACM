#include<bits/stdc++.h>
#define ll long long
#define mod 1000000007
using namespace std;
const int maxn = 2e6 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int ksm(int a, int b)
{
    int r = 1; 
    while (b) {if (b & 1) r = mul(r, a); a = mul(a, a); b >>= 1;}
    return r;
}
int p[maxn], a, b, c, pre[maxn];
int len, inv; // inv == 1 / (x - 1)
int main()
{
    int n; scanf("%d", &n); 
    scanf("%d%d%d%d", &p[1], &a, &b, &c);
    for (int i = 2; i <= n; i++) p[i] = add(add(mul(a, mul(p[i - 1], p[i - 1])), mul(b, p[i - 1])), c);
    for (int i = n + 1, ptr = n - 1; ptr > 1; i++, ptr--) p[i] = p[ptr];
    pre[0] = 1; len = 2 * (n - 1);
    for (int i = 1; i <= len; i++) pre[i] = mul(pre[i - 1], 1 - p[i] + mod);
    int x = pre[len]; inv = ksm(1 - x + mod, mod - 2);
    int F = mul(len, mul(x, mul(inv, inv)));
    int ans = 0;
    for (int r = 0, P, G; r < len; r++)
    {
        P = mul(pre[r], p[r + 1]);
        G = mul(r, inv);
        ans = add(ans, mul(P, add(F, G)));
    }
    printf("%d\n", ans);
    return 0;
}