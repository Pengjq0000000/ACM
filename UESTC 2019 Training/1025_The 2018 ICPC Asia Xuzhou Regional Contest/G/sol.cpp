#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define mod 1000000007
#define ll long long
using namespace std;
const int N = 3e5 + 7;
struct node{int u, v, next;}e[N << 2];
int head[N], tot;
void add_edge(int u, int v) {e[++tot] = {u, v, head[u]}; head[u] = tot;}
int son[N], father[N], id[N], sz[N], rnk[N], dep[N], top[N], val[N];
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
vector<pii>path[N];
void deal(int p, int x, int y)
{
    //if (x == y) {path[p].push_back({id[x], id[x]}); return;}
    int topx = top[x], topy = top[y];
    while (topx != topy)
    {
        if (dep[topx] < dep[topy]) swap(topx, topy), swap(x, y);
        path[p].push_back({id[topx], id[x]});
        x = father[topx]; topx = top[x];
    }   
    if (dep[x] > dep[y]) swap(x, y);
    path[p].push_back({id[x], id[y]});
    sort(path[p].begin(), path[p].end());
}
int a[N], lazy[N];
vector<int>ins[N];

inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
int fac[N], inv[N];
int C(int n, int m)
{
    if (n < m) return 0;
    return mul(fac[n], mul(inv[m], inv[n - m]));
}
int ksm(int a, int b)
{
    int res = 1;
    while (b)
    {
        if (b & 1) res = mul(res, a);
        a = mul(a, a);
        b /= 2;
    }
    return res;
}
int main()
{
    fac[0] = 1; for (int i = 1; i <= 300000; i++) fac[i] = mul(fac[i - 1], i);
    inv[300000] = ksm(fac[300000], mod - 2); for (int i = 300000; i; i--) inv[i - 1] = mul(inv[i], i); 
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, m, k; scanf("%d%d%d", &n, &m, &k);
        tot = 1; for (int i = 1; i <= n; i++) head[i] = 0;
        for (int i = 1, u, v; i < n; i++) 
        {
            scanf("%d%d", &u, &v);
            add_edge(u, v); add_edge(v, u);
        }
        int root = 1;
        dfs1(root, 0, 0);
        tim = 0; dfs2(root, root);
        for (int i = 1; i <= max(n, m); i++) ins[i].clear(), path[i].clear();
        for (int i = 1, x, y; i <= m; i++) 
        {
            scanf("%d%d", &x, &y);
            deal(i, x, y);
            ins[path[i][0].fir].push_back(i);
        }
        int ans = 0, cnt = 0;
        for (int i = 1; i <= max(n, m); i++) lazy[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            cnt += lazy[i];
            for (int &p : ins[i]) 
            {
                ans = add(ans, C(cnt, k - 1));
                cnt++;
                //printf("p = %d:\n", p);
                for (pii &line : path[p]) 
                {
                    //printf("update : %d %d\n", line.fir, line.sec);
                    lazy[line.fir] += 1;
                    lazy[line.sec + 1] -= 1;
                }
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}