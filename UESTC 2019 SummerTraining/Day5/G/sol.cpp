#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define pdd pair<double, double>
#define fir first
#define sec second
#define mp(a,b) make_pair(a,b)
#define pb push_back
using namespace std;
const int maxn = 1007;
int a[maxn], b[maxn];
bool done[maxn];
map<pii, int>vis;
vector<pdd>pp;
int main()
{
	int n; scanf("%d", &n);
	long long ans = 1;
	for (int i = 1; i <= n; i++)
	{
		scanf("%d%d", &a[i], &b[i]);
		pii now = mp(a[i], b[i]);
		if (vis.count(now)) 
		{
			done[i] = 1;
			continue;
		}
		vis[now] = 1;
		ans++;
        pp.clear();
		for (int j = 1; j < i; j++)
		{
			if (done[j]) continue;
			double a1 = a[i], a2 = a[j], b1 = b[i], b2 = b[j];
			double up = a2 * a2 + b2 - a1 * a1 - b1;
			double down = 2 * (a2 - a1);
			if (down == 0) continue;
			double x = up / down;
			double y = (x - a1) * (x - a1) + b1;
			pp.pb(mp(x, y));
		}
        sort(pp.begin(), pp.end());
        int sz = pp.size();
        if (sz > 0) ans++;
        for (int i = 1; i < sz; i++)
        {
            if (abs(pp[i - 1].fir - pp[i].fir) + abs(pp[i - 1].sec - pp[i].sec) < (1e-8)) continue;
            ans++;
        }
	}
	printf("%lld\n", ans);
}