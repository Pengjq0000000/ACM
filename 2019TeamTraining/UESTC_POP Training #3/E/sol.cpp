#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
#define pii pair<int, int>
#define mkpair(x, y) make_pair(x, y)
#define fir first
#define sec second
using namespace std;
pii p[1007];
map<pair<int, int>, int> cnt;
LL mi[1000007];
int main()
{
	int T; scanf("%d", &T);
	mi[0] = 1;
	for (int i = 1; i <= 1000000; i++) mi[i] = MOD(mi[i - 1] * 2);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d%d", &p[i].fir, &p[i].sec);
		}
		sort(p + 1, p + 1 + n);
		LL ans = 0;
		for (int i = 1; i < n; i++)
		{
			cnt.clear();
			for (int j = i + 1; j <= n; j++)
			{
				int pp = p[i].fir - p[j].fir;
				int qq = p[i].sec - p[j].sec;
				int gcd = __gcd(pp, qq);
				if (gcd) {pp /= gcd; qq /= gcd;}
				cnt[make_pair(pp, qq)]++;
			}
			int tmp = cnt[make_pair(0, 0)];
			for (auto iter = cnt.begin(); iter != cnt.end(); iter++)
			{
				int num = iter->sec;
				LL res = MOD(mi[num] - 1 + mod);
				if (iter->fir != (make_pair(0, 0))) res = MOD(res * mi[tmp]);
				//printf("%d %d: %lld\n",iter->fir.fir, iter->fir.sec, res);
				ans = MOD(ans + res + mod);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}
