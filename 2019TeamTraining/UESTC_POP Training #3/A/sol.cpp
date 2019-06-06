#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL w[maxn];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		LL sqrsum = 0, abssum = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld", &w[i]);
			sqrsum += w[i] * w[i];
			abssum += abs(w[i]);
		}
		LL p = sqrsum * n - abssum * abssum, q = n;
		LL gcd = __gcd(p, q);
		p /= gcd; q /= gcd;
		printf("%lld/%lld\n", p, q);
	}
	return 0;
}
