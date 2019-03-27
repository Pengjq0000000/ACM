#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 507;
struct node 
{
	int v, w;
	node(int v, int w) : v(v), w(w) {}
	node() {}
	bool operator < (const node &rhs) const {return w > rhs.w;}
};
vector<node>E[maxn];
priority_queue<node>q;
int dis[maxn], vis[maxn], dp[maxn], ways[maxn], val[maxn], pre[maxn];
int main()
{
	int n, m, s, t; scanf("%d%d%d%d", &n, &m, &s, &t);
	for (int i = 0; i < n; i++) scanf("%d", &val[i]);
	while (m--)
	{
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		E[u].pb(node(v, w)); E[v].pb(node(u, w));
	}
	MEM(dis, 0x3f3f3f3f);
	for (int i = 0; i < n; i++) ways[i] = 1, pre[i] = -1;
	q.push(node(t, 0)); dis[t] = 0; dp[t] = val[t];
	while (!q.empty())
	{
		int u = q.top().v; q.pop();
		if (vis[u]) continue; vis[u] = 1;
		for (node tmp : E[u])
		{
			int v = tmp.v;
			if (dis[u] + tmp.w == dis[v]) 
			{
				ways[v] += ways[u];
				if (dp[v] < dp[u] + val[v])
				{
					dp[v] = dp[u] + val[v];
					pre[v] = u;
				}
			}
			else if (dis[u] + tmp.w < dis[v])
			{
				dis[v] = dis[u] + tmp.w;
				ways[v] = ways[u]; dp[v] = val[v];
				if (dp[v] < dp[u] + val[v])
				{
					dp[v] = dp[u] + val[v];
					pre[v] = u;
				}
				q.push(node(v, dis[v]));
			}
		}
	}
	printf("%d %d\n", ways[s], dp[s]);
	int x = s;
	while (pre[x] != -1) {printf("%d ", x); x = pre[x];}
	printf("%d\n", x);
	return 0;
}
