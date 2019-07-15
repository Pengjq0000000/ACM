#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL ans = 1;
int k;
int main()
{
	scanf("%d", &k);
    for (int i = 1; i <= k; i++)
    {
        ans+=(1ll<<i);
    }
    printf("%lld\n", ans);
	return 0;
}
