#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline void upd(int &x, int y) {x = add(x, y);}
char s[3007];
int pre[3007][3007], suf[3007][3007], dp[3007][3007];
int main()
{
    int n; scanf("%d", &n);
    scanf(" %s", s + 2);
    dp[1][1] = pre[1][1] = suf[1][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        for (int j = 1; j <= i; j++)
            if (s[i] == '>') upd(dp[i][j], pre[i - 1][j - 1]);
            else upd(dp[i][j], suf[i - 1][j]);
        for (int j = 1; j <= i; j++) pre[i][j] = add(pre[i][j - 1], dp[i][j]);
        for (int j = i; j; j--) suf[i][j] = add(suf[i][j + 1], dp[i][j]);
    }
    printf("%d\n", pre[n][n]);
    return 0;
}