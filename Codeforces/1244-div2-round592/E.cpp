#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
int a[MAXN], b[MAXN];
ll num[MAXN];
int main()
{
    int n; ll k; scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int ans = a[n] - a[1];
    int l = 1, r = n;
    ll cntl = 1, cntr = 1;
    while (l < r && k > 0)
    {
        while (a[l] == a[l + 1] && l < n) l++, cntl++;
        while (a[r] == a[r - 1] && r > 1) r--, cntr++; 
        if (l >= r) break;
        if (cntl < cntr)
        {
            ll t = min(k / cntl, (ll)a[l + 1] - a[l]);
            k -= t * cntl; ans -= t;
            if (t < a[l + 1] - a[l]) break;
            else l++, cntl++;
        }
        else 
        {
            ll t = min(k / cntr, (ll)a[r] - a[r - 1]);
            k -= t * cntr; ans -= t;
            if (t < a[r] - a[r - 1]) break;
            else r--, cntr++;
        }
    }
    printf("%d\n", ans);
    return 0;
}