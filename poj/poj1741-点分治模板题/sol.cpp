#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node {int v, w, next;}e[maxn * 2];
int head[maxn], n, k, tot, all;
int num, dis[maxn], rt;
LL ans = 0;
void add(int u, int v, int w)
{
	++tot;
	e[tot].v = v; e[tot].w = w;
	e[tot].next = head[u];
	head[u] = tot;
}
int sz[maxn], son[maxn], vis[maxn];
void getroot(int u, int fa)
{
	sz[u] = 1; son[u] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == fa || vis[v]) continue;
		getroot(v, u);
		sz[u] += sz[v];
		son[u] = max(son[u], sz[v]);
	}
	son[u] = max(son[u], all - sz[u]);
	if (son[rt] > son[u] || son[rt] == 0) rt = u;
}
void getdis(int u, int fa, int dist)
{
	dis[++num] = dist;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == fa || vis[v]) continue;
		getdis(v, u, dist + e[i].w);
	}
}
void cal(int u, int op, int len)
{
	num = 0; getdis(u, 0, len);
	sort(dis + 1, dis + 1 + num);
	int res = 0;
	int l = 1, r = num;
	while (l < r)
	{
		while (dis[l] + dis[r] > k && l < r) r--;
		res += r - l;
		l++;
	}
    ans += op * res;
}
void dfs(int u)
{
	rt = 0; getroot(u, 0); u = rt;
	vis[u] = 1;
	cal(u, 1, 0);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v]) continue;
		cal(v, -1, e[i].w);
		all = sz[v]; dfs(v);
	}
}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		if (n == 0 && k == 0) break;
		tot = 0; ans = 0;
		for (int i = 1; i <= n; i++) head[i] = vis[i] = 0;
		for (int i = 1; i < n; i++)
		{
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			add(u, v, w); add(v, u, w);
		}
		all = n;
		dfs(1);
		printf("%lld\n", ans);
	}
	return 0;
}

