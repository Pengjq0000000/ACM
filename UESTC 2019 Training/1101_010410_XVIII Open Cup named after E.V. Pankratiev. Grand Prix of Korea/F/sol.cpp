#include<bits/stdc++.h>
#define ctz __builtin_ctz
#define ll long long
using namespace std;
const int N = 15;
const int M = (1 << 15);
ll w[N][N], dp[M][N], cnt[M];
inline int lowbit(int x) {return x & -x;}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 1; j < n - i; j++) 
        {
            scanf("%lld", &w[i][i + j]);
            w[i + j][i] = w[i][i + j];
        }
    for (int s = 0; s < M; s++)
        for (int i = 0; i < n; i++) 
            dp[s][i] = 1e16;
    for (int i = 0; i < n; i++) dp[1 << i][i] = 0;
    
    int all = (1 << n) - 1;
    for (int s = 0; s <= all; s++) cnt[s] = __builtin_popcount(s), cnt[s] *= (n - cnt[s]);
    for (int s = 0; s <= all; s++)
    {
        //for (int u = 0; u < n; u++) if (s >> u & 1)
        for (int tmp = s, u = ctz(s); tmp; tmp ^= lowbit(tmp), u = ctz(tmp))
        {
            //for (int v = 0; v < n; v++) if ((s >> v & 1) && u != v)
            //for (int tmp = s, v = ctz(s); tmp; tmp ^= lowbit(tmp), v = ctz(tmp)) if (u != v)
                 //dp[s][u] = min(dp[s][u], dp[s ^ (1 << u)][v] + w[u][v] * cnt[s ^ (1 << u)]);
            int U = s ^ (1 << u);
            for (int s1 = U; ; s1 = (s1 - 1) & U)
            {
                int s2 = s ^ s1;
                //for (int v = 0; v < n; v++) if (s1 >> v & 1) 
                for (int tmp = s1, v = ctz(s1); tmp; tmp ^= lowbit(tmp), v = ctz(tmp))
                    dp[s][u] = min(dp[s][u], dp[s1][v] + dp[s2][u] + w[u][v] * cnt[s1]);
                if (!s1) break;
            }
        }
    }
    ll ans = 1e18;
    for (int u = 0; u < n; u++) ans = min(ans, dp[all][u]);
    printf("%lld\n", ans);
    return 0;
}