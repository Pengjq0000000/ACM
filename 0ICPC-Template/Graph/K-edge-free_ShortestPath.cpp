LL dis[maxn][maxn];
int vis[maxn][maxn];
struct Node
{
    LL w; int u, k;
    Node(LL w, int u, int k) : w(w), u(u), k(k){}
    bool operator < (const Node &rhs) const 
    {
        return w > rhs.w;
    }
};
priority_queue<Node>q;
LL dijkstra(int s, int t)
{
    for (int i = 1; i <= n; i++) 
        for (int j = 0; j <= k; j++)
            dis[i][j] = 1e18;
    q.push(Node(0, s, 0));
    dis[s][0] = 0;
    while (!q.empty())
    {
        Node now = q.top(); q.pop();
        if (vis[now.u][now.k]) continue;
        for (int i = head[now.u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (dis[v][now.k] > dis[now.u][now.k] + e[i].w)
            {
                dis[v][now.k] = dis[now.u][now.k] + e[i].w;
                q.push(Node(dis[v][now.k], v, now.k));
            }
            if (now.k == k) continue;
            if (dis[v][now.k + 1] > dis[now.u][now.k])
            {
                dis[v][now.k + 1] = dis[now.u][now.k];
                q.push(Node(dis[v][now.k + 1], v, now.k + 1));
            }
        }
    }
    return dis[t][k];
}