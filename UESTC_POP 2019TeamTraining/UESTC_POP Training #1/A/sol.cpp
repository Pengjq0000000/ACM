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
	int T; scanf("%d", &T);
	while (T--)
	{
		LL n; scanf("%lld", &n);
		LL ans = -1;
		if (n % 3 == 0) ans = max(ans, (n / 3 * n / 3 * n / 3));
		if (n % 6 == 0) ans = max(ans, (n / 6 * n / 2 * n / 3));
		if (n % 4 == 0) ans = max(ans, (n / 2 * n / 4 * n / 4));
		printf("%lld\n", ans);
	}
	return 0;
}
