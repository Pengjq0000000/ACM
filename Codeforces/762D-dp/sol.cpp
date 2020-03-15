#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
const ll INF = 1e16;
ll dp[3][MAXN], g[3], a[3][MAXN];
void upd(ll &x, ll y) {x = max(x, y);}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++) scanf("%lld", &a[i][j]), dp[i][j] = -INF;
    dp[0][1] = a[0][1];
    dp[1][1] = a[0][1] + a[1][1];
    dp[2][1] = a[0][1] + a[1][1] + a[2][1];
    for (int j = 0; j < 3; j++) g[j] = 0 + a[j][1];
    for (int i = 2; i <= n; i++)
    {
        upd(dp[0][i], dp[0][i - 1] + a[0][i]);
        upd(dp[0][i], dp[1][i - 1] + a[1][i] + a[0][i]);
        upd(dp[0][i], dp[2][i - 1] + a[2][i] + a[1][i] + a[0][i]);
        upd(dp[0][i], g[2] + a[2][i] + a[1][i] + a[0][i] + a[1][i - 1] + a[0][i - 1]);
        
        upd(dp[1][i], dp[0][i - 1] + a[0][i] + a[1][i]);
        upd(dp[1][i], dp[1][i - 1] + a[1][i]);
        upd(dp[1][i], dp[2][i - 1] + a[2][i] + a[1][i]);

        upd(dp[2][i], dp[0][i - 1] + a[0][i] + a[1][i] + a[2][i]);
        upd(dp[2][i], g[0] + a[0][i] + a[1][i] + a[2][i] + a[1][i - 1] + a[2][i - 1]);
        upd(dp[2][i], dp[1][i - 1] + a[1][i] + a[2][i]);
        upd(dp[2][i], dp[2][i - 1] + a[2][i]);

        for (int j = 0; j < 3; j++) g[j] = dp[j][i - 1] + a[j][i];
        // printf("%lld %lld %lld\n", dp[0][i], dp[1][i], dp[2][i]);
    }
    printf("%lld\n", dp[2][n]);
    return 0;   
}