#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
LL suf[maxn];
int main()
{
	int n, k; scanf("%d%d", &n, &k);
	for (int i = 1; i <= n; i++) scanf("%lld", &suf[i]);
	for (int i = n; i >= 1; i--) suf[i] += suf[i + 1];
	sort(suf + 2, suf + 1 + n, greater<LL>());
	LL ans = 0;
	for (int i = 1; i <= k; i++) ans += suf[i];
	printf("%lld\n", ans);
	return 0;
}
