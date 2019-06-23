#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define INF 1e18
#define pil pair<int, long long>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 1e6 + 7;
int n, m, k;
bool vis[maxn];
int head[maxn], tot = 0;
struct node{int v, next; LL w;}e[maxn << 1];
void add(int u, int v, LL w)
{
	++tot; e[tot].v = v; e[tot].w = w; 
	e[tot].next = head[u]; head[u] = tot;
}
LL ans;
void dfs(int u, int cnt, LL dis)
{
	if (dis >= ans) return;
	if (u == n)
	{
		if (cnt == k) ans = min(ans, dis);
		return;
	}
	if (cnt >= k) return;
	for (int i = head[u]; i; i = e[i].next)
	{
		if (vis[e[i].v]) continue;
		vis[e[i].v] = 1;
		dfs(e[i].v, cnt + 1, dis + e[i].w);
		vis[e[i].v] = 0;
	}
}

int main()
{
	scanf("%d%d%d", &n, &m, &k);
	if (k > m || k >= n || k > 5) {puts("-1"); return 0;}
	for (int i = 1; i <= m; i++)
	{
		int u, v; LL w; scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w); add(v, u, w);
	}
	ans = INF;
	vis[1] = 1;
	dfs(1, 0, 0);
	if (ans >= INF) puts("-1");
	else printf("%lld\n", ans);
	return 0;
}