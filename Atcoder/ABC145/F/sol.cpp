#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 302;
ll dp[MAXN][MAXN], h[MAXN];
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%lld", &h[i]);
    n++;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= k; j++)
        {
            dp[i][j] = 1e16;
            for (int x = 0; x < i; x++) if (j - (i - x - 1) >= 0)
                dp[i][j] = min(dp[i][j], dp[x][j - (i - x - 1)] + max(0ll, h[i] - h[x]));
        }

    ll ans = 1e16;
    for (int i = 0; i <= k; i++) ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);
    return 0;
}