#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
// build graph //
struct node{int v, next;}e[maxn << 1];
int tot, head[maxn];
int n, m, root; 
void add(int u, int v)
{
    ++tot;
    e[tot].v = v; e[tot].next = head[u];
    head[u] = tot;
}

// dfs //
int son[maxn], sz[maxn], father[maxn], dep[maxn], rnk[maxn], in[maxn], out[maxn], top[maxn]; 
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
int cnt;
void dfs2(int u, int tp)
{
    ++cnt; in[u] = cnt; rnk[cnt] = u;
    top[u] = tp;
    if (son[u]) dfs2(son[u], tp);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == father[u] || v == son[u]) continue;
        dfs2(v, v);
    }
    out[u] = cnt;
}

// segment tree//
int T[maxn << 2];
void pushdown(int rt)
{
    if (T[rt] == 0) return;
    T[rt << 1] += T[rt]; T[rt << 1 | 1] += T[rt];
    T[rt] = 0;    
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {T[rt] += val; return;}
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
}
int query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}

// chain operation //
void treeupdate(int x, int y, int val)
{
    int topx = top[x], topy = top[y];
    while (topx != topy)
    {
        if (dep[topx] > dep[topy])
        {
            update(1, 1, n, in[topx], in[x], val);
            x = father[topx]; topx = top[x];
        }
        else
        {
            update(1, 1, n, in[topy], in[y], val);
            y = father[topy]; topy = top[y];
        }
    }
    if (dep[x] > dep[y]) swap(x, y);
    update(1, 1, n, in[x], in[y], val);
}
int main()
{
    scanf("%d%d%d", &n, &m, &root);
    tot = 0; MEM(head, 0);
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    dfs1(root, 0, 0);
    cnt = 0; dfs2(root, root);
    while (m--)
    {
        int k, x, y, c;
        scanf("%d", &k);
        if (k == 1) {scanf("%d%d", &x, &c); update(1, 1, n, in[x], out[x], c); }
        else if (k == 2) {scanf("%d%d%d", &x, &y, &c); treeupdate(x, y, c);}
        else if (k == 3) {scanf("%d", &x); printf("%d\n", query(1, 1, n, in[x]));}
    }
    return 0;
}
/*
2 3 1
1 2
1 1 1
2 2 1 1
3 2
*/








