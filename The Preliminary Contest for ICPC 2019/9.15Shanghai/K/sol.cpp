#include<bits/stdc++.h>
#define LL long long
#define ll long long
#define pii pair<LL, LL>
using namespace std;
const int N = 1e5 + 5;
vector<pair<pii, pii> >ans;
LL a[N];
int tot;
vector<pii> solve(LL r)
{
    vector<pii>res;
    LL i, d, S, j, cc = 0;  S = sqrt(r);
    for (i = 1; i <= S; i++)
        if (r % i == 0) 
        {
            a[++cc] = i; a[++cc] = 2ll * i;
            if (r / i != i) a[++cc] = r / i,
            a[++cc] = 2ll * (r / i);
        }
    sort(a + 1, a + cc + 1); 
    tot = unique(a + 1, a + cc + 1) - a - 1;
    for (j = 1; j <= tot; j++) 
    {
        d = a[j]; 
        for (i = 1; 1ll * i * i * d <= r; i++) 
        {
            LL x = r - i * i * d; if (x <= 0 || x >= r) continue;
            if (__gcd(1ll * r + x, 1ll * r - x) != d) continue;
            ll w = 1ll * r * r - 1ll * x * x;
            ll s = sqrt(w); 
            if (s * s == w)
            {
                res.push_back({x, s});
                res.push_back({-x, -s});
                res.push_back({x, -s});
                res.push_back({-x, s});
                //printf("%lld %lld %lld\n", x, s, r);
            }
        }
    }
    sort(res.begin(), res.end());
    res.erase(unique(res.begin(), res.end()), res.end());
    return res;
}
LL dis(pii x, pii y)
{
    return (x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second); 
}
int main() 
{
    int T; scanf("%d", &T);
    while (T--)
    {
        ans.clear();
        LL a, b, c; scanf("%lld%lld%lld", &a, &b, &c);
        vector<pii>pa = solve(a);
        vector<pii>pb = solve(b);
        pa.push_back({0, a}); pa.push_back({a, 0}); pa.push_back({0, -a}); pa.push_back({-a, 0});
        pb.push_back({0, b}); pb.push_back({b, 0}); pb.push_back({0, -b}); pb.push_back({-b, 0});
        for (pii nodea : pa)
            for (pii nodeb : pb)
            {
                if (dis(nodea, nodeb) == c * c) 
                {
                    ans.push_back({nodea, nodeb});
                }
            }
        
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        printf("%d\n", (int)ans.size());
        sort(ans.begin(), ans.end());
        for (auto x : ans)
        {
            printf("%lld %lld %lld %lld\n", x.first.first, x.first.second, x.second.first, x.second.second);
        }
    }
    return 0;
}
