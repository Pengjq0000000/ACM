// 01 shortest path
deque<int>dq;
int dis[maxn], vis[maxn];
void BFS(int s)
{
    for (int i = 1; i <= n; i++) dis[x] = INF, vis[x] = 0;
    dis[s] = 0; dq.push_back(s);
    while (!dq.empty())
    {
        int u = dq.front(); dq.pop_front();
        if (vis[u]) continue;
        vis[u] = 1;
        for (auto x : E[u])
        {
            if (dis[x.fir] > dis[u] + x.sec)
            {
                dis[x.fir] = dis[u] + x.sec;
                if (vis[x.fir]) continue;
                x.sec == 1 ? dq.push_back(x.fir) : dq.push_front(x.fir);
            }
        }
    }
}
