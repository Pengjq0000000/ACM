#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
int dfn[maxn], f[maxn][20], dep[maxn], d[maxn], tim;
bool keyp[maxn];
vector<int>E[maxn];
struct node{int op, u, v, k;}q[maxn];
void dfs(int u)
{
    dfn[u] = ++tim;
    for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1]; 
    for (int v : E[u])
    {
        if (v == f[u][0]) continue;
        f[v][0] = u; dep[v] = dep[u] + 1;
        dfs(v);
    }
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) if (dep[x] < dep[y] && dep[x] <= dep[f[y][i]]) y = f[y][i];
    for (int i = 19; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0]; 
}

int cnt[maxn];
vector<int>vv;
bool cmp(int x, int y) {return dfn[x] < dfn[y];}

void build(int u, int pre, int fa)
{
    if (keyp[u]) 
    {
        dep[u] = dep[fa] + 1, f[u][0] = fa;
        for (int i = 1; i < 20; i++) f[u][i] = f[f[u][i - 1]][i - 1];
        cnt[u] = d[u] - d[fa] - 1; // (u -> fa)
    }
    for (int v : E[u])
    {
        if (v == pre) continue;
        build(v, u, keyp[u] ? u : fa);
    }
}
LL w_self[maxn], w_up[maxn];
void update(LL &x, LL k, int op)
{
    if (op == 1) x += k;
    else if (op == 2) x ^= k;
    else if (op == 3 && x >= k) x -= k;
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) E[i].clear(), keyp[i] = w_up[i] = w_self[i] = 0;
        vv.clear();
        for (int i = 1; i < n; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
            E[u].pb(v); E[v].pb(u);
        }
        tim = 0; dep[1] = 1; f[1][0] = 0; dfs(1);
        for (int i = 1; i <= m; i++)
        {
            scanf("%d%d%d", &q[i].op, &q[i].u, &q[i].v);
            if (q[i].op <= 3 || q[i].op == 7) scanf("%d", &q[i].k);
            vv.pb(q[i].u); vv.pb(q[i].v);
        }
        sort(vv.begin(), vv.end(), cmp);
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        int sz = vv.size();
        for (int i = 1; i < sz; i++) vv.pb(LCA(vv[i - 1], vv[i]));
        for (int x : vv) keyp[x] = 1;
        for (int i = 1; i <= n; i++) d[i] = dep[i];
        dep[0] = 0; build(1, 0, 0); 
        for (int i = 1; i <= m; i++)
        {
            int u = q[i].u, v= q[i].v, op = q[i].op;
            LL k = q[i].k;
            int lca = LCA(u, v);
            if (op <= 3)
            {
                update(w_self[lca], k, op);
                for (int x = u; x != lca; x = f[x][0]) update(w_self[x], k, op), update(w_up[x], k, op);
                for (int x = v; x != lca; x = f[x][0]) update(w_self[x], k, op), update(w_up[x], k, op);
            }
            else if (op == 4)
            {
                LL sum = w_self[lca];
                for (int x = u; x != lca; x = f[x][0]) sum += w_up[x] * cnt[x] + w_self[x]; 
                for (int x = v; x != lca; x = f[x][0]) sum += w_up[x] * cnt[x] + w_self[x];
                printf("%lld\n", sum);
            }
            else if (op == 5)
            {
                LL sum = w_self[lca];
                for (int x = u; x != lca; x = f[x][0]) sum ^= w_self[x] ^ (w_up[x] * (cnt[x] & 1));
                for (int x = v; x != lca; x = f[x][0]) sum ^= w_self[x] ^ (w_up[x] * (cnt[x] & 1));
                printf("%lld\n", sum);
            }
            else if (op == 6)
            {
                LL mx = w_self[lca], mi = w_self[lca];
                for (int x = u; x != lca; x = f[x][0]) 
                {
                    mx = max(mx, w_self[x]);
                    if (cnt[x]) mx = max(mx, w_up[x]);
                    mi = min(mi, w_self[x]);
                    if (cnt[x]) mi = min(mi, w_up[x]);
                }
                for (int x = v; x != lca; x = f[x][0]) 
                {
                    mx = max(mx, w_self[x]);
                    if (cnt[x]) mx = max(mx, w_up[x]);
                    mi = min(mi, w_self[x]);
                    if (cnt[x]) mi = min(mi, w_up[x]);
                }
                printf("%lld\n", mx - mi);
            }
            else 
            {
                LL mi = abs(w_self[lca] - k);
                for (int x = u; x != lca; x = f[x][0]) 
                {
                    mi = min(mi, abs(w_self[x] - k));
                    if (cnt[x]) mi = min(mi, abs(w_up[x] - k));
                }
                for (int x = v; x != lca; x = f[x][0]) 
                {
                    mi = min(mi, abs(w_self[x] - k));
                    if (cnt[x]) mi = min(mi, abs(w_up[x] - k));
                }
                printf("%lld\n", mi);
            }
        }
    }
    return 0;
}
