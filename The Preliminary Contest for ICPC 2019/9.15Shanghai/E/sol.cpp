#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
LL ksm(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = MOD(res * a);
        a = MOD(a * a);
        b /= 2;
    }
    return res;
}
LL fac[maxn], inv[maxn];
void init()
{
    fac[0] = 1;
    for (int i = 1; i <= 200000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[200000] = ksm(fac[200000], mod - 2);
    for (int i = 200000; i >= 1; i--) inv[i - 1] = MOD(inv[i] * i);
}
LL C(int n, int m)
{
    return MOD(fac[n] * MOD(inv[m] * inv[n - m]));
}
int main()
{
    init();
    int T; scanf("%d", &T);
    while (T--)
    {
        LL n, m; scanf("%lld%lld", &n, &m);
        LL ans = 0;
        for (int i = 0; i <= m / 2; i++)
        {
            ans = MOD(ans + MOD(C(m / 2, i) * ksm(m - 2 * i, n)));
        }
        LL tmp = ksm(2, m / 2);
        ans = MOD(ans * ksm(tmp, mod - 2));
        printf("%lld\n", ans);
    }
    return 0;
}
