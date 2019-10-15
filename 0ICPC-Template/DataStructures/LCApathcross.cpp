#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
int read() 
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int N = 5e5 + 7;
const int M = 20;
vector<pii>G[N];
int ST[N << 1][M], elr[N << 1], dep[N], in[N];
ll dist[N];
int cnt = 0;
void dfs(int u, int fa)
{
    elr[++cnt] = u; in[u] = cnt;
    for (pii edge : G[u])
    {
        int v = edge.fir, w = edge.sec;
        if (v == fa) continue;
        dist[v] = dist[u] + w; dep[v] = dep[u] + 1;
        dfs(v, u);
        elr[++cnt] = u;
    } 
}
inline int cal(int x, int y) {return dep[x] < dep[y] ? x : y;}
void init(int rt)
{
    cnt = 0; dist[rt] = 0; dep[rt] = 1;
    dfs(rt, 0);
    for (int i = 1; i <= cnt; i++) ST[i][0] = elr[i];
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= cnt; i++)
            ST[i][j] = cal(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
inline int LCA(int x, int y)
{
    int l = in[x], r = in[y];
    if (l > r) swap(l, r);
    int k = log2(r - l + 1);
    return cal(ST[l][k], ST[r - (1 << k) + 1][k]);
}
inline ll getdist(int u, int v){ return dist[u] + dist[v] - dist[LCA(u, v)] * 2;}
#define lson (rt << 1)
#define rson (rt << 1 | 1)
struct node{int u, v; ll w;}path[N], T[N << 2];
int p[4]; bool cmp(const int &x, const int &y)  {return dep[x] > dep[y];}
node merge(node &x, node &y)
{
    if (x.u == y.u && x.v == y.v) return x;
    if (!x.w || !y.w) return {0, 0, 0};
    p[0] = LCA(x.u, y.u);
    p[1] = LCA(x.u, y.v);
    p[2] = LCA(x.v, y.u);
    p[3] = LCA(x.v, y.v);
    sort(p, p + 4, cmp);
    int u = p[0], v = p[1]; 
    if (u == v && (dep[u] < dep[LCA(x.u, x.v)] || dep[v] < dep[LCA(y.u, y.v)])) return {0, 0, 0};
    else return {u, v, getdist(u, v)};
}
void pushup(int rt) {T[rt] = merge(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        T[rt].u = path[l].u; T[rt].v = path[l].v;
        T[rt].w = getdist(T[rt].u, T[rt].v);
        return;
    } 
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
node query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    node resl = {0, 0, -1}, resr = {0, 0, -1};
    if (L <= mid) resl = query(lson, l, mid, L, R);
    if (mid <  R) resr = query(rson, mid + 1, r, L, R);
    if (resl.w == -1) return resr;
    if (resr.w == -1) return resl;
    return merge(resl, resr);
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, u, v, w; i < n; i++)
    {
        u = read(); v = read(); w = read();
        G[u].push_back({v, w});
        G[v].push_back({u, w});
    }
    init(1);
    int m; scanf("%d", &m);
    for (int i = 1; i <= m; i++) path[i].u = read(), path[i].v = read();
    build(1, 1, m);
    int q; scanf("%d", &q);
    while (q--)
    {
        int l = read(), r = read(); 
        node res = query(1, 1, m, l, r);
        printf("%lld\n", res.w);
    }

    return 0;
}