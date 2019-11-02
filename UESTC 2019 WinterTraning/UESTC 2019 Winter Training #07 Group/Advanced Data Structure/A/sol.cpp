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
int head[maxn], tot, n;
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
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = val[rnk[l]]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) {T[rt] = val; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(rt << 1, l, mid, pos, val);
    else update(rt << 1 | 1, mid + 1, r, pos, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    int res = -INF;
    if (L <= mid) res = max(res, query(rt << 1, l, mid, L, R));
    if (mid < R)  res = max(res, query(rt << 1 | 1, mid + 1, r, L, R));
    return res;
}

int treequery(int x, int y)
{
    int res = -INF;
    int topx = top[x], topy = top[y];
    while (topx != topy)
    {
        if (dep[topx] > dep[topy]) 
        {
            res = max(res, query(1, 1, n, id[topx], id[x]));
            x = father[topx]; topx = top[x];
        }
        else
        {
            res = max(res, query(1, 1, n, id[topy], id[y]));
            y = father[topy]; topy = top[y];
        }
    }
    if (x == y) return res;
    if (dep[x] > dep[y]) swap(x, y);
    res = max(res, query(1, 1, n, id[son[x]], id[y]));
    return res;
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
            add(u, v, w); add(v, u, w);
        }
        int root = 1;
        dfs1(root, 0, 0);
        tim = 0; dfs2(root, root);
        for (int i = 1; i <= tot; i += 2)
        {
            int u = e[i].u, v = e[i].v;
            if (dep[u] < dep[v]) swap(e[i].u, e[i].v);
            val[e[i].u] = e[i].w;
        }
        build(1, 1, n);
        char s[10];
        while (scanf("%s", s) != EOF)
        {
            if (s[0] == 'D') break;
            int x, y; scanf("%d%d", &x, &y);
            if (s[0] == 'Q') printf("%d\n", treequery(x, y));
            else if (s[0] == 'C')
            {
                int u = e[2 * x - 1].u;
                update(1, 1, n, id[u], y);
            }
        }
    }
    return 0;
}

