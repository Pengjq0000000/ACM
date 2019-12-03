#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1007;
const int mod = 1e9 + 7;
inline int add(int x, int y){int res = x + y; if (res >= mod) res -= mod; return res;}
int dp[MAXN][MAXN];
char s[MAXN][MAXN];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf(" %s", s[i] + 1);
    dp[1][1] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            if (s[i][j] == '#') continue;
            if (s[i - 1][j] == '.') dp[i][j] = add(dp[i][j], dp[i - 1][j]);
            if (s[i][j - 1] == '.') dp[i][j] = add(dp[i][j], dp[i][j - 1]);
        }
    printf("%d\n", dp[n][m]);
    return 0;
}