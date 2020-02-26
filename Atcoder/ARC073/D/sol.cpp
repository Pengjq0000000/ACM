#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 107;
int dp[MAXN][MAXN * 3], w[MAXN], v[MAXN];
int main()
{
    int n, W; scanf("%d%d", &n, &W); 
    for (int i = 1; i <= n; i++) scanf("%d%d", &w[i], &v[i]);
    int ww = w[1];
    for (int i = 1; i <= n; i++) w[i] -= ww;
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j >= 1; j--)
            for (int r = 3 * i; r >= w[i]; r--)
            {
                dp[j][r] = max(dp[j][r], dp[j - 1][r - w[i]] + v[i]);
                if ((ll)j * ww + r <= W) ans = max(ans, dp[j][r]);
            }
    }
    printf("%d\n", ans);
    return 0;
}