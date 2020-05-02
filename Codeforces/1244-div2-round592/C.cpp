#include<bits/stdc++.h>
#define ll long long
using namespace std;

int main()
{
    ll n, p, w, d; scanf("%lld%lld%lld%lld", &n, &p, &w, &d);
    ll x = 0, y = 0, z = 0;
    if (w < d)
    {
        while ((p - x * w) % d && x <= d) x++;
        y = (p - x * w) / d;
        z = n - x - y;
    }    
    else 
    {
        while ((p - y * d) % w && y <= w) y++;
        x = (p - y * d) / w;
        z = n - x - y;
    }
    if (x * w + y * d != p || x < 0 || y < 0 || z < 0) puts("-1");
    else printf("%lld %lld %lld\n", x, y, z);
    return 0;
}