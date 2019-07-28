#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 307;
vector<pii>E[maxn];
vector<int>G[maxn], vv;
queue<int>q;
int vis[maxn], ans[maxn];
void bfs(int s)
{
    vv.clear(); 
    q.push(s); vis[s] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop(); vv.pb(u);
        for (int v : G[u]) 
        {
            if (vis[v]) continue;
            q.push(v); vis[v] = 1;
        }
    }
}

deque<int>dq;
int dis[maxn], inq[maxn];
int BFS(int s, int val)
{
    for (int x : vv) dis[x] = 1e8, inq[x] = 0;
    dis[s] = 0; dq.push_back(s);
    while (!dq.empty())
    {
        int u = dq.front(); dq.pop_front();
        if (inq[u]) continue;
        inq[u] = 1;
        for (auto x : E[u])
        {
            if (dis[x.fir] > dis[u] + x.sec)
            {
                dis[x.fir] = dis[u] + x.sec;
                if (inq[x.fir]) continue;
                x.sec == 1 ? dq.push_back(x.fir) : dq.push_front(x.fir);
            }
        }
    }
    int res = 0;
    for (int x : vv) res = max(res, dis[x]), ans[x] = val + dis[x];
    return res;
}
int main()
{
	freopen("graph.in", "r", stdin);
    freopen("graph.out", "w", stdout);
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].pb(v); G[v].pb(u);
        E[u].pb(make_pair(v, 1));
        E[v].pb(make_pair(u, 0));
    }
    int now = 0;
    for (int i = 1; i <= n; i++) 
    {
        if (vis[i]) continue;
        bfs(i); 
        int mx = -1, st = 0;
        for (int x : vv) 
        {
            int res = BFS(x, 0);
            if (mx < res) {mx = res; st = x;}
        }
        BFS(st, now);
        now += mx + 1;
    }
    for (int i = 1; i <= n; i++) printf("%d%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}
