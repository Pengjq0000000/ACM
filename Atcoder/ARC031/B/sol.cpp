#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
int dp[MAXN], a[MAXN], b[MAXN], lst[MAXN], pos[MAXN];
int main()
{
    int n; scanf("%d", &n);
    int tot = 0;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]);
        if (a[i] != a[i - 1]) b[++tot] = a[i];
    }
    for (int i = 1; i <= tot; i++)
    {
        lst[i] = pos[b[i]];
        pos[b[i]] = i;
    }
    dp[0] = 1;
    for (int i = 1; i <= tot; i++)
    {
        dp[i] = dp[i - 1];
        if (lst[i]) dp[i] = add(dp[i], dp[lst[i]]);
    }
    printf("%d\n", dp[tot]);
    return 0;
}//