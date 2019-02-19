#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
struct node
{
    int v, next, w;
    node(int v, int next, int w):v(v), next(next), w(w){}
    node(){}
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
}e[maxn];
int head[1007], dis[1007], vis[1007], tot;
int s = 0, aim = 1006;

void add(int u, int v, int w)
{
    ++tot;
    e[tot] = node(v, head[u], w);
    head[u] = tot;
}


priority_queue<node>q;
int dij(int s, int t)
{
    MEM(dis, 0x3f3f3f3f); MEM(vis, 0);
    while (!q.empty()) q.pop();
    dis[s] = 0;
    q.push(node(s, 0, 0));
    while (!q.empty())
    {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v, cost = e[i].w;
            if (dis[v] > dis[u] + cost)
            {
                dis[v] = dis[u] + cost;
                q.push(node(v, 0, dis[v]));
            }  
        }
    }
    return dis[t];
}

int main()
{
    int T, S, D;
    while (scanf("%d%d%d",&T, &S, &D) != EOF)
    {
        tot = 0; MEM(head, 0); 
        while (T--)
        {
            int u, v, w; scanf("%d%d%d",&u, &v, &w);
            add(u, v, w);
            add(v, u, w);
        }
        while (S--) {int x; scanf("%d", &x);add(s, x, 0);}
        while (D--){int x; scanf("%d", &x);add(x, aim, 0);}
        printf("%d\n", dij(s, aim));
    }
    return 0;
}

