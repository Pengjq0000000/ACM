#include<bits/stdc++.h>
#define LL long long
#define MOD(x) ((x) % mod)
#define mod 1000000007
using namespace std;
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

int main()
{
    LL inv2 = ksm(2, mod - 2), inv6 = ksm(6, mod - 2);
    int T; scanf("%d", &T);
    while (T--)
    {
        LL n; scanf("%lld", &n);
        LL tmp1 = MOD(MOD(MOD(n * n) * MOD((n + 1) * (n + 1))) * MOD(inv2 * MOD(inv2 * inv2)));
        LL tmp2 = MOD(MOD(n * inv2) * MOD(MOD(MOD(n * (n + 1)) * (n * 2 + 1)) * inv6));
        LL tmp3 = MOD(MOD((n + 1) * inv2) * MOD(MOD(n * (n + 1)) * inv2));
        LL ans = MOD(tmp2 + tmp3 - tmp1 + mod);
        printf("%lld\n", ans);
    }

}