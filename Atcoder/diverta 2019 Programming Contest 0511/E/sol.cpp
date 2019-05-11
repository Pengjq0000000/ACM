#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e6 + 10;
int n, a[maxn], cnt[maxn], vis[maxn];
vector<int>pos[maxn];
LL cal(int x)
{
	LL dpzero = 1, dpx = 0;
	int now = 0, lastp = 1;
	while (now < (int)pos[x].size())
	{
		int thisp = pos[x][now];
		dpzero = MOD(dpzero + MOD(dpx * (cnt[thisp] - cnt[lastp - 1])));
		dpx = MOD(dpx + dpzero);
		lastp = thisp;
		now++;
	}
	if (a[n] == 0) return dpx;
	else return dpzero;
}
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
		a[i] ^= a[i - 1];
		pos[a[i]].pb(i);
		cnt[i] = cnt[i - 1] + (a[i] == 0);
	}
	LL ans = 0;
	if (a[n] != 0)
	{
		ans = MOD(ans + cal(a[n]));
	}
	else
	{
		for (int i = 1; i <= n; i++)
		{
			if (vis[a[i]] || a[i] == 0) continue;
			vis[a[i]] = 1;
			ans = MOD(ans + cal(a[i]));
		}
		LL anszero = 1;
		for (int i = 1; i < cnt[n]; i++) anszero = MOD(anszero * 2);
		ans = MOD(ans + anszero);
	}
	printf("%lld\n", ans);
	return 0;
}
