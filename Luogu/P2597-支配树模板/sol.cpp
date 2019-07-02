#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 7e4;
int n, deg[maxn], a[maxn], f[maxn][17], dep[maxn]; 
vector<int>E[maxn], G[maxn], Tr[maxn];
queue<int>q;
void BFS()
{
    for (int i = 1; i <= n; i++) if (!deg[i]) {E[n + 1].pb(i); G[i].pb(n + 1); q.push(i);}
    int tot = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        a[++tot] = u; 
        for (int v : E[u]) if ((--deg[v]) == 0) q.push(v);
    } 
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 16; i >= 0; --i) 
    {
        if (dep[x] < dep[y] && dep[x] <= dep[f[y][i]]) y = f[y][i];
    } 
    for (int i = 16; i >= 0; --i)
    {
        if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    }
    return x == y ? x : f[x][0];
}
int sz[maxn];
void dfs(int u)
{
    sz[u] = 1;
    for (int v : Tr[u]) if (v != f[u][0]) {dfs(v); sz[u] += sz[v];}
}
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        int x; 
        while (1) 
        {
            scanf("%d", &x); if (x == 0) break;
            E[x].pb(i); G[i].pb(x); deg[i]++;
        }
    }
    BFS();
    dep[n + 1] = 1;
    for (int i = 1; i <= n; i++)
    {
        int u = a[i], fa = -1;
        for (int v : G[u]) fa = (fa == -1 ? v : LCA(fa, v));
        dep[u] = dep[fa] + 1; f[u][0] = fa;
        for (int i = 1; i <= 16; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        Tr[fa].pb(u);
        //printf("%d->%d\n", fa, u);
    }
    dfs(n + 1);
    for (int i = 1; i <= n; i++) printf("%d\n", sz[i] - 1);
	return 0;
}
