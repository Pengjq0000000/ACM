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
	LL n, a, b; scanf("%lld%lld%lld", &n, &a, &b);
    printf("%lld\n", min(n * a, b));
	return 0;
}
