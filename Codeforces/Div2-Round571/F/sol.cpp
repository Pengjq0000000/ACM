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
const int maxn = 2e6 + 7;
struct node{int v, next;}e[maxn << 1];
int head[maxn], tot = 1;
int used[maxn << 1];
vector<int>vv;
void add(int u, int v) {e[++tot] = {v, head[u]}; head[u] = tot;}
void dfs(int u)
{
	for (int &i = head[u]; i; i = e[i].next)
	{
		if (used[i]) continue;
		used[i] = used[i ^ 1] = 1;
		dfs(e[i].v);
	}
	vv.pb(u);
}

int deg[maxn];
vector<int>q[maxn];
vector<pii>ans;
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v; scanf("%d%d", &u, &v);
		add(u, v); add(v, u);
		deg[u]++; deg[v]++;
	}
	for (int i = 1; i <= n; i++) if (deg[i] & 1)
	{
		add(n + 1, i); add(i, n + 1);
		deg[n + 1]++;
	}
	int cnt = 0;
	if (deg[n + 1] > 0)
	{
		dfs(n + 1);
		for (int x : vv) if (x == n + 1) ++cnt; else q[cnt].pb(x);
		// printf("%d\n", cnt);
		// for (int x : vv) printf("%d ", x);
		// puts("");
		vv.clear();
	}
	for (int i = 1; i <= n; i++) 
	{
		dfs(i);
		if (vv.size() > 1)
		{
			++cnt; for (int x : vv) q[cnt].pb(x);
			//for (int x : vv) printf("%d ", x); puts("");
		}
		vv.clear();
	}
	for (int now = 1; now <= cnt; now++)
	{
		int sz = q[now].size();
		if (sz == 0) continue;
		if (sz & 1)
		{
			ans.pb(make_pair(q[now][0], q[now][1]));
			for (int i = 1; i < sz; i += 2) ans.pb(make_pair(q[now][i], q[now][i + 1]));
		}
		else 
		{
			for (int i = 0; i < sz; i += 2) ans.pb(make_pair(q[now][i], q[now][i + 1]));
		}
	}
	printf("%d\n", (int)ans.size());
	for (pii edge : ans) printf("%d %d\n", edge.fir, edge.sec);
	return 0;
}
