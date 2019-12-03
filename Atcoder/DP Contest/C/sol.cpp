#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int dp[MAXN][3];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, c[3]; i <= n; i++)
    {
        for (int j = 0; j <= 2; j++) 
        {
            scanf("%d", &c[j]);
            for (int k = 0; k <= 2; k++) if (j != k)
                dp[i][j] = max(dp[i][j], dp[i - 1][k] + c[j]);
        }
    }
    printf("%d\n", max(dp[n][0], max(dp[n][1], dp[n][2])));
    return 0;
}