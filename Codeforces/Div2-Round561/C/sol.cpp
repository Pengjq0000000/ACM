#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL a[maxn], b[maxn];
vector<LL>v;
map<LL, int>id;
LL sum[maxn];
bool cmp(LL a, LL b) {return abs(a) < abs(b);}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%lld", &a[i]);
		a[i] *= 2;
		v.pb(a[i]);
		v.pb(a[i]*2); v.pb(a[i]/2);
		v.pb(-1*a[i]*2); v.pb(-1*a[i]/2);
	}
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	int t = 0;
	for (LL x : v) id[x] = ++t;
	for (int i = 1; i <= n; i++) sum[id[a[i]]]++;
	for (int i = 1; i <= t; i++) sum[i] += sum[i - 1];
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		LL num = abs(a[i]);
		ans += sum[id[2 * num]] - sum[id[num / 2] - 1];
		ans += sum[id[-num / 2]] - sum[id[-num * 2] - 1];
	}
	printf("%lld\n", (ans - n) / 2);
	return 0;
}
