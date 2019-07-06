#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn], deg[maxn], f[maxn];
vector<int>E[maxn], G[maxn];
void dfs(int u, int fa)
{
    for (int v : E[u])
    {
        if (v == fa) continue;
        G[u].pb(v);
        dfs(v, u);
    }
}
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        E[u].pb(v); E[v].pb(u);
        deg[u]++; deg[v]++;
    }
    if (n == 2) {puts("YES"); return 0;}
    if (n == 3) {puts("NO"); return 0;}
    int rt = 1; while (deg[rt] <= 1) rt++;
    dfs(rt, 0);
    int flag = 1;
    if (G[rt].size() <= 2) flag = 0;
    for (int u = 1; u <= n; u++)
    {
        if (deg[u] == 1) continue;
        if (G[u].size() < 2) flag = 0; 
    }
    if (flag) puts("YES"); else puts("NO");
	return 0;
}
