#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e4 + 7;
struct node
{
    int u, v, next, w, last;
    node(int u, int v, int next, int w):u(u), v(v), next(next), w(w){}
    node(int v, int w):v(v), w(w){}
    node(){}
    bool operator < (const node &rhs ) const
    {
        return w > rhs.w;
    }
}e[maxn * 10];
int n, m, tot;
int pre[maxn], head[maxn], dis[maxn], vis[maxn];

void add(int u, int v, int w)
{
    ++tot;
    e[tot] = node(u, v, head[u], w);
    head[u] = tot;
}

priority_queue<node>q;
void dij(int s, int t, int skip)
{
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) dis[i] = 1e9, vis[i] = 0;
    q.push(node(s, 0)); dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            if (i == skip) continue;
            int v = e[i].v, w = e[i].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = dis[u] + w;
                if (!skip) pre[v] = i;
                q.push(node(v, dis[v]));
            }
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        tot = 0; MEM(head, 0); MEM(pre, 0);
        scanf("%d%d", &n, &m);
        while (m--)
        {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        dij(1, n, 0);
        int ans = dis[n];
        for (int i = pre[n]; i; i = pre[e[i].u])
        {
            dij(1, n, i);
            ans = max(ans, dis[n]);
            if (ans == 1e9) break;
        }
        printf("%d\n", ans == 1e9 ? -1 : ans);
    }
    return 0;
}


