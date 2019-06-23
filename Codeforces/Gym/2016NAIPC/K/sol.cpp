#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
struct node{int v, next;LL w;}e[maxn << 1];
int n, head[maxn];
int tot = 1;
void add(int u, int v, LL w)
{
	e[++tot] = {v, head[u], w};
	head[u] = tot;
}
LL a[maxn], ans[maxn];
int all, rt;
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
	if (!son[rt] || son[rt] > son[u])  rt = u;
}
int cnt = 0;
struct Node
{
	LL d, a;
	bool operator < (const Node &rhs) const
	{
		if (a == rhs.a) return d < rhs.d;
		return a > rhs.a;
	}
}p[maxn];
LL x[maxn], d[maxn];
bool cmp(LL x, LL y) {return a[x] < a[y];}
void getdis(int u, int fa, LL dis)
{
	p[++cnt] = {dis, a[u]};
	x[cnt] = u;
	d[u] = dis;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v] || v == fa) continue;
		getdis(v, u, dis + e[i].w);
	}
}

bool check(int x, int y, int z)
{
	return (p[y].d - p[x].d) * (p[y]. a - p[z].a) > (p[z].d - p[y].d) * (p[x].a - p[y].a);
}

int q[maxn];
LL cal(int x, int pos)
{
	int j = q[pos];
	return p[j].a * a[x] + p[j].d + d[x];
}
void DIV(int u)
{
	rt = 0; getroot(u, 0); u = rt;
	vis[u] = 1;
	cnt = 0; getdis(u, 0, 0);
	sort(p + 1, p + 1 + cnt);
	sort(x + 1, x + 1 + cnt, cmp);
	int t = 0, pos = 1;
	q[++t] = 1;
	for (int i = 2; i <= cnt; i++)
	{
		if (p[i].a == p[i - 1].a) continue;
		while (t > 1 && check(q[t - 1], q[t], i)) t--;
		q[++t] = i;
	}
	for (int i = 1; i <= cnt; i++)
	{
		while (pos < t && cal(x[i], pos) > cal(x[i], pos + 1)) pos++;
		ans[x[i]] = min(ans[x[i]], cal(x[i], pos));
	}
	int totsz = all;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v]) continue;
		all = sz[v] < sz[u] ? sz[v] : all - sz[u];
		DIV(v);
	}
}

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	MEM(ans, 127);
	all = n; DIV(1);
	LL sum = 0;
	for (int i = 1; i <= n; i++) sum += ans[i];
	printf("%lld\n", sum);
	return 0;
}
