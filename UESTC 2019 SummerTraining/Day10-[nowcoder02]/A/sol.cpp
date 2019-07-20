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
LL ans = 1;
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        if (n == 1 && m == 0) ans *= 1;
        else if (m == 0) ans *= 0;
        else if (m > 0) ans = MOD(ans * ksm(n - 1, mod - 2)); 
        printf("%lld\n", ans);
    }
	return 0;
}
