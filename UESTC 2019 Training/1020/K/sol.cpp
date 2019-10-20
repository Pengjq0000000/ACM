#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1000000007;
const int maxn = 5e5 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int n, m, L, R;
int a[maxn], b[maxn], sum[maxn];
int main()
{
    while (~scanf("%d%d%d%d", &n, &m, &L, &R))
    {
        for (int i = 0; i <= n; i++) scanf("%d", &a[i]);
        for (int i = 0; i <= m; i++) scanf("%d", &b[i]), sum[i] = add(sum[i - 1], b[i]);
        int ans = 0;
        for (int i = 0; i <= n; i++)
        {
            int l = max(0, L - i);
            int r = min(m, R - i);
            if (l <= r)
                ans = add(ans, mul(a[i], add(sum[r] - sum[l - 1], mod)));
        }
        printf("%d\n", ans);
    }
}



