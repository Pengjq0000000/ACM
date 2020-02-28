#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 3e5 + 7;
struct node{ll suml, maxd;};
stack<node>stk;
multiset<ll>s;
ll c[MAXN], d[MAXN];
ll suml[MAXN], dd[MAXN];
int main()
{
    int n, a; scanf("%d%d", &n, &a);
    for (int i = 1; i <= n; i++) scanf("%lld%lld", &d[i], &c[i]), c[i] = a - c[i];
    for (int i = 1; i <= n; i++)
    {
        dd[i - 1] = (d[i + 1] - d[i]) * (d[i + 1] - d[i]);
        suml[i] = suml[i - 1] + c[i];
    }
    ll nowd = 0, ans = max(0ll, c[n]);
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, c[i]);
        if (s.size()) ans = max(ans, suml[i + 1] - *s.begin());
        ll temp = suml[i]; nowd = dd[i];
        while (stk.size() && stk.top().maxd <= nowd) 
        {
            temp = min(temp, stk.top().suml);
            s.erase(s.find(stk.top().suml + stk.top().maxd));
            stk.pop();
        }
        stk.push({temp, nowd});
        s.insert(temp + nowd);
    }
    printf("%lld\n", ans);
    return 0;
}