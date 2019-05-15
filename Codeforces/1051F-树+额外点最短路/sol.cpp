#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 37;
int n, m;
struct node
{
	int u, v, next; LL w;
	node(int v, LL w) : v(v), w(w) {}
	node() {}
	bool operator < (const node &rhs) const
	{
		return w > rhs.w;
	}
}e[maxn << 1]; 
int head[maxn], tot = 1;
bool tedge[maxn << 1];
vector<int> Sp;
void add(int u, int v, LL w)
{
	++tot;
	e[tot].u = u; e[tot].v = v; e[tot].w = w;
	e[tot].next = head[u]; head[u] = tot;
}

int totsp = 0;
LL dis[maxn][25];
bool vis[maxn];
priority_queue<node>q;
void dijkstra(int s, int id)
{
	for (int i = 1; i <= n; i++) vis[i] = 0, dis[i][id] = 1e16;
	q.push(node(s, 0));
	dis[s][id] = 0;
	while (!q.empty())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (int i = head[u]; i; i = e[i].next)
		{
			int v = e[i].v;
			if (dis[u][id] + e[i].w < dis[v][id])
			{
				dis[v][id] = dis[u][id] + e[i].w;
				q.push(node(v, dis[v][id]));
			}
		}
	}
}

int f[maxn], dep[maxn], father[maxn][21];
LL dist[maxn][25];
int find(int x)
{
	if (x == f[x]) return f[x];
	return f[x] = find(f[x]);
}
void dfs(int u, int fa)
{
	for (int i = 1; i <= 18; i++)
	{
		father[u][i] = father[father[u][i - 1]][i - 1];
		dist[u][i] = dist[u][i - 1] + dist[father[u][i - 1]][i - 1];
	}
	for (int i = head[u]; i; i = e[i].next)
	{
		int v = e[i].v;
		if (!tedge[i] || v == fa) continue;
		dep[v] = dep[u] + 1;
		father[v][0] = u;
		dist[v][0] = e[i].w;
		dfs(v, u);
	}
}
LL treequery(int x, int y)
{
	LL res = 0;
	if (dep[x] > dep[y]) swap(x, y);
	for (int i = 18; i >= 0; --i)
	{
		if (dep[x] < dep[y] && dep[father[y][i]] >= dep[x])
		{
			res += dist[y][i];
			y = father[y][i];
		}
	} 
	for (int i = 18; i >= 0; --i)
	{
		if (father[x][i] != father[y][i])
		{
			res += dist[x][i] + dist[y][i];
			x = father[x][i]; y = father[y][i];
		}
	}
	if (x != y) res += dist[x][0] + dist[y][0]; 
	return res;
}
void Init()
{
	for (int i = 1; i <= n; i++) f[i] = i;
	int cnt = 0;
	for (int i = 2; i <= tot; i += 2)
	{
		int u = e[i].u, v = e[i].v;
		int fu = find(u), fv = find(v);
		if (fu != fv)
		{
			++cnt;
			f[fu] = fv;
			tedge[i] = tedge[i ^ 1] = 1; 
		}
		if (cnt == n - 1) break;
	}
	for (int i = 2; i <= tot; i += 2)
	{
		if (!tedge[i]) Sp.pb(e[i].u);
	}
	sort(Sp.begin(), Sp.end());
	Sp.erase(unique(Sp.begin(), Sp.end()), Sp.end());
	dep[1] = 1;
	dfs(1, 0);
	for (int x : Sp) dijkstra(x, ++totsp);
}
int main()
{
	scanf("%d%d", &n, &m);
	while (m--)
	{
		int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	Init();
	//printf("size:%d\n", (int)Sp.size());
	int q; scanf("%d", &q);
	while (q--)
	{
		int u, v; scanf("%d%d", &u, &v);
		
		LL ans = treequery(u, v);
		for (int i = 1; i <= totsp; i++)
		{
			if (dis[u][i] >= 1e16 || dis[v][i] >= 1e16) continue;
			ans = min(ans, dis[u][i] + dis[v][i]);
		}
		

		//dijkstra(u, 1);
		//LL ans = dis[v][1];
		printf("%lld\n", ans);
	}
	return 0;
}
