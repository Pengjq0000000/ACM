#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 7;
vector<int>G[MAXN], rG[MAXN];
int dp[MAXN], d[MAXN];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v); d[u]++;
        rG[v].push_back(u);
    }
    queue<int>q;
    for (int i = 1; i <= n; i++) if (!d[i]) q.push(i);
    int ans = 0;
    while (q.size())
    {
        int u = q.front(); q.pop();
        for (int v : rG[u]) 
        {
            ans = max(ans, dp[v] = max(dp[v], dp[u] + 1));
            if ((--d[v]) == 0) q.push(v);
        }
    }
    printf("%d\n", ans);
    return 0;
}