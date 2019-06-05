#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int sz[maxn], son[maxn], head[maxn], vis[maxn];
int ans[maxn], q[maxn];
int n, m, maxk; 
struct node{int v, w, next;}e[maxn << 1];
int cnt = 0;
void add(int u, int v, int w)
{
	e[++cnt] = {v, w, head[u]};
	head[u] = cnt;
}
int all, rt;
void getroot(int u, int fa)
{
	sz[u] = 1, son[u] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == fa || vis[v]) continue;
		getroot(v, u);
		sz[u] += sz[v];
		son[u] = max(son[u], sz[v]);
	}
	son[u] = max(son[u], all - sz[u]);
	if (!son[rt] || son[rt] > son[u]) rt = u;
}
int num[maxn * 100];
vector<int>vv;
void dfs(int u, int fa, int dis)
{
	if (dis <= maxk) {num[dis]++; vv.pb(dis);}
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v] || v == fa) continue;
		dfs(v, u, dis + e[i].w);
	}
}
void cal(int u, int det, int dis)
{
	dfs(u, 0, dis);
	for (int i = 1; i <= m; i++)
	{
		for (int dis : vv) 
		{
			if (q[i] < dis) continue;
			if (dis != q[i] - dis && num[q[i] - dis]) ans[i] += det * num[q[i] - dis];
			if (dis == q[i] - dis && num[q[i] - dis] > 1) ans[i] += det * (num[q[i] - dis] - 1);
		}
	}
	for (int dis : vv) num[dis]--;
	vv.clear();
}

void DIV(int u)
{
	rt = 0; getroot(u, 0); u = rt;
	vis[u] = 1; cal(u, 1, 0);
	int totsz = all;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v]) continue;
		cal(v, -1, e[i].w);
		all = sz[v] < sz[u] ? sz[v] : totsz - sz[u];
		DIV(v);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1, u, v, w; i < n; i++) 
	{
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	maxk = 0;
	for (int i = 1; i <= m; i++) scanf("%d", &q[i]), maxk = max(maxk, q[i]);
	all = n; DIV(1);
	for (int i = 1; i <= m; i++)
		//printf("%d\n", ans[i]);
		if (ans[i]) puts("AYE"); else puts("NAY");
	return 0;
}
