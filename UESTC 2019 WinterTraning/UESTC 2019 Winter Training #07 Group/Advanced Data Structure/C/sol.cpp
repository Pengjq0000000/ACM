#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node{int v, next;}e[maxn << 1];
int tot, head[maxn], n, m;
void add(int u, int v)
{
	++tot; e[tot].v = v; e[tot].next = head[u];
	head[u] = tot;
}
int father[maxn], son[maxn], top[maxn], sz[maxn], id[maxn], rnk[maxn], dep[maxn];
void dfs1(int u, int fa, int depth)
{
	father[u] = fa; son[u] = 0; sz[u] = 1; dep[u] = depth;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == father[u]) continue;
		dfs1(v, u, depth + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) son[u] = v;
	}
}
int cnt;
void dfs2(int u, int tp)
{
	++cnt; id[u] = cnt; rnk[cnt] = u;
	top[u] = tp;
	if (son[u]) dfs2(son[u], tp);
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == father[u] || v == son[u]) continue;
		dfs2(v, v);
	} 
}
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r)
{
	if (l == r) {T[rt] = 0; return;}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}
void update(int rt, int l, int r, int pos)
{
	if (l == r) {T[rt] ^= 1; return;}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(rt << 1, l, mid, pos);
	else update(rt << 1 | 1, mid + 1, r, pos);
	pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
	if (T[rt] == 0) return -1;
	if (l == r) return l;
	int mid = (l + r) >> 1;
	int res = 0;
	if (L <= mid) res = query(rt << 1, l, mid, L, R);
	if (res > 0) return res;
	if (mid <  R) res = query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}
int query_nd(int x)
{
	int res = -1;
	while (x != 0)
	{
		int tmp = query(1, 1, n, id[top[x]], id[x]);
		if (tmp > 0) res = rnk[tmp];
		x = father[top[x]];
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i < n; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
	}
	int root = 1;
	dfs1(root, 0, 0); cnt = 0; dfs2(root, root);
	build(1, 1, n);
	while (m--)
	{
		int op, x; scanf("%d%d", &op, &x);
		if (op == 0) update(1, 1, n, id[x]);
		else printf("%d\n", query_nd(x));
	}
	return 0;
}
