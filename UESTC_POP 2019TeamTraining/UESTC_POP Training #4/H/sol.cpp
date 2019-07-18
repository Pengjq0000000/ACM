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
	LL n, k;
	int cas = 0;	
	while (scanf("%lld%lld", &n, &k) != EOF)
	{
		n = MOD(n);
		printf("Case #%d: %lld\n", ++cas, ksm(n, k));
	}
	
	return 0;
}
