#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e4 + 7;
const int INF = 0x7fffffff;
struct node
{
    int v, next, val, w;
    node(int v, int next, int val, LL w):v(v), next(next), val(val), w(w) {}
    node(int v, int w):v(v), w(w) {}
    node() {}
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
}e[maxn * 10];
int tot, n, m, T;
int head[maxn], vis[maxn], num[maxn * 5];
LL dis[maxn];
void add(int u, int v, int val, int w)
{
    ++tot;
    e[tot] = node(v, head[u], val, w);
    head[u] = tot;
}

priority_queue<node>q;

int dij(int s, int t, int lim)
{
    for (int i = 1; i <=n; i++) dis[i] = INF, vis[i] = 0;
    while (!q.empty()) q.pop();
    q.push(node(s, 0)); dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().v; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].next)
        {
            if (e[i].val < lim) continue;
            int v = e[i].v, w = e[i].w;
            if (dis[v] > dis[u] + w)
            {
                dis[v] = dis[u] + w;
                q.push(node(v, dis[v]));
            }
        }
    }
    return dis[t] <= T;
}
int main()
{
    int X; scanf("%d", &X);
    while (X--)
    {
        scanf("%d%d%d", &n, &m, &T);
        LL up = 0; tot = 0;MEM(head, 0);
        for (int i = 1; i <= m; i++)
        {
            int u, v, w;
            scanf("%d%d%d%d", &u, &v, &num[i], &w);
            add(u, v, num[i], w);
            add(v, u, num[i], w);
        }
        sort(num + 1, num + 1 + m);
        int l = 1, r = m;
        while (l < r)
        {
            int mid = (l + r + 1) >> 1;
            if (dij(1, n, num[mid])) l = mid;
            else r = mid - 1;
        }
        printf("%d\n", num[l]);
    }
    return 0;
}

