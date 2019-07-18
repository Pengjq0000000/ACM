#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
const int INF = 1e9;
struct node{int u, v, w, next;}e[maxn << 1];
int head[maxn], tot, n, m;
void add(int u, int v, int w)
{
    ++tot;
    e[tot].u = u; e[tot].v = v; e[tot].w = w;
    e[tot].next = head[u]; head[u] = tot;
}
int son[maxn], father[maxn], id[maxn], sz[maxn], rnk[maxn], dep[maxn], top[maxn], val[maxn];
int tim;
void dfs1(int u, int fa, int deep)
{
    son[u] = 0; father[u] = fa; dep[u] = deep;
    sz[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == father[u]) continue;
        dfs1(v, u, deep + 1);
        sz[u] += sz[v];
        if (sz[v] > sz[son[u]]) son[u] = v;
    }
}
void dfs2(int u, int tp)
{
    ++tim; id[u] = tim; rnk[tim] = u;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == father[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}

struct Node{int l, r, sum;}T[maxn * 45];
int root[maxn], cnt = 0;
vector<int>vv;
int getid(int x) {return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;}
void update(int l, int r, int &x, int y, int pos)
{
	T[++cnt] = T[y]; T[cnt].sum++; x = cnt;
	if (l == r) return;
	int mid = (l + r) / 2;
	if (pos <= mid) update(l, mid, T[x].l, T[y].l, pos);
	else update(mid + 1, r, T[x].r, T[y].r, pos);
}

int query(int l, int r, int x, int y, int pos)
{
	if (l == r) return T[y].sum - T[x].sum;
	int mid = (l + r) / 2;
	if (pos <= mid) return query(l, mid, T[x].l, T[y].l, pos);
	else return query(mid + 1, r, T[x].r, T[y].r, pos) + T[T[y].l].sum - T[T[x].l].sum;
}

int treequery(int x, int y, int k)
{
    int topx = top[x], topy = top[y];
    int res = 0;
    while (topx != topy)
    {
        if (dep[topx] < dep[topy]) 
        {
            swap(topx, topy); swap(x, y);
        }
        res += query(1, n, root[id[topx] - 1], root[id[x]], k);
        x = father[topx]; topx = top[x];
    }
    if (x == y) return res;
    if (dep[x] > dep[y]) swap(x, y);
    res += query(1, n, root[id[son[x]] - 1], root[id[y]], k);
    return res;
}

int main()
{
	scanf("%d%d", &n, &m);
    tot = 0; MEM(head, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v, w; scanf("%d%d%d", &u, &v, &w);
        add(u, v, w); add(v, u, w);
    }
    int Rt = 1;
    dfs1(Rt, 0, 0);
    tim = 0; dfs2(Rt, Rt);
    for (int i = 1; i <= tot; i += 2)
    {
        int u = e[i].u, v = e[i].v;
        if (dep[u] < dep[v]) swap(e[i].u, e[i].v);
        val[e[i].u] = e[i].w;
    }
    for (int i = 1; i <= n; i++) vv.pb(val[i]);
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    for (int i = 1; i <= n; i++) update(1, n, root[i], root[i - 1], getid(val[rnk[i]]));
    while (m--)
    {
        int u, v, k; scanf("%d%d%d", &u, &v, &k);
        int pos = getid(k);
        if (vv[pos - 1] > k) pos--;
        int ans = treequery(u, v, pos);
        printf("%d\n", ans);
    }
    return 0;
}
