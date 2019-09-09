#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int n, m, s, k, c;
struct node
{
    int v; LL w;
    node(int v, LL w):v(v),w(w){}
    bool operator < (const node &rhs) const 
    {
        return w > rhs.w;
    }
};
struct Node{int v, next; LL w;}e[maxn << 1];
int tot, head[maxn], vis[maxn];
void add(int u, int v, LL w)
{
    e[++tot] = {v, head[u], w};
    head[u] = tot;
}
LL dis[1007];
priority_queue<node>q;
void dij()
{
    while (!q.empty())
    {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v; LL w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
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
        scanf("%d%d%d%d%d", &n, &m, &s, &k, &c);
        for (int i = 1; i <= n; i++) dis[i] = 1e10, vis[i] = head[i] = 0;
        tot = 0;
        for (int i = 1; i <= k; i++)
        {
            int x; scanf("%d", &x);
            dis[x] = 0; q.push(node(x, 0));
        }
        for (int i = 1, u, v, w; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            add(u, v, w); add(v, u, w);
        }
        dij();
        LL ans1 = 0;
        for (int i = 1; i <= n; i++) ans1 = max(ans1, dis[i]);
        for (int i = 1; i <= n; i++) dis[i] = 1e10, vis[i] = 0;
        dis[s] = 0;
        q.push(node(s, 0));
        dij();
        LL ans2 = 0;
        for (int i = 1; i <= n; i++) ans2 = max(ans2, dis[i]);
        if (ans1 * c < ans2) printf("%lld\n", ans1);
        else printf("%lld\n", ans2);
        //printf("%lld\n", ans);
    }
	return 0;
}
