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
	LL L, R; scanf("%lld%lld", &L, &R);
    if (R - L + 1 >= 2019)  {puts("0"); return 0;}
    LL ans = 1e18;
    for (LL x = L; x < R; x++)
        for (LL y = x + 1; y <= R; y++)
        {
            ans = min(ans, ((x % 2019) * (y % 2019)) % 2019);
        }
    printf("%lld\n", ans);
	return 0;
}
