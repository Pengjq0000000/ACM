#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 30010;
int n, m, k;
int dis[maxn], VIS[maxn];
struct Node{int u, v, next, w;}ee[maxn << 2], e[maxn << 2];
int HEAD[maxn], TOT;
void ADD(int u, int v, int w)
{
    ee[++TOT] = {u, v, HEAD[u], w};
    HEAD[u] = TOT;
}
int head[maxn], tot;
void add(int u, int v, int w)
{
    e[++tot] = {u, v, head[u], w};
    head[u] = tot;
}
priority_queue<pii, vector<pii>, greater<pii> >q;
pii f[maxn];
void dij(int s)
{
    for (int i = 1; i <= n; i++) dis[i] = 1e9, VIS[i] = 0;
    dis[s] = 0;
    q.push(make_pair(0, s));
    while (!q.empty())
    {
        int u = q.top().second; q.pop();
        if (VIS[u]) continue; VIS[u] = 1;
        for (int i = HEAD[u]; i; i = ee[i].next)
        {
            int v = ee[i].v;
            if (dis[v] > dis[u] + ee[i].w)
            {
                dis[v] = dis[u] + ee[i].w;
                q.push(make_pair(dis[v], v));
                f[v] = make_pair(u, ee[i].w);
            }
        }
    }
    for (int u = 2; u <= n; u++)
    {
        int v = f[u].first, w = f[u].second;
        add(u, v, w);
        add(v, u, w);
    }
}

int sz[maxn], son[maxn];
// son[u] u的儿子中最大的sz值
int all, rt; // init : all = n
int vis[maxn];
void getroot(int u, int fa)
{
	sz[u] = 1; son[u] = 0;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (v == fa || vis[v]) continue;
		getroot(v, u);
		sz[u] += sz[v];
		son[u] = max(son[u], sz[v]);
	}
	son[u] = max(son[u], all - sz[u]);
	if (!son[rt] || son[rt] > son[u]) rt = u;
}
pair<int, int>depth[maxn], t[maxn], ans;
int now_mxdep;
void dfs(int u, int fa, int d, int dep)
{
    if (depth[dep].first < d) depth[dep] = make_pair(d, 1);
    else if (depth[dep].first == d) depth[dep].second++;
    now_mxdep = max(now_mxdep, dep);
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa || vis[v]) continue;
        dfs(v, u, d + e[i].w, dep + 1);
    }
}
void cal(int u)
{
    for (int j = 0; j <= k; j++) depth[j] = {0, 0}, t[j] = {0, 0};
    t[0] = {0, 1};
	for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (vis[v]) continue;
        now_mxdep = 0;
        dfs(e[i].v, -1, e[i].w, 1);
        for (int j = 1; j <= min(k - 1, now_mxdep); j++)
        {
            if (ans.first < depth[j].first + t[k - 1 - j].first && depth[j].second * t[k - 1- j].second)
            {
                ans.first = depth[j].first + t[k - 1 - j].first;
                ans.second = depth[j].second * t[k - 1 - j].second;
            }
            else if (ans.first == depth[j].first + t[k - 1 - j].first)
            {
                ans.second += depth[j].second * t[k - 1 - j].second;
            }
        }
        for (int j = 0; j <= min(k, now_mxdep); j++)
        {
            if (depth[j].first > t[j].first) t[j] = depth[j];
            else if (depth[j].first == t[j].first) t[j].second += depth[j].second;
            depth[j].first = 0, depth[j].second = 0;
        }
    }
}
void DIV(int u)
{
	rt = 0; getroot(u, 0); u = rt;
	vis[u] = 1;
	cal(u);
	int totsz = all;
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (vis[v]) continue;
		all = sz[v] < sz[u] ? sz[v] : totsz - sz[u];
		DIV(v);
	}
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++) HEAD[i] = head[i] = 0;
        TOT = 0; tot = 0;
        for (int i = 1, u, v, w; i <= m; i++)
        {
            scanf("%d%d%d", &u, &v, &w);
            ADD(u, v, w); ADD(v, u, w);
        }
        dij(1);
        for (int i = 1; i <= n; i++) vis[i] = 0;
        all = n; ans.first = ans.second = 0;
        DIV(1);
        printf("%d %d\n", ans.first, ans.second);
    }
    return 0;
}
