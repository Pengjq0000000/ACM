#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
int M;
inline int add(int x, int y) {int res = x + y; if (res >= M) res -= M; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / M * M; return res;}

vector<int>G[MAXN];
int f[MAXN], fs[MAXN], fp[MAXN], g[MAXN];
void dfs1(int u, int fa)
{
    int p = 1;
    for(int v : G[u]) if(v != fa) 
    {
        dfs1(v, u);
        fp[v] = p;
        p = mul(p, f[v] + 1);
    }
    f[u] = p;
    p = 1;
    for (auto it = G[u].rbegin(); it != G[u].rend(); it++) if (*it != fa)
        fs[*it] = p, p = mul(p, f[*it] + 1);
}
void dfs2(int u, int fa)
{
    for (int v : G[u]) if (v != fa)
    {
        g[v] = mul(g[u] + 1, mul(fs[v], fp[v]));
        dfs2(v, u);
    }
}
int main()
{
    int n; scanf("%d%d", &n, &M);
    for (int i = 1, x, y; i < n; i++) 
    {
        scanf("%d%d", &x, &y);
        G[x].push_back(y); G[y].push_back(x);
    }
    dfs1(1, 0); dfs2(1, 0);
    for (int i = 1; i <= n; i++) printf("%d\n", mul(f[i], g[i] + 1));
    return 0;
}