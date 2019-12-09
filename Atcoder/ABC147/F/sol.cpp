#include<bits/stdc++.h>
#define ll long long
using namespace std;
struct line
{
    ll l, r;
    bool operator < (const line &rhs) const 
    {
        return r < rhs.l;
    } 
};
unordered_map<int, set<line>>eq;
void add(int ind, ll l, ll r)
{
    line x = {l, r};
    while (1)
    {
        auto it = eq[ind].find(x);
        if (it == eq[ind].end()) break;
        x = {min(x.l, it->l), max(x.r, it->r)};
        eq[ind].erase(it);
    }
    eq[ind].insert(x);
}
int main()
{
    ll N, X, D; scanf("%lld%lld%lld", &N, &X, &D);
    if (!D) {printf("%lld\n", X ? N + 1 : 1ll); return 0;}
    if (D < 0) 
    {
        X += (N - 1) * D;
        D = -D;
    }
    for (ll k = 0; k <= N; k++) 
    {
        int ind = (k * X) % D;
        if (ind < 0) ind += D;
        ll det = (ind - k * X) / D;
        add(ind, k * (k - 1) / 2 - det, k * (2 * N - k - 1) / 2 - det);
    }
    ll ans = 0;
    for (auto item : eq)
        for (auto x : item.second) ans += x.r - x.l + 1;
    printf("%lld\n", ans);
    return 0;
}