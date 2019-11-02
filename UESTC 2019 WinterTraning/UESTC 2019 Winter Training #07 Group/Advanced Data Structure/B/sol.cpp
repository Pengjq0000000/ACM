#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e4 + 7;
struct node {int u, v, w, next;} e[maxn << 1];
int head[maxn], tot;
int n; 
void add(int u, int v, int w)
{
	++tot;
	e[tot].u = u; e[tot].v = v; e[tot].w = w; 
	e[tot].next = head[u]; head[u] = tot;	
}
int father[maxn], son[maxn], sz[maxn], id[maxn], rnk[maxn], dep[maxn], top[maxn], val[maxn];
void dfs1(int u, int fa, int depth)
{
	father[u] = fa; sz[u] = 1; son[u] = 0;
	dep[u] = depth;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == father[u]) continue;
		dfs1(v, u, depth + 1);
		sz[u] += sz[v];
		if (sz[son[u]] < sz[v]) son[u] = v; 
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
		if (v == father[u] || v == son[u]) continue;
		dfs2(v, v);
	}
}

int T[maxn << 2];
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
	if (l == r) {T[rt] = val[rnk[l]]; return;}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return T[rt];
	int mid = (l + r) >> 1;
	int res = 0;
	if (L <= mid) res += query(rt << 1, l, mid, L, R);
	if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}
int query_sum(int x, int y)
{
	int topx = top[x], topy = top[y];
	int res = 0;
	while (topx != topy)
	{
		if (dep[topx] < dep[topy]){swap(topx, topy); swap(x, y);}
		res += query(1, 1, n, id[topx], id[x]);
		x = father[topx]; topx = top[x];
	}
	if (x == y) return res;
	if (dep[x] > dep[y]) swap(x, y);
	res += query(1, 1, n, id[son[x]], id[y]);
	return res;
}
int LCA(int x, int y)
{
	while (top[x] != top[y])
	{
		if (dep[top[x]] > dep[top[y]]) x = father[top[x]];
		else y = father[top[y]]; 
	}
	if (dep[x] < dep[y]) return x; else return y;
}
int query_kth(int x, int y, int k)
{
	int lca = LCA(x, y);
	if (dep[x] - dep[lca] + 1 < k) 
	{
		k -= dep[x] - dep[lca] + 1;
		k = dep[y] - dep[lca] + 1 - k;
		swap(x, y);	
	}	
	while (dep[top[x]] > dep[lca])
	{
		int tmp = dep[x] - dep[top[x]] + 1;
		if (tmp >= k) break; k -= tmp;
		x = father[top[x]];
	}
	return rnk[id[x] - k + 1];
}
int main()
{
	int t; scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		tot = 0; MEM(head, 0);
		for (int i = 1; i < n; i++)
		{
			int u, v, w; scanf("%d%d%d", &u, &v, &w);
			add(u, v, w);
			add(v, u, w);
		} 
		int root = 1;
		dfs1(root, 0, 0); cnt = 0; dfs2(root, root);
		for (int i = 1; i <= tot; i += 2)
		{
			if (dep[e[i].u] < dep[e[i].v]) swap(e[i].u, e[i].v);
			val[e[i].u] = e[i].w;
		}
		build(1, 1, n);
		char s[10];
		while (scanf(" %s", s) != EOF)
		{
			if (s[0] == 'D' && s[1] == 'O') break;
			if (s[0] == 'K') 
			{
				int x, y, k; scanf("%d%d%d", &x, &y, &k);
				printf("%d\n", query_kth(x, y, k));
			} 
			else if (s[0] == 'D')
			{
				int x, y; scanf("%d%d", &x, &y);
				printf("%d\n", query_sum(x, y));
			}
		}
	}
	return 0;
}
