#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e4 + 7;
int dp[MAXN];
int main()
{
    int H, n; scanf("%d%d", &H, &n);
    for (int i = 1; i <= H + 10000; i++) dp[i] = 1e9;
    int ans = 1e9;
    for (int i = 1, a, b; i <= n; i++)
    {
        scanf("%d%d", &a, &b);
        for (int j = a; j <= H + 10000; j++) dp[j] = min(dp[j], dp[j - a] + b);
        for (int j = H; j <= H + 10000; j++) ans = min(ans, dp[j]);
    }
    printf("%d\n", ans);
    return 0;
}