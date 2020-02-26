#include<bits/stdc++.h>
#define ll long long
#define pll pair<ll, ll>
#define fir first
#define sec second
using namespace std;
const int MAXN = 2e5 + 7;
pll p[MAXN];
multiset<ll>X, Y;
inline ll getans() 
{
    return (*X.rbegin() - *X.begin()) * (*Y.rbegin() - *Y.begin());
}
int main()
{   
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &p[i].fir, &p[i].sec);
        if (p[i].fir > p[i].sec) swap(p[i].fir, p[i].sec);
        X.insert(p[i].fir); Y.insert(p[i].sec);
    }
    sort(p + 1, p + 1 + n);
    ll ans = getans();
    for (int i = 1; i < n; i++)
    {
        X.erase(X.find(p[i].fir)); Y.insert(p[i].fir);
        Y.erase(Y.find(p[i].sec)); X.insert(p[i].sec);
        ans = min(ans, getans());
    }
    printf("%lld\n", ans);
    return 0;
}