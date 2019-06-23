#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
vector<int>E[maxn], G[maxn];
int n, m, k, s;
int dis[maxn][105];
bool vis[maxn];
queue<int>q;
void BFS(int col)
{
	MEM(vis, 0);
	for (int u : G[col]) {q.push(u); vis[u] = 1; dis[u][col] = 0;}
	while (!q.empty())
	{
		int u = q.front(); q.pop();
		for (int v : E[u])
		{
			if (vis[v]) continue;
			dis[v][col] = dis[u][col] + 1;
			vis[v] = 1;
			q.push(v);
		}
	}
	//for (int i = 1; i <= n; i++) printf("%d ", dis[i][col]);
	//puts("");
}
int main()
{
	MEM(dis, 0x3f3f3f3f);
	scanf("%d%d%d%d", &n, &m, &k, &s);
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		G[x].pb(i);
	}
	while (m--)
	{
		int u, v; scanf("%d%d", &u, &v);
		E[u].pb(v); E[v].pb(u);
	}
	for (int i = 1; i <= k; i++) BFS(i);
	for (int i = 1; i <= n; i++)
	{
		sort(dis[i] + 1, dis[i] + 1 + k);
		LL ans = 0;
		for (int j = 1; j <= s; j++) ans += dis[i][j];
		printf("%lld ", ans);
	}
	return 0;
}
