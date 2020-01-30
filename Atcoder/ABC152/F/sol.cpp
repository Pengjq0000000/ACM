#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 51;
int n, m, LCA[MAXN][MAXN];
ll mi[MAXN];
vector<int>G[MAXN], son[MAXN];
pii path[MAXN];
int tag[MAXN], cnt = 0;
void dfs(int u, int fa)
{
    for (int v : G[u]) if (v != fa) dfs(v, u), tag[u] += tag[v];
    if (tag[u] > 0) cnt++;
}
ll deal(int sta)
{
    for (int i = 1; i <= n; i++) tag[i] = 0;
    for (int i = 0; i < m; i++) if ((sta >> i) & 1)
    {
        int u = path[i].fir, v = path[i].sec;
        tag[u]++; tag[v]++; tag[LCA[u][v]] -= 2;
    }
    cnt = 0; dfs(1, 0);
    int sig = 1;
    if (__builtin_popcount(sta) & 1) sig = -1;
    return mi[n - 1 - cnt] * sig;
}
void DFS(int u, int fa)
{
    son[u].push_back(u);
    for (int v : G[u]) if (v != fa) 
    {
        DFS(v, u);
        for (int sonv : son[v]) son[u].push_back(sonv);
    }
    for (int sonu : son[u]) LCA[u][sonu] = LCA[sonu][u] = u;
    for (int x : G[u]) if (x != fa)
        for (int y : G[u]) if (y != fa && x != y)
            for (int sonx : son[x])
                for (int sony : son[y])
                    LCA[sonx][sony] = u;
}
int main()
{
    mi[0] = 1; for (int i = 1; i <= 50; i++) mi[i] = mi[i - 1] * 2;
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) 
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v); G[v].push_back(u);
    }
    DFS(1, 0);
    scanf("%d", &m);
    for (int i = 0; i < m; i++) scanf("%d%d", &path[i].fir, &path[i].sec);
    ll ans = 0;
    for (int sta = 0; sta < (1 << m); sta++) ans += deal(sta);
    printf("%lld\n", ans);
    return 0;
}