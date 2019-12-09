#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod = 1e9 + 7;
const int MAXN = 10007;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int dp[MAXN][100];
char s[MAXN];
inline void upd(int &x, int y) {x = add(x, y);}
int main()
{
    scanf(" %s", s + 1); int n = strlen(s + 1);
    int D; scanf("%d", &D);
    dp[0][0] = 1;
    for (int i = 0; i < n; i++) 
        for (int d = 0; d < 10; d++)
            for (int j = 0; j < D; j++)
                upd(dp[i + 1][(j + d) % D], dp[i][j]);

    int ans = 0, r = 0;
    for (int i = 1; i <= n; i++)
    {
        int d = s[i] - '0';
        for (int j = 0; j < d; j++) upd(ans, dp[n - i][(D - (j + r) % D + D) % D]);
        r = (r + d) % D;
    }
    if (!r) upd(ans, 1);
    printf("%d\n", add(ans, mod - 1));
    return 0;
}