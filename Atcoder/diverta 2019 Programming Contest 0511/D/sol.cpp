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
	LL n; scanf("%lld", &n);
	LL ans = 0;
	for (LL x = 1; x <= sqrt(n + 0.5); x++)
	{
		LL m = n / x - 1;
		if (m == 0) continue;
		if ((n / m) == (n % m)) ans += m;
	}
	printf("%lld\n", ans);
	return 0;
}
