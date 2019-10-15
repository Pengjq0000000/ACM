// 欧拉序+ST表nlogn预处理 O(1)回答LCA
// 利用4对点的LCA判断两条路径的交集
// 路径交集可合并 可以用线段树维护 注意查询的初始值
const int N = 5e5 + 7;
const int M = 20;
vector<pii>G[N];
int ST[N << 1][M], elr[N << 1], dep[N << 1], in[N];
ll dist[N];
int cnt = 0;
void dfs(int u, int fa, int d)
{
    elr[++cnt] = u; dep[cnt] = d; in[u] = cnt;
    for (pii edge : G[u])
    {
        int v = edge.fir, w = edge.sec;
        if (v == fa) continue;
        dist[v] = dist[u] + w;
        dfs(v, u, d + 1);
        elr[++cnt] = u; dep[cnt] = d;
    } 
}
inline int cal(int x, int y) {return dep[x] < dep[y] ? x : y;}
void init(int rt)
{
    cnt = 0; dist[rt] = 0;
    dfs(rt, 0, 1);
    for (int i = 1; i <= cnt; i++) ST[i][0] = i;
    for (int j = 1; j < 20; j++)
        for (int i = 1; i + (1 << j) - 1 <= cnt; i++)
            ST[i][j] = cal(ST[i][j - 1], ST[i + (1 << (j - 1))][j - 1]);
}
inline int LCA(int x, int y)
{
    int l = in[x], r = in[y];
    if (l > r) swap(l, r);
    int k = log2(r - l + 1);
    return elr[cal(ST[l][k], ST[r - (1 << k) + 1][k])];
}
inline ll getdist(int u, int v){ return dist[u] + dist[v] - dist[LCA(u, v)] * 2;}
struct node{int u, v; ll w;}path[N], T[N << 2];
int p[4]; bool cmp(int x, int y) {return dep[in[x]] > dep[in[y]];}
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
    if (u == v && (dep[in[u]] < dep[in[LCA(x.u, x.v)]] || dep[in[v]] < dep[in[LCA(y.u, y.v)]])) return {0, 0, 0};
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