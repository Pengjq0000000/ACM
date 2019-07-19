#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const LL inv2 = 500000004;
const int maxn = 1007;
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = MOD(res * base);
        base = MOD(base * base);
        b >>= 1;
    }
    return res;
}
LL inv(LL x) {return ksm(x, mod - 2);}
LL a[maxn], c[maxn], sqra[maxn];
int main()
{
    int n;
	while (scanf("%d", &n) != EOF)
    {
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sqra[i] = MOD(a[i] * a[i]), c[i] = 1;
        for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            {
                if (j == i) continue;
                c[i] = MOD(c[i] * MOD(MOD(sqra[j] - sqra[i]) + mod));
            }
        LL ans = 0;
        for (int i = 1; i <= n; i++)
            ans = MOD(ans + MOD(inv(c[i]) * inv(a[i])));
        ans = MOD(ans * inv2);
        printf("%lld\n", ans);
    }
	return 0;
}
