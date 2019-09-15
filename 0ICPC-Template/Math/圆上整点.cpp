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
