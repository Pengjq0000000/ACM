#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 3007;
ll dp[MAXN][MAXN], a[MAXN];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), dp[i][1] = a[i];
    for (int j = 2; j <= n; j++)
        for (int i = 1; i + j - 1 <= n; i++)
            dp[i][j] = max(-dp[i + 1][j - 1] + a[i], -dp[i][j - 1] + a[i + j - 1]);
    printf("%lld\n", dp[1][n]);
    return 0;
}