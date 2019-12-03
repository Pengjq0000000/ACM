#include<bits/stdc++.h>
#define ldb long double
const int MAXN = 3007;
ldb dp[MAXN][MAXN];
int main()
{
    int n; scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        double p; scanf("%lf", &p);
        for (int j = 0; j < i; j++)
        {
            dp[i][j + 1] += dp[i - 1][j] * p;
            dp[i][j] += dp[i - 1][j] * (1.0 - p);
        }
    }
    ldb ans = 0;
    for (int i = (n + 1) / 2; i <= n; i++) ans += dp[n][i];
    printf("%.15lf\n", (double)ans);
    return 0;
}