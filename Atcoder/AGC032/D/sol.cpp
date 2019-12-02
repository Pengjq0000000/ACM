#include<bits/stdc++.h>
#define ll long long
using namespace std;
const ll INF = 1e18;
const int MAXN = 5007;
ll dp[MAXN][MAXN];
int a[MAXN], p[MAXN];
int main()
{
    int n; ll A, B; scanf("%d%lld%lld", &n, &A, &B);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), p[a[i]] = i;
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            dp[i][j] = INF;
    dp[0][0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll MIN = INF;
        for (int j = 0; j <= n; j++) 
        {
            MIN = min(MIN, dp[i - 1][j]);
            if (j == p[i]) dp[i][p[i]] = min(dp[i][p[i]], MIN);
            else if (j < p[i]) dp[i][j] = min(dp[i][j], MIN + B);
            else dp[i][j] = min(dp[i][j], MIN + A);
        }
    }
    // for (int i = 0; i <= n; i++)
    //     for (int j = 0; j <= n; j++) printf("%lld%c", dp[i][j], " \n"[j == n]);
    ll ans = INF;
    for (int i = 0; i <= n; i++) ans = min(ans, dp[n][i]);
    printf("%lld\n", ans);
    return 0;
}