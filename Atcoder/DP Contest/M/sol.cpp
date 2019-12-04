#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
int dp[101][MAXN], sum[MAXN];
int main()
{
    int n, K; scanf("%d%d", &n, &K);
    dp[0][0] = 1; sum[0] = 1; for (int j = 1; j <= K; j++) sum[j] = add(sum[j - 1], dp[0][j]);
    for (int i = 1, a; i <= n; i++)
    {
        scanf("%d", &a);
        dp[i][0] = 1; for (int j = 1; j <= K; j++) dp[i][j] = add(sum[j], j - a - 1 < 0 ? 0 : mod - sum[j - a - 1]);
        sum[0] = 1; for (int j = 1; j <= K; j++) sum[j] = add(sum[j - 1], dp[i][j]);
    }
    printf("%d\n", dp[n][K]);
    return 0;
}