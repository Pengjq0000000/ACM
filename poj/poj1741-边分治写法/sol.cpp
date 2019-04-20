#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<vector>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 7;
struct node
{
	int v, w, next, eid;
	node(int v, int w) : v(v), w(w) {}
	node(){}
}e[maxn];
vector<node>E[maxn];
int head[maxn], sz[maxn], mx[maxn], vis[maxn], done[maxn], fake[maxn];
int n, m, k, tot, cnt = 1, pid, eid;
LL ans = 0;
void add(int u, int v, int w)
{
	++cnt; fake[cnt] = done[cnt] = 0;
	e[cnt] = node(v, w);
	e[cnt].next = head[u]; head[u] = cnt;
}
void build(int u, int fa)
{
	int son = (int)E[u].size() - (fa > 0);
	done[u] = 1;
	if (son > 2)
	{
		add(u, n + 1, 0); add(n + 1, u, 0); fake[cnt] = fake[cnt ^ 1] = 1;
		add(u, n + 2, 0); add(n + 2, u, 0); fake[cnt] = fake[cnt ^ 1] = 1;
		int flag = 1;
		for (node edge : E[u])
		{
		    if (done[edge.v]) continue;
			E[n + flag].pb(node(edge.v, edge.w));
			flag ^= 3; // 1 -> 2, 2 -> 1
		}
		n += 2;
	}
	else
	{
		for (node edge : E[u])
		{
		    if (done[edge.v]) continue;
			add(u, edge.v, edge.w); add(edge.v, u, edge.w);
		}
	}
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (done[v]) continue;
		build(v, u);
	}
}
void getp(int u, int fa)
{
	sz[u] = 1; mx[u] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		if (vis[i]) continue;
		int v = e[i].v; if (v == fa) continue;
		getp(v, u);
		sz[u] += sz[v];
		if (mx[v] < mx[e[eid].v] || pid == 0)
		{
			pid = u; eid = i; // e[eid].u = pid  , cut edge eid
		}
	}
	mx[u] = max(sz[u], tot - sz[u]);
}
int num, disy[maxn], disx[maxn];
void getdis(int u, int fa, int dist, int flag)
{
	if (!flag) disy[++num] = dist;
	for (int i = head[u]; i; i = e[i].next)
	{
		if (vis[i]) continue;
		int v = e[i].v; if (v == fa) continue;
		getdis(v, u, dist + e[i].w, fake[i]);
	}
}
void cal(int x, int y, int len, int flag) 
{
	int numx, numy;
	num = 0; getdis(x, 0, 0, 1); numx = num;
	for (int i = 1; i <= num; i++) disx[i] = disy[i];
	num = 0; getdis(y, 0, 0, 1); numy = num;
	if (!flag) {disx[++numx] = 0; disy[++numy] = 0;}
	sort(disx + 1, disx + 1 + numx);
	sort(disy + 1, disy + 1 + numy);
	int pos = numy;
	for (int i = 1; i <= numx; i++)
	{
		while (disx[i] + disy[pos] + len > k && pos > 0) pos--;
		if (pos == 0) break;
		ans += pos;
	}
}
void dfs(int u)
{
    if (tot <= 1) return;
	eid = pid = 0; getp(u, 0); vis[eid] = vis[eid ^ 1] = 1;
	int x = pid, y = e[eid].v;
	cal(x, y, e[eid].w, fake[eid]);
	int newtot = sz[y];
	tot = tot - newtot; dfs(x);
	tot = newtot; dfs(y);

}
int main()
{
	while (scanf("%d%d", &n, &k) != EOF)
	{
		if (n == 0 && k == 0) break;
		m = n;
		cnt = 0; ans = 0;
		for (int i = 1; i < n; i++)
		{
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			E[u].pb(node(v, w)); E[v].pb(node(u, w));
		}
		build(1, -1);
		for (int i = 0; i <= n; i++) vis[i] = 0;
		tot = n; dfs(1);
		printf("%lld\n", ans);
		for (int i = 1; i <= n; i++) E[i].clear(), head[i] = 0;
	}
	
	return 0;
}





