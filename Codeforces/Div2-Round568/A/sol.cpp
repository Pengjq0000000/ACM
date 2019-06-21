#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL a[10];
int main()
{
	for (int i = 1; i <= 3; i++) scanf("%lld", &a[i]);
	LL d; scanf("%lld", &d);
	sort(a + 1, a + 1 + 3);
	LL ans = 0;
	if (a[2] - a[1] < d) ans += (d - (a[2] - a[1]));
	if (a[3] - a[2] < d) ans += (d - (a[3] - a[2]));
	printf("%lld\n", ans);
	return 0;
}
