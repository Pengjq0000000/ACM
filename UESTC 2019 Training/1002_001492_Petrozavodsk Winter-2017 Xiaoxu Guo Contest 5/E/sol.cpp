#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 7;
int n, w[maxn];
vector<int>G[maxn];
int sz[maxn], son[maxn], dep[maxn], f[maxn];
int tim, top[maxn], id[maxn], rk[maxn];
int T[maxn << 2], lazy[maxn << 2];
void build(int rt, int l, int r)
{
    T[rt] = lazy[rt] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void upd(int rt, int l, int r, int v)
{
    T[rt] += (w[rk[r]] - w[f[rk[l]]]) * v;
    lazy[rt] += v;
}
void pushdown(int rt, int l, int r)
{
    if (!lazy[rt]) return;
    int mid = (l + r) >> 1;
    upd(lson, l, mid, lazy[rt]);
    upd(rson, mid + 1, r, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) {upd(rt, l, r, 1); return;}
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R);
    if (mid <  R) update(rson, mid + 1, r, L, R);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1, res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}
void dfs1(int u, int fa, int d)
{
    sz[u] = 1; son[u] = 0; dep[u] = d;
    for (int v : G[u])
    {
        if (v == fa) continue;
        dfs1(v, u, d + 1);
        sz[u] += sz[v];
        if (!son[u] || sz[son[u]] < sz[v]) son[u] = v;
    }
}
void dfs2(int u, int tp)
{
    ++tim; id[u] = tim; rk[tim] = u;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int v : G[u])
    {
        if (v == f[u] || v == son[u]) continue;
        dfs2(v, v);
    }
}
void treeupdate(int x, int y)
{
    int topx = top[x], topy = top[y];
    while (topx != topy)
    {
        if (dep[topx] < dep[topy]) swap(topx, topy), swap(x, y);
        update(1, 1, n, id[topx], id[x]);
        x = f[topx]; topx = top[x];
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, 1, n, id[x], id[y]);
}
int treequery(int x, int y)
{
    int topx = top[x], topy = top[y];
    int res = 0;
    while (topx != topy)
    {
        if (dep[topx] < dep[topy]) swap(topx, topy), swap(x, y);
        res += query(1, 1, n, id[topx], id[x]);
        x = f[topx]; topx = top[x];
    }
    if (dep[x] > dep[y]) swap(x, y);
    res += query(1, 1, n, id[x], id[y]);
    return res;
}
int main()
{
    while (~scanf("%d", &n))
    {
        for (int i = 1; i <= n; i++) G[i].clear();
        for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
        for (int v = 2; v <= n; v++) scanf("%d", &f[v]), G[f[v]].push_back(v);
        dfs1(1, 0, 1);
        tim = 0; dfs2(1, 1);
        build(1, 1, n);
        for (int u = 1; u <= n; u++)
        {
            if (u > 1) printf("%d\n", treequery(1, u));
            treeupdate(1, u);
        }
    }
    return 0;
}