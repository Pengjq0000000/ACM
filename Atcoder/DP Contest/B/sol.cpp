#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
int dp[MAXN], h[MAXN];
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &h[i]);
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[1] = 0;
    for (int i = 2; i <= n; i++) 
        for (int j = 1; j <= k; j++)
            if (i - j >= 1) dp[i] = min(dp[i], dp[i - j] + abs(h[i] - h[i - j]));
    printf("%d\n", dp[n]);
    return 0;
}