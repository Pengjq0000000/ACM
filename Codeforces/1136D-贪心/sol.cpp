#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
set<int> E[maxn], now;
int p[maxn];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) scanf("%d", &p[i]);
	while (m--)
	{
		int u, v; scanf("%d%d", &u, &v);
		E[u].insert(v);
	}
	int sz = 0, ans = 0;
	now.insert(p[n]); sz++;
	for (int i = n - 1; i >= 1; --i)
	{
		int cnt = 0;
		for (int u : E[p[i]]) if (now.count(u)) cnt++;
		if (cnt == now.size()) ans++;
		else {now.insert(p[i]); sz++;}
	}
	printf("%d\n", ans);
	return 0;
}
