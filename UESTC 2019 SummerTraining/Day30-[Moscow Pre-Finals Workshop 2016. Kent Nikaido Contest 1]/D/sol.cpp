#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int n, m; 
int uu[maxn], vv[maxn];
bool vis[maxn];
int f[maxn];
int fa(int x) {return x == f[x] ? f[x] : f[x] = fa(f[x]);}

struct node{int u, v, next, id;}e[maxn << 1];
int head[maxn], tot = 0;
void add(int u, int v, int id){e[++tot] = {u, v, head[u], id}; head[u] = tot;}

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


int T[maxn << 2], lazy[maxn << 2];
void pushdown(int rt, int l, int r)
{
	if (lazy[rt] == 0) return;
	lazy[rt << 1] ^= lazy[rt];
    lazy[rt << 1 | 1] ^= lazy[rt];
	int mid = (l + r) >> 1;
	T[rt << 1] ^= lazy[rt];
	T[rt << 1 | 1] ^= lazy[rt];
	lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R)
	{
		T[rt] ^= 1;
		lazy[rt] ^= 1;
		return; 
	}
	int mid = (l + r) >> 1;
	pushdown(rt, l, r);
	if (L <= mid) update(rt << 1, l, mid, L, R);
	if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R);
}
int query(int rt, int l, int r, int pos)
{
	if (l == r) return T[rt];
	int mid = (l + r) >> 1;
	pushdown(rt, l, r);
	int res = 0;
	if (pos <= mid) return query(rt << 1, l, mid, pos);
	else return query(rt << 1 | 1, mid + 1, r, pos);
}

void treeupdate(int x, int y)
{
	int topx = top[x], topy = top[y];
	while (topx != topy)
	{
		if (dep[topx] > dep[topy]) 
		{
			update(1, 1, n, id[topx], id[x]);
			x = father[topx]; topx = top[x];
		}
		else 
		{
			update(1, 1, n, id[topy], id[y]);
			y = father[topy]; topy = top[y];
		}
	}
    if (x == y) return;
	if (dep[x] > dep[y]) swap(x, y);
	update(1, 1, n, id[son[x]], id[y]);
}
LL mi[maxn];
LL ans = 0;
int main()
{
    mi[0] = 1;
    for (int i = 1; i <= 1000000; i++) mi[i] = MOD(mi[i - 1] * 2), f[i] = i;
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++) 
    {
        scanf("%d%d", &uu[i], &vv[i]);
        ans = MOD(ans + mi[i]);
        int fu = fa(uu[i]), fv = fa(vv[i]);
        if (fu == fv) continue;
        f[fu] = fv;
        add(uu[i], vv[i], i);
        add(vv[i], uu[i], i);
        vis[i] = 1;
    }
    dfs1(1, 0, 0); cnt = 0; dfs2(1, 1);
    for (int i = m; i >= 1; i--)
    {
        if (vis[i]) continue;
        treeupdate(uu[i], vv[i]); 
    }
    for (int i = 1; i <= tot; i += 2) 
    {
        int x = e[i].u, y = e[i].v;
        if (dep[x] > dep[y]) swap(x, y);
        int res = query(1, 1, n, id[y]);
        if (!res) 
        {
            //printf("%lld\n", mi[e[i].id]);
            ans = MOD(ans + mi[e[i].id]); 
        }
    }
    printf("%lld\n", ans);
	return 0;
}
