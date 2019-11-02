#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
int n, vis[maxn]; 
int a[maxn][maxn], dis[maxn], ans[maxn][maxn];
struct node
{
    int u, nxt, w;
    node(int u, int nxt, int w) : u(u), nxt(nxt), w(w) {}
    node(int u, int w) : u(u), w(w) {}
    node(){}
    bool operator < (const node &rhs) const
    {
        return w > rhs.w;
    }
}e[maxn * maxn];
priority_queue<node> q;
int tot = 1, head[maxn];
void add(int u, int v, int w)
{
    e[++tot] = node(v, head[u], w);
    head[u] = tot;
}
void dij(int s)
{
    for (int i = 1; i <= n; i++) dis[i] = 9999;
    q.push(node(s, 0));
    dis[s] = 0;
    while (!q.empty())
    {
        int u = q.top().u; q.pop();
        if (vis[u]) continue;
        vis[u] = 1;
        for (int i = head[u]; i; i = e[i].nxt)
        {
            int v = e[i].u;
            if (dis[v] > dis[u] + e[i].w)
            {
                dis[v] = dis[u] + e[i].w;
                q.push(node(v, dis[v]));
            }
        }
    }
    for (int i = 1; i <= n; i++)
        ans[i][n] = ans[n][i] = dis[i];
}
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                scanf("%d", &a[i][j]);
                if (a[i][j] > 0 && a[i][j] < 9999) add(i, j, a[i][j]);
                ans[i][j] = a[i][j];
            }
    dij(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                ans[i][j] = min(ans[i][j], dis[i] + dis[j]);
                printf("%d%c", ans[i][j], j == n ? '\n' : ' ');
            }
	return 0;
}
