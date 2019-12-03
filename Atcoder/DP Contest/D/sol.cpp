#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 +7;
ll dp[MAXN];
int main()
{
    int n, W; scanf("%d%d", &n, &W);
    ll ans = 0;
    for (int i = 1, w, v; i <= n; i++)
    {
        scanf("%d%d", &w, &v);
        for (int j = W; j >= w; --j) ans = max(ans, dp[j] = max(dp[j], dp[j - w] + v));
    }
    printf("%lld\n", ans);
    return 0;
}