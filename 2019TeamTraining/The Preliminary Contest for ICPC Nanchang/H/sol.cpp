#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL ksm(LL a, LL b)
{
	LL res = 1, base = a;
	while (b)
	{
		if (b & 1) res = MOD(res * base);
		base = MOD(base * base);
		b /= 2;
	}
	return res;
}
int main()
{
	LL n; scanf("%lld", &n);
	LL ans;
	if (n == 1) ans = 1;
	else
	{
		ans = ksm(3, n - 2);
		ans = MOD(ans * 4);
	}
	printf("%lld\n", ans);
	return 0;
}
