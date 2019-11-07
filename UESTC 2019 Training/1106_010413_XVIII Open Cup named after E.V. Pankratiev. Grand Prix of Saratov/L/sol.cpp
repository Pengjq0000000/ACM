#include<bits/stdc++.h>
#define ll long long
#define pli pair<long long, int>
#define fir first
#define sec second
using namespace std;
const int N = 4e5 + 7;
const int M = 20;
const ll INF = 1e16;
int n, m;
struct node{int u, v, w, next;}e[N << 1];
int head[N], tot = 1;
void add(int u, int v, int w) 
{
    e[++tot] = {u, v, w, head[u]};
    head[u] = tot;
}
vector<int>G[N], rG[N], DT[N];
int in[N], f[N][M], dep[N];
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) 
        if (dep[x] < dep[y] && dep[x] <= dep[f[y][i]]) y = f[y][i];
    for (int i = 19; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0];
}
void Dominator()
{
    queue<int>q;
    for (int u = 1; u <= n; u++) if (!in[u]) q.push(u);
    int uf;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        uf = 0;
        for (int v : rG[u])
            uf = (uf == 0 ? v : LCA(uf, v));
        DT[uf].push_back(u); 
        dep[u] = dep[uf] + 1; f[u][0] = uf;
        // printf("u = %d uf = %d dep = %d\n", u, uf, dep[u]);
        for (int i = 1; i <= 19; i++)
            f[u][i] = f[f[u][i - 1]][i - 1];
        for (int v : G[u]) 
            if ((--in[v]) == 0) q.push(v);
    }
}
int sz[N];
void dfs(int u)
{
    sz[u] = (u <= n);
    for (int v : DT[u]) {dfs(v); sz[u] += sz[v];}
}
ll dis[N]; bool vis[N];
priority_queue<pli, vector<pli>, greater<pli> >pq;
void dijkstra(int s)
{
    for (int i = 1; i <= n; i++) dis[i] = INF;
    pq.push({dis[s] = 0, s});
    while (!pq.empty())
    {
        int u = pq.top().sec; pq.pop();
        if (vis[u]) continue; 
        vis[u] = 1;
        for (int i = head[u], v; i; i = e[i].next)
        {
            v = e[i].v;
            if (dis[v] > dis[u] + e[i].w)
                pq.push({dis[v] = dis[u] + e[i].w, v});
        }
    }
    for (int i = 2, eid; i <= tot; i++)
        if (dis[e[i].v] == dis[e[i].u] + e[i].w)
        {
            eid = i / 2 + n;
            G[e[i].u].push_back(eid); rG[eid].push_back(e[i].u); in[eid]++;
            G[eid].push_back(e[i].v); rG[e[i].v].push_back(eid); in[e[i].v]++;
        }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    dijkstra(1);
    Dominator();
    dfs(1);
    for (int i = 1; i <= m; i++)
        printf("%d\n", sz[i + n]);
    return 0;
}