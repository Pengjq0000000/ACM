#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 3e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int cnt[60][2];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        ll x; scanf("%lld", &x);
        for (int j = 0; j < 60; j++) cnt[j][x & 1]++, x /= 2;
    }
    int base = 1, ans = 0;
    for (int j = 0; j < 60; j++) ans = add(ans, mul(mul(cnt[j][0], cnt[j][1]), base)), base = mul(base, 2); 
    printf("%d\n", ans);
    return 0;
}