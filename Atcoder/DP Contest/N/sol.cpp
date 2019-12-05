#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 401;
const ll INF = 1e18;
ll dp[MAXN][MAXN], a[MAXN], sum[MAXN];
int main()
{
    int n; scanf("%d", &n); 
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = INF;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i], dp[i][i] = 0;
    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            for (int k = i; k + 1 <= j; k++) dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + sum[j] - sum[i - 1]);
        }
    printf("%lld\n", dp[1][n]);
    return 0;
}