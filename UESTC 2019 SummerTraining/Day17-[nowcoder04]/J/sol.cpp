#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
struct node
{
    int v, next; LL w;
    node(int v, int next, LL w) : v(v), next(next), w(w){}
    node(){}
}e[maxn << 1];
int head[maxn], tot = 0;
int n, m, k, S, T;
void add(int u, int v, LL w)
{
    e[++tot] = node(v, head[u], w);
    head[u] = tot;
}
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
int main()
{
	scanf("%d%d%d%d%d", &n, &m, &S, &T, &k);
    for (int i = 1; i <= m; i++)
    {
        int u, v; LL w;
        scanf("%d%d%lld", &u, &v, &w);
        add(u, v, w);
        add(v, u, w);
    }
    printf("%lld\n", dijkstra(S, T));
	return 0;
}
