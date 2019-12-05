#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
inline int lowbit(int x) {return x & -x;}
int n, h[MAXN];
ll dp[MAXN], a[MAXN];
void update(int x, ll v) {for (; x <= n; x += lowbit(x)) dp[x] = max(dp[x], v);}
ll query(int x) {ll res = 0; for (; x; x -= lowbit(x)) res = max(res, dp[x]); return res;}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), update(h[i], query(h[i] - 1) + a[i]);
    printf("%lld\n", query(n));
    return 0;
}