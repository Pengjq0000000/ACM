#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
const int M = 1 << 8;
char s[10]; 
int cal(int a, int b)
{
	if (s[0] == 'A') return a & b;
	if (s[0] == 'O') return a | b;
	if (s[0] == 'X') return a ^ b;
}

LL dp[maxn], g[M + 10][M + 10], tmp[maxn][M + 10];
int w[maxn], vis[M + 10];
vector<int>E[maxn];

void dfs(int u)
{
	int high = w[u] / M;
	int low = w[u] % M;
	for (int i = 0; i < M; i++) //update dp
	{
		if (!vis[i]) continue;
		dp[u] = max(dp[u], g[i][low] + (cal(high, i) << 8));
	}
	vis[high]++;
	for (int i = 0; i < M; i++) // update g
	{
		tmp[u][i] = g[high][i];
		g[high][i] = max(g[high][i], dp[u] + cal(low, i));
	}
	for (int v : E[u]) dfs(v);
	vis[high]--;
	for (int i = 0; i < M; i++) g[high][i] = tmp[u][i];
}
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) dp[i] = 0, E[i].clear();
		scanf(" %s", s);
		for (int i = 1; i <= n; i++) scanf("%d", &w[i]);
		for (int i = 2; i <= n; i++) 
		{
			int x; scanf("%d", &x);
			E[x].pb(i);
		}
		dfs(1);
		LL ans = 0;
		for (int i = 1; i <= n; i++) ans = MOD(ans + (dp[i] + w[i]) * i);
		printf("%lld\n", ans);
	}	
	return 0;
}

