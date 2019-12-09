#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll dp[20007];
struct node{int w, s; ll v;}a[1007];
bool cmp(node &x, node &y) {return x.w + x.s < y.w + y.s;}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d%lld", &a[i].w, &a[i].s, &a[i].v);
    sort(a + 1, a + 1 + n, cmp);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = a[i].s + a[i].w; j >= a[i].w; j--)
            ans = max(ans, dp[j] = max(dp[j], dp[j - a[i].w] + a[i].v));
    printf("%lld\n", ans);
    return 0;
}