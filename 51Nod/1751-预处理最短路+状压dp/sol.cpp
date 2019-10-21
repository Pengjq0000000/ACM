#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
const int maxn = 15;
int dist[maxn][maxn], d[maxn], dp[1 << maxn];
bool used[maxn];
int f[maxn], sz[maxn], tot, cnt;
int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}
void unite(int x, int y)
{
    if (!used[x]) tot++, used[x] = 1;
    if (!used[y]) tot++, used[y] = 1;
    x = fa(x); y = fa(y);
    if (x != y) f[y] = x, sz[x] += sz[y];
    cnt = max(cnt, sz[x]); 
}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    memset(dist, inf, sizeof(dist));
    for (int i = 0; i < n; i++) f[i] = i, sz[i] = 1;
    int ans = 0;
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        ans += w;
        u--; v--; 
        dist[u][v] = min(dist[u][v], w);
        dist[v][u] = min(dist[v][u], w);
        d[u]++; d[v]++;
        unite(u, v);
    }

    if (m == 0) {puts("0"); return 0;}
    if (cnt != tot || sz[fa(0)] != tot) {puts("-1"); return 0;}

    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
    
    memset(dp, inf, sizeof(dp)); 
    dp[0] = 0;
    int bits = (1 << n);
    for (int sta = 0; sta < bits; sta++)
    {
        for (int u = 0; u < n; u++)
            for (int v = 0; v <= u; v++)
            {
                if (dist[u][v] == inf) continue;
                int to = (sta ^ (1 << u) ^ (1 << v));
                dp[to] = min(dp[to], dp[sta] + dist[u][v]);
            }
    }
    int aim = 0;
    for (int i = n - 1; i >= 0; i--) aim = aim * 2 + (d[i] & 1);
    if (dp[aim] == inf) puts("-1");
    else printf("%d\n", ans + dp[aim]);
    return 0;
}