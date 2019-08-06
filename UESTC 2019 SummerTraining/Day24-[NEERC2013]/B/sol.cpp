#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
set<int>E[maxn], now;
vector<int>G[maxn];
int dis[maxn], vis[maxn];
int n, k;
LL A, B;
queue<int>q;
void BFS1(int s)
{
    for (int i = 1; i <= n; i++) vis[i] = 0, dis[i] = 1e9;
    vis[s] = 1; dis[s] = 0;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : G[u])
        {
            if (vis[v]) continue;
            q.push(v); vis[v] = 1;
            dis[v] = dis[u] + 1;
        }
    }
    //for (int i = 1; i <= n; i++) printf("%d ", dis[i]); puts("");
}

vector<int>t;
void BFS2(int s)
{
    for (int i = 2; i <= n; i++) now.insert(i), dis[i] = 1e9;
    q.push(s); dis[s] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        t.clear();
        for (int v : now)
        {
            if (E[u].count(v)) continue;
            q.push(v); 
            dis[v] = dis[u] + 1;
            t.pb(v);
        }
        for (int v : t) now.erase(v);
    }
    //for (int i = 1; i <= n; i++) printf("%d ", dis[i]); puts("");
}
int main()
{
	freopen("b.in", "r", stdin);
    scanf("%d%d%lld%lld", &n, &k, &A, &B);
    for (int i = 1, u, v; i <= k; i++)
    {
        scanf("%d%d", &u, &v);
        E[u].insert(v); E[v].insert(u);
        G[u].pb(v); G[v].pb(u);
    }
    LL ans = 0;
    if (!E[1].count(n))
    {
        BFS1(1); ans = (LL)dis[n] * A;
        ans = min(B, ans);
    }
    else
    {
        BFS2(1); ans = (LL)dis[n] * B;
        ans = min(A, ans);
    }
    printf("%lld\n", ans);
	return 0;
}
