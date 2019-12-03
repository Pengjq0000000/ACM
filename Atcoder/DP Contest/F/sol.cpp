#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3007;
int dp[MAXN][MAXN];
char s[MAXN], t[MAXN];
int main()
{
    scanf(" %s", s + 1); scanf(" %s", t + 1);
    int n = strlen(s + 1), m = strlen(t + 1);
    for (int i = 1; i <= n / 2; i++) swap(s[i], s[n + 1 - i]);
    for (int j = 1; j <= m / 2; j++) swap(t[j], t[m + 1 - j]);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            dp[i][j] = s[i] == t[j] ? dp[i - 1][j - 1] + 1 : max(dp[i][j - 1], dp[i - 1][j]);
    }
    int i = n, j = m;
    while (i && j)
    {
        if (s[i] == t[j]) putchar(t[j]), i--, j--;
        else dp[i - 1][j] > dp[i][j - 1] ? i-- : j--;
    }
    puts("");
    return 0;
}