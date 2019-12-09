#include<bits/stdc++.h>
using namespace std;
const int MAXN = 81;
bool dp[MAXN][MAXN][MAXN * MAXN * 2];
int a[MAXN][MAXN], b[MAXN][MAXN];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            scanf("%d", &a[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++) 
            scanf("%d", &b[i][j]);
    dp[0][1][6400] = dp[1][0][6400] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            int d = a[i][j] - b[i][j];
            for (int k = 0; k <= 80 * 160; k++)
            {
                bool f = dp[i - 1][j][k] | dp[i][j - 1][k];
                if (k + d >= 0) dp[i][j][k + d] |= f;
                if (k - d >= 0) dp[i][j][k - d] |= f;
            }
        }
    int ans = 1e9;
    for (int k = 0; k <= 80 * 160; k++) if (dp[n][m][k])
        ans = min(ans, abs(k - 6400));
    printf("%d\n", ans);
    return 0;
}