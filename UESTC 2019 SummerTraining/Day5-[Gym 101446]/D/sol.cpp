#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int main()
{
	int k;
	scanf("%d",&k);
	long long ans = 2;
	while (k % 2 == 0)
	{
		ans = MOD(ans * ans);
		k /= 2;
	}
	printf("%lld\n", MOD(ans - 1 + mod));
	return 0;
}