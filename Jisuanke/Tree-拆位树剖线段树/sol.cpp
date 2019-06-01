//补 西安邀请赛
//为什么赛场上就过不了？我好蔡啊
#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
const int M = 32;
struct node{int v, next;}e[maxn << 1];
int tot = 1, head[maxn];
void add(int u, int v)
{
	++tot; e[tot] = {v, head[u]};
	head[u] = tot;
}
int n, q, a[maxn];

int son[maxn], sz[maxn], father[maxn], dep[maxn], id[maxn], rnk[maxn], top[maxn];
void dfs1(int u, int fa, int depth)
{
	son[u] = 0; sz[u] = 1;
	father[u] = fa;
	dep[u] = depth;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == father[u]) continue;
		dfs1(v, u, depth + 1);
		sz[u] += sz[v];
		if (son[u] == 0 || sz[son[u]] < sz[v]) son[u] = v;
	}
}
int cnt = 0;
void dfs2(int u, int tp)
{
	++cnt; id[u] = cnt; rnk[cnt] = u;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == son[u] || v == father[u]) continue;
		dfs2(v, v);
	}
}

int val[maxn][M];
int T[maxn << 2][M], lazy[maxn << 2][M];
void pushup(int k, int rt) {T[rt][k] = T[rt << 1][k] + T[rt << 1 | 1][k];}
void build(int k, int rt, int l, int r)
{
	if (l == r)
	{
		T[rt][k] = val[rnk[l]][k];
		return;
	}
	int mid = (l + r) >> 1;
	build(k, rt << 1, l, mid);
	build(k, rt << 1 | 1, mid + 1, r);
	pushup(k, rt);
}
void pushdown(int k, int rt, int l, int r)
{
	if (lazy[rt][k] == -1) return;
	lazy[rt << 1][k] = lazy[rt << 1 | 1][k] = lazy[rt][k];
	int mid = (l + r) >> 1;
	T[rt << 1][k] = lazy[rt][k] * (mid - l + 1);
	T[rt << 1 | 1][k] = lazy[rt][k] * (r - mid);
	lazy[rt][k] = -1;
}
void update(int k, int rt, int l, int r, int L, int R, int c)
{
	if (L <= l && r <= R)
	{
		T[rt][k] = c * (r - l + 1);
		lazy[rt][k] = c;
		return; 
	}
	int mid = (l + r) >> 1;
	pushdown(k, rt, l, r);
	if (L <= mid) update(k, rt << 1, l, mid, L, R, c);
	if (mid <  R) update(k, rt << 1 | 1, mid + 1, r, L, R, c);
	pushup(k, rt);
}
int query(int k, int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return T[rt][k];
	int mid = (l + r) >> 1;
	pushdown(k, rt, l, r);
	int res = 0;
	if (L <= mid) res += query(k, rt << 1, l, mid, L, R);
	if (mid <  R) res += query(k, rt << 1 | 1, mid + 1, r, L, R);
	return res;
}

void treeupdate(int k, int x, int y, int c)
{
	int topx = top[x], topy = top[y];
	while (topx != topy)
	{
		if (dep[topx] > dep[topy]) 
		{
			update(k, 1, 1, n, id[topx], id[x], c);
			x = father[topx]; topx = top[x];
		}
		else 
		{
			update(k, 1, 1, n, id[topy], id[y], c);
			y = father[topy]; topy = top[y];
		}
	}
	if (dep[x] > dep[y]) swap(x, y);
	update(k, 1, 1, n, id[x], id[y], c);
}

int treequery(int k, int x, int y)
{
	int res = 0;
	int topx = top[x], topy = top[y];
	while (topx != topy)
	{
		if (dep[topx] > dep[topy]) 
		{
			res += query(k, 1, 1, n, id[topx], id[x]);
			x = father[topx]; topx = top[x];
		}
		else 
		{
			res += query(k, 1, 1, n, id[topy], id[y]);
			y = father[topy]; topy = top[y];
		}
	}
	if (dep[x] > dep[y]) swap(x, y);
	res += query(k, 1, 1, n, id[x], id[y]);
	return res % 2;
}

int main()
{
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d", &a[i]);
		for (int j = 0; j < 30; j++)
		{
			val[i][j] = a[i] % 2;
			a[i] /= 2;
		}
	}
	for (int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	dfs1(1, 0, 0); cnt = 0; dfs2(1, 1);
	MEM(lazy, -1);
	for (int k = 0; k < 30; k++) build(k, 1, 1, n);
	while (q--)
	{
		int opt, s, t; scanf("%d%d%d", &opt, &s, &t);
		int now;
		if (opt == 1)
		{
			for (int k = 0; k < 30; k++)
			{
				now = t % 2; t /= 2;
				if (now == 1) treeupdate(k, 1, s, 1);
			}
		}
		else if (opt == 2)
		{
			for (int k = 0; k < 30; k++)
			{
				now = t % 2; t /= 2;
				if (now == 0) treeupdate(k, 1, s, 0);
			}
		}
		else if (opt == 3)
		{
			int flag = 1;
			for (int k = 0; k < 30; k++)
			{
				now = t % 2; t /= 2;
				int res = treequery(k, 1, s);
				if (res != now) flag = 0;
			}
			if (flag) puts("NO"); else puts("YES");
		}
	}
	return 0;
}


