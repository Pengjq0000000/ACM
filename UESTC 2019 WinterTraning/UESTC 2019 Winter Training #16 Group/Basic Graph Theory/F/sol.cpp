#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define INF 1e15

using namespace std;
const int maxn = 3007;
struct node 
{
    int v, next;LL w;
    node(int v, int next, LL w) : v(v), next(next), w(w) {}
    node(int v, LL w) : v(v), w(w) {}
    node() {}
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
}e[2000007];
int n, m;
int head[maxn], vis[maxn], limt[maxn], tot;
LL dis[maxn], mx[maxn];
vector<int> pro[maxn];
priority_queue<node>q;

void init()
{
    tot = 0;
    for (int i = 1; i <= n; i++)
    {
        head[i] = limt[i] = mx[i] = 0;
        pro[i].clear();
    }
}

void add(int u, int v, LL w)
{
    ++tot;
    e[tot] = node(v, head[u], w);
    head[u] = tot;
}

LL dij(int s, int t)
{
    for (int i = 1; i <= n; i++) {dis[i] = INF; vis[i] = 0;}
    q.push(node(s, 0)); dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = 0; i < pro[u].size(); i++)
        {
            int v = pro[u][i]; limt[v]--;
            mx[v] = max(mx[v], dis[u]);
            if (!limt[v] && dis[v] != INF)
            {
                dis[v] = max(dis[v], mx[v]);
                q.push(node(v, dis[v]));
            }
        }
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v; LL w = e[i].w;
            if (dis[u] + w < dis[v])
            {
                dis[v] = max(dis[u] + w, mx[v]);
                if (!limt[v]) q.push(node(v, dis[v]));
            }
        }
    }
    return dis[t];
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m); init();
        while (m--)
        {
            int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
            add(u, v, w);
        }
        for (int i = 1; i <= n; i++)
        {
            int x; scanf("%d", &x);
            while (x--) 
            {
                int u; scanf("%d", &u); 
                pro[u].pb(i); limt[i]++;
            }
        }
        printf("%lld\n", dij(1, n));
    }    
    return 0;
}





