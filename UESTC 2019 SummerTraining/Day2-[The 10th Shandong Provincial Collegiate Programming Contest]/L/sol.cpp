#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 107;
int vis[maxn], deg_e[maxn], deg_g[maxn], deg[maxn];
vector<int>E[maxn], G[maxn];
queue<int>q;
int n, m;
int bfs()
{
    int cnt = 0;
    for (int i = 1; i <= n; i++) deg[i] = deg_e[i];
    for (int i = 1; i <= n; i++) if (deg[i] == 0) q.push(i);
    while (!q.empty())
    {
        int u = q.front(); q.pop(); cnt++;
        int sz = E[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = E[u][i];
            deg[v]--; if (deg[v] == 0) q.push(v);
        }
    }
    return cnt;
}
int bfss(int u)
{
    for (int i = 1; i <= n; i++) vis[i] = 0;
    while (!q.empty()) q.pop();
    q.push(u); vis[u] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); cnt++;
        int sz = E[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = E[u][i];
            if (vis[v]) continue;
            q.push(v); vis[v] = 1;
        }
    }
    return cnt;
}
int BFS(int u)
{
    for (int i = 1; i <= n; i++) vis[i] = 0;
    while (!q.empty()) q.pop();
    q.push(u); vis[u] = 1;
    int cnt = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); cnt++;
        int sz = G[u].size();
        for (int i = 0; i < sz; i++)
        {
            int v = G[u][i];
            if (vis[v]) continue;
            q.push(v); vis[v] = 1;
        }
    }
    return cnt;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) {E[i].clear(); G[i].clear();deg_e[i] = deg_g[i] = 0;}
        for (int i = 1; i <= m; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
            E[u].pb(v); G[v].pb(u);
            deg_e[v]++; deg_g[u]++;
        }
        if (bfs() != n)
        {
            for (int i = 1; i <= n; i++) printf("0");
            puts("");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            int x = bfss(i);
            int y = BFS(i);
            //printf("%d,%d\n", x, y);
            if (x <= n / 2 + 1 && y <= n / 2 + 1) printf("1");
            else printf("0");
        }
        puts("");
    }
	return 0;
}
