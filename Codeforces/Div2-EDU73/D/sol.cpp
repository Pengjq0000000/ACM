#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 3e5 + 7;
LL dp[maxn][3], a[maxn], b[maxn];
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%lld%lld", &a[i], &b[i]);
        for (int j = 0; j < 3; j++) dp[1][j] = b[1] * j;
        for (int i = 2; i <= n; i++)
        {
            dp[i][0] = dp[i][1] = dp[i][2] = 2e18;
            for (int j = 0; j < 3; j++)
                for (int k = 0; k < 3; k++)
                {
                    if (a[i] + j == a[i - 1] + k) continue;
                    dp[i][j] = min(dp[i][j], dp[i - 1][k] + b[i] * j);
                }
        }
        printf("%lld\n", min(dp[n][0], min(dp[n][1], dp[n][2])));
    }
    return 0;
}