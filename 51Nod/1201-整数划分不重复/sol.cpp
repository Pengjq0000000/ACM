#include<bits/stdc++.h>
#define mod 1000000007
using namespace std;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;} 
const int N = 50000;
const int M = 350;
int dp[N][M];
int main()
{
    int n; scanf("%d", &n);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j * (j + 1) / 2 <= n; j++)
        {
            if (i >= j) dp[i][j] = add(dp[i - j][j - 1], dp[i - j][j]);
        }
    int ans = 0;
    for (int j = 1; j * (j + 1) / 2 <= n; j++) ans = add(ans, dp[n][j]);
    printf("%d\n", ans);
    return 0;
}