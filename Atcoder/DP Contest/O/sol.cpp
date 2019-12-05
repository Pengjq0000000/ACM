#include<bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int lowbit(int x) {return x & -x;}
int a[21][21], dp[22][1 << 21];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
    dp[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int s = 0; s < (1 << n); s++)
        {
            int S = s ^ ((1 << n) - 1);
            for (int tmp = lowbit(S); S; S ^= tmp, tmp = lowbit(S))
            {
                int j = __builtin_ctz(tmp);
                if (a[i - 1][j]) dp[i][s | (1 << j)] = add(dp[i][s | (1 << j)], dp[i - 1][s]);
            }
        }
    printf("%d\n", dp[n][(1 << n) - 1]);
    return 0;
}