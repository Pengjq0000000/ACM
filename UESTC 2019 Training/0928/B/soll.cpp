#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 1e5 + 7;
int T[maxn << 2], ans[maxn];
struct Query{int id, u, v;};
vector<Query>Q[maxn];
vector<pii>edge[10][maxn << 2];

int f[maxn], sz[maxn];
int fa(int x) {return x == f[x] ? x : fa(f[x]);}

void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = Q[l].size(); return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void ins_edge(int rt, int l, int r, int L, int R, pii x, int v)
{
    if (L <= l && r <= R) {edge[v][rt].push_back(x); return;}
    int mid = (l + r) >> 1;
    if (L <= mid) ins_edge(lson, l, mid, L, R, x, v);
    if (mid <  R) ins_edge(rson, mid + 1, r, L, R, x, v);
}
void dfs(int rt, int l, int r, int val)
{
    if (T[rt] == 0) return;
    vector<pair<int*, int>>opt;
    for (int i = 0; i <= val; i++)
        for (auto e : edge[i][rt])
        {   
            int u = fa(e.fir), v = fa(e.sec);
            if (u == v) continue;
            if (sz[u] > sz[v]) swap(u, v);
            opt.push_back({&f[u], f[u]}); f[u] = v;
            opt.push_back({&sz[v], sz[v]}); sz[v] += sz[u];
        }
    if (l == r)
    {
        for (auto x : Q[l])
        {
            if (ans[x.id] >= 0) continue;
            if (fa(x.u) == fa(x.v)) ans[x.id] = val;
            else ans[x.id] = -1;
        }
    }
    else 
    {
        int mid = (l + r) >> 1;
        dfs(lson, l, mid, val);
        dfs(rson, mid + 1, r, val);
    }
    for (auto iter = opt.rbegin(); iter != opt.rend(); iter++)
        (*iter->fir) = iter->sec;
}

map<pii, int>id;
int V[maxn], has[maxn];
pii E[maxn];
int main()
{
    int n, q; scanf("%d%d", &n, &q);
    int N = q;
    for (int i = 1; i <= q; i++)
    {
        ans[i] = -2;
        int op; scanf("%d%d%d", &op, &E[i].fir, &E[i].sec);
        E[i].fir++; E[i].sec++;
        if (E[i].fir > E[i].sec) swap(E[i].fir, E[i].sec);
        if (op == 0) scanf("%d", &V[i]), id[E[i]] = i, has[i] = 1;
        else if (op == 1) 
        {
            int p = id[E[i]];
            ins_edge(1, 1, N, p, i, E[i], V[p]);
            has[p] = 0;
        }
        else Q[i].push_back({i, E[i].fir, E[i].sec});
    }
    for (int i = 1; i <= q; i++)
    {
        if (has[i]) ins_edge(1, 1, N, i, N, E[i], V[i]);
    }
    build(1, 1, N);
    for (int i = 1; i <= n; i++) f[i] = i, sz[i] = 1;
    for (int i = 0; i <= 9; i++)
        dfs(1, 1, N, i);
    for (int i = 1; i <= q; i++)
    {
        if (ans[i] == -2) continue;
        printf("%d\n", ans[i]);
    }
    return 0;
}