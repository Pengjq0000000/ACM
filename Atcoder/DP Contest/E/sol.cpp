#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
const ll INF = 1e18;
ll dp[MAXN];
int main()
{
    int n, W; scanf("%d%d", &n, &W);
    for (int i = 1; i <= 100000; i++) dp[i] = INF;
    int ans = 0;
    for (int i = 1, w, v; i <= n; i++)
    {
        scanf("%d%d", &w, &v);
        for (int j = 100000; j >= v; --j) 
        {
            dp[j] = min(dp[j], dp[j - v] + w);
            if (dp[j] <= W) ans = max(ans, j);
        }
    }
    printf("%d\n", ans);
    return 0;
}