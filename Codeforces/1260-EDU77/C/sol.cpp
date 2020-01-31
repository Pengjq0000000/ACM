#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ll r, b, k; scanf("%lld%lld%lld", &r, &b, &k);
        ll g = __gcd(r, b);
        r /= g; b /= g;
        if (r > b) swap(r, b);
        if ((k - 1) * r + 1 < b) puts("REBEL");
        else puts("OBEY");
    }
    return 0;
}