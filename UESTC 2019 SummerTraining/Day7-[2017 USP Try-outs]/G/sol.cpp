#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e4 + 7;
vector<int>E[maxn];
int dep[maxn], tot = 0, ans = 0;
void dfs(int u, int fa)
{
    dep[u] = dep[fa] + 1;
    for (int v : E[u])
    {
        if (v == fa) continue;
        if (!dep[v]) dfs(v, u);
        else ans = max(ans, dep[v] - dep[u] + 1);
    }
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        E[u].pb(v); E[v].pb(u);
    }
    dfs(1, 0);
    printf("%d\n", ans ? ans : (n > 1 ? 2 : 1));
	return 0;
}
