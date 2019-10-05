#include<bits/stdc++.h>
using namespace std;
const int maxn = 307;
bitset<maxn>dp[maxn]; 
vector<int>G[maxn], E[maxn];
int out[maxn];
int col[maxn], a[maxn];
int n, m, q;
int solve()
{
    int ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int u = a[i]; 
        dp[u].reset();
        if (col[u]) continue;
        dp[u].set(u);
        for (int v : E[u])
        {
            if (col[v]) continue;
            dp[u] |= dp[v];
        }
        ans += dp[u].count() - 1;
    }
    return ans;
}
queue<int>Q;
int main()
{
    while (scanf("%d %d %d", &n, &m, &q) == 3)
    {
        for (int i = 1; i <= n; i++) E[i].clear(), G[i].clear(), out[i] = col[i] = 0;
        while (m--)
        {
            int u, v; scanf("%d %d", &u, &v);
            E[u].push_back(v);
            G[v].push_back(u);
            out[u]++;
        }
        for (int i = 1; i <= n; i++)
            if (!out[i]) Q.push(i);
        int cnt = 0;
        while (!Q.empty())
        {
            int u = Q.front(); Q.pop();
            a[++cnt] = u;
            for (int v : G[u])
            {
                out[v]--;
                if (!out[v]) Q.push(v);
            }
        }
        while (q--)
        {
            int v; scanf("%d", &v);
            col[v] ^= 1;
            printf("%d\n", solve());
        }
    }
    return 0;
}