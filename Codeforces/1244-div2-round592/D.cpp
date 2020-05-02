#include<bits/stdc++.h>
#define pii pair<int, int>
#define ll long long
using namespace std;
const int MAXN  = 1e5 + 7;
int color[MAXN], son[MAXN];
ll c[MAXN][3];
vector<int>G[MAXN];
void predfs(int u, int fa)
{
    son[u] = -1;
    for (int v : G[u]) if (v != fa)
        predfs(v, u), son[u] = v;
}
pii st[6] = {{0, 1}, {1, 0}, {1, 2}, {2, 1}, {0, 2}, {2, 0}};
int col[6] = {2, 2, 0, 0, 1, 1};
ll res;
void dfs(int u, int c1, int c2)
{
    for (int i = 0; i < 6; i++)
        if (make_pair(c1, c2) == st[i]) color[u] = col[i];
    res += c[u][color[u]];
    if (son[u] > 0) dfs(son[u], color[u], c1);
}
int main()
{
    int n; scanf("%d", &n);
    for (int j = 0; j < 3; j++)
        for (int i = 1; i <= n; i++) scanf("%lld", &c[i][j]);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    int rt = -1;
    for (int u = 1; u <= n; u++)
        if (G[u].size() >= 3)
        {
            puts("-1");
            return 0;
        }
        else if (G[u].size() == 1) rt = u;
    predfs(rt, 0);
    ll ans = 1e18;
    pii ans_st;
    for (int i = 0; i < 6; i++)
    {
        res = c[rt][st[i].second] + c[son[rt]][st[i].first]; 
        dfs(son[son[rt]], st[i].first, st[i].second);
        if (res < ans) ans = res, ans_st = st[i];
    }
    printf("%lld\n", ans);
    color[rt] = ans_st.second, color[son[rt]] = ans_st.first;
    dfs(son[son[rt]], ans_st.first, ans_st.second);
    for (int u = 1; u <= n; u++) printf("%d%c", color[u] + 1, " \n"[u == n]);
    return 0;
}