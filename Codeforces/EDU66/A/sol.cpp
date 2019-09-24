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
		LL n, k; scanf("%lld%lld", &n, &k);
		LL cnt = 0;
		while (n)
		{
			if (n % k) cnt += n % k, n -= n % k;
			else n /= k, cnt++;
		}
		printf("%lld\n", cnt);
	}
	return 0;
}
