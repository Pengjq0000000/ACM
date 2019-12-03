#include<bits/stdc++.h>
#define ldb long double
const int MAXN = 307;
ldb dp[MAXN][MAXN][MAXN];
int cnt[4], n;
int main()
{
    scanf("%d", &n);
    for (int i = 1, a; i <= n; i++) scanf("%d", &a), cnt[a]++;
    dp[0][0][0] = 0;
    for (int k = 0; k <= cnt[3]; k++)
        for (int j = 0; j <= cnt[2] + cnt[3]; j++)
            for (int i = 0; i <= cnt[1] + cnt[2] + cnt[3]; i++)
            {
                if (!i && !j && !k) continue;
                dp[i][j][k] = (ldb)(n - i - j - k) / (i + j + k);
                if (i) dp[i][j][k] += (ldb)i / (i + j + k) * (dp[i - 1][j][k] + 1);
                if (j) dp[i][j][k] += (ldb)j / (i + j + k) * (dp[i + 1][j - 1][k] + 1); 
                if (k) dp[i][j][k] += (ldb)k / (i + j + k) * (dp[i][j + 1][k - 1] + 1);
            }
    printf("%.15lf\n", (double)dp[cnt[1]][cnt[2]][cnt[3]]);
    return 0;
}