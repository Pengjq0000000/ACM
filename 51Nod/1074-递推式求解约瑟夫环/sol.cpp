#include<bits/stdc++.h>
#define ll long long
#define bound 1000000
using namespace std;
const int maxn = 1e6 + 7;
// f(n) = (f(n - 1) + k - 1) % n + 1
int f[maxn];
int main()
{
    ll N, k; scanf("%lld%lld", &N, &k);
    f[2] = 2 - (k + 1) % 2;
    ll n = 2, fn = 2 - (k + 1) % 2;
    while (n < N)
    {
        ll x = min(N - n, (n - fn + 1) / (k - 1));
        n += x; fn += k * x;
        assert(fn - 1 <= n);
        while (n < N) 
        {
            if (fn - 1 >= n) break;
            n++, fn += k;
        }
        fn = (fn - 1) % n + 1;
    }
    printf("%lld\n", fn);
    return 0;
}