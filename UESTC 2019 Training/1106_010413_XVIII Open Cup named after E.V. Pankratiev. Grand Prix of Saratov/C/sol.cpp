#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 1e5 + 7;
const int M = 18;
vector<int>G[N], keyp[N], endp[N];
set<int>s[N];
pii path[N];
int f[N][M], dep[N], id[N];
void dfs(int u)
{
    for (int v : G[u]) 
    {
        if (v == f[u][0]) continue;
        f[v][0] = u; dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int getLCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 17; i >= 0; i--)
        if (dep[x] < dep[y] && dep[x] <= dep[f[y][i]]) y = f[y][i];
    for (int i = 17; i >= 0; i--)
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0];
}

void merge(int u, int v)
{
    if (s[id[u]].size() < s[id[v]].size()) swap(id[u], id[v]);
    for (int p : s[id[v]]) s[id[u]].insert(p);
}
int vis[N], ans[N], tot;
void DFS(int u)
{
    for (int v : G[u])
    {
        if (v == f[u][0]) continue;
        DFS(v);
        merge(u, v);
    }
    for (int p : endp[u]) s[id[u]].insert(p);
    for (int p : keyp[u]) 
    {
        if (vis[p]) continue;
        vis[p] = 1; ans[++tot] = u;
        for (int x : s[id[u]]) vis[x] = 1;
        s[id[u]].clear();
    }
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
        id[i] = i;
    } 
    dep[1] = 1; dfs(1);
    for (int j = 1; j < 18; j++)
        for (int i = 1; i <= n; i++)
            f[i][j] = f[f[i][j - 1]][j - 1];
    

    int m; scanf("%d", &m);
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        // printf("%d\n", getLCA(u, v));
        keyp[getLCA(u, v)].push_back(i);
        endp[u].push_back(i); endp[v].push_back(i);
    }
    tot = 0;
    DFS(1);
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) printf("%d%c", ans[i], i == tot ? '\n' : ' ');
    return 0;
}