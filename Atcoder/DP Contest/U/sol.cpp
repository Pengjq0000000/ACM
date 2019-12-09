#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 16;
const int MAXM = (1 << MAXN);
ll dp[MAXM], c[MAXM], a[MAXN][MAXN];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%lld", &a[i][j]);
    for (int s = 0; s < (1 << n); s++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < i; j++) if (((s >> i) & 1) && ((s >> j) & 1))
                c[s] += a[i][j];
    for (int s = 0; s < (1 << n); s++) dp[s] = -1e18;
    dp[0] = 0;
    for (int U = 1; U < (1 << n); U++)
        for (int s = U; s; s = (s - 1) & U)
            dp[U] = max(dp[U], dp[U ^ s] + c[s]);
    printf("%lld\n", dp[(1 << n) - 1]);
    return 0;
}