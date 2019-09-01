#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
double dp[maxn][2];
vector<int>E[maxn], G[maxn];
int n, m, deg[maxn], out[maxn], a[maxn];
queue<int>q;
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) deg[i] = out[i] = 0, E[i].clear(), G[i].clear();
        for (int i = 1, u, v; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            E[u].pb(v); G[v].pb(u);
            deg[u]++; out[u]++;
        }
        q.push(n);
        for (int i = 1; i <= n; i++) dp[i][0] = dp[i][1] = 0;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            
            for (int v : E[u])
            {
                dp[u][0] += 1.0 / ((double)out[u]) * (dp[v][0]);
                dp[u][1] += 1.0 / ((double)out[u]) * (dp[v][0] + dp[v][1] + 1);
            }
            if (u != n) 
            {
                dp[u][0] += 1.0 / out[u] + 1;
                dp[u][1] += ((double)dp[u][0] + 1) / out[u];
            }
            for (int v : G[u])
                if (!(--deg[v])) q.push(v);
        }
        printf("%.2lf\n", dp[1][1]);
    }
	return 0;
}
