#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
map<LL, LL>num;
int sz[maxn], f[maxn];
struct node{int v, next; LL w;}e[maxn << 1];
int cnt = 0, head[maxn];
void add(int u, int v, LL w) {++cnt; e[cnt] = {v, head[u], w}; head[u] = cnt;}

void dfs(int u)
{
	sz[u] = 1;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v; if (v == f[u]) continue;
		dfs(v);
		sz[u] += sz[v];
	}
}
LL ans = 0;
void DFS1(int u, LL dis)
{
	ans = MOD(ans + MOD(num[dis] * sz[u]));
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v; if (v == f[u]) continue;
		DFS1(v, dis ^ e[i].w);
	}
	num[dis] = MOD(num[dis] + sz[u]);
}
LL tmp = 0;
void DFS2(int u, LL dis)
{
	ans = MOD(ans + MOD(num[dis] * sz[u]));
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v; if (v == f[u]) continue;
		LL det = sz[u] - sz[v];
		tmp = MOD(tmp + det);
		num[dis] = MOD(num[dis] + tmp);
		DFS2(v, dis ^ e[i].w);
		num[dis] = MOD(num[dis] - tmp + mod);
		tmp = MOD(tmp - det + mod);
	}
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 2; i <= n; i++)
	{
		LL w; scanf("%d%lld", &f[i], &w);
		add(i, f[i], w); add(f[i], i, w);
	}
	dfs(1);
	DFS1(1, 0);
	num.clear();
	DFS2(1, 0);
	printf("%lld\n", ans);
	return 0;
}
