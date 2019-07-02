#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
vector<int>E[maxn];
int n, sz[maxn];
LL res = 0, ans = 0;
void dfs(int u, int fa)
{
	sz[u] = 1;
	for (int v : E[u])
	{
		if (v == fa) continue;
		dfs(v, u);
		sz[u] += sz[v];
	}
	res += sz[u];
}
void DFS(int u, int fa)
{
	for (int v : E[u])
	{
		if (v == fa) continue;
		int tmp1 = sz[u], tmp2 = sz[v];
		sz[u] = n - sz[v]; sz[v] = n;
		res = res - tmp1 - tmp2 + sz[u] + sz[v];
		ans = max(ans, res);
		DFS(v, u);
		res = res - sz[u] - sz[v] + tmp1 + tmp2;
		sz[u] = tmp1; sz[v] = tmp2; 
	}
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i < n; i++) 
	{
		int u, v; scanf("%d%d", &u, &v);
		E[u].pb(v); E[v].pb(u);
	}
	dfs(1, 0);
	DFS(1, 0);
	printf("%lld\n", ans);
	return 0;
}
