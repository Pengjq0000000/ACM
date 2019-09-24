#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
	LL x, y, z; scanf("%lld%lld%lld", &x, &y, &z);
	LL a = x % z, b = y % z;
	LL ans = x / z + y / z;
	if (a + b >= z)
	{
		ans++;
		printf("%lld %lld\n", ans, z - max(a, b));
	}
	else printf("%lld 0\n", ans);
	return 0;
}
