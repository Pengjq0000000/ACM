#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
int n, m;
vector<pii>G[MAXN];
int dis[MAXN];
bool vis[MAXN];
void dijkstra(int s)
{
    for (int i = 0; i <= n; i++) dis[i] = 2e9;
    priority_queue<pii, vector<pii>, greater<pii> >pq;
    pq.push({dis[s] = 0, s}); 
    while (pq.size())
    {
        int u = pq.top().sec; pq.pop();
        if (vis[u]) continue; 
        vis[u] = 1;
        for (pii e : G[u])
        {
            int v = e.sec, w = e.fir;
            if (dis[u] + w < dis[v]) 
                pq.push({dis[v] = dis[u] + w, v});
        }
    }
}
int main()
{
    int k1, k2; scanf("%d%d%d%d", &n, &m, &k1, &k2);
    for (int i = 1, u, v, w; i <= m; i++)
    {
        scanf("%d%d%d", &u, &v, &w);
        G[u].push_back({w, v});
        G[v].push_back({w, u});
    }
    for (int i = 1, x; i <= k1; i++)
    {
        scanf("%d", &x);
        G[0].push_back({0, x});
    }
    dijkstra(0);
    int ans = 2e9;
    for (int i = 1, x; i <= k2; i++)
    {
        scanf("%d", &x);
        ans = min(ans, dis[x]);
    }
    printf("%d\n", ans);
    return 0;
}