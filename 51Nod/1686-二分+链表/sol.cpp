#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5 + 7;
int n, a[N]; ll k;
int nxt[N], pre[N], fir[N], cnt[N], lst[N], lstx[N], MAX[N];
vector<int>vec;
ll cal(int x)
{
    for (int i = 1; i <= n; i++) nxt[i] = pre[i] = lstx[i] = lst[i] = cnt[i] = fir[i] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (!fir[a[i]]) fir[a[i]] = i;
        if (lst[a[i]]) pre[i] = lst[a[i]], nxt[pre[i]] = i;
        lst[a[i]] = i;
        cnt[a[i]]++;
        if (cnt[a[i]] > x) 
        {
            if (!lstx[pre[i]]) lstx[i] = fir[a[i]];
            else lstx[i] = nxt[lstx[pre[i]]];
        }
    }
    ll res = 0;
    int p = 0;
    for (int i = 1; i <= n; i++)
    {
        p = max(p, lstx[i]);
        res += i - p;
    }
    return res;
}
int main()
{
    scanf("%d%lld", &n, &k); k = (ll)n * (n + 1) / 2 - k + 1;
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vec.push_back(a[i]);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++) a[i] = lower_bound(vec.begin(), vec.end(), a[i]) - vec.begin() + 1;
    int l = 1, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        if (cal(mid) >= k) r = mid;
        else l = mid + 1;
    }
    printf("%d\n", l);
    return 0;
}