#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
__int128_t l, r;
int main()
{

	LL aa, bb, xx, yy; 
    while (scanf("%lld%lld%lld%lld", &xx, &aa, &yy, &bb) != EOF)
    {
        l = xx;
        l *= bb;
        r = yy;
        r *= aa;
        if (l < r) puts("<");
        else if (l > r) puts(">");
        else puts("=");
    }
	return 0;
}
