#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
ll read() 
{
    ll x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int maxn = 2e5 + 7; 
int best[maxn << 2];
vector<int>vec;
ll k[maxn], b[maxn];
ll f(int id, int x) {return k[id] * vec[x - 1] + b[id];}
void update(int rt, int l, int r, int x)
{
    if (f(x, l) > f(best[rt], l) && f(x, r) > f(best[rt], r)) {best[rt] = x; return;}
    if (f(x, l) <= f(best[rt], l) && f(x, r) <= f(best[rt], r)) return;
    int mid = (l + r) / 2;
    if (k[best[rt]] < k[x])
    {
        if (f(best[rt], mid) < f(x, mid)) update(lson, l, mid, best[rt]), best[rt] = x;
        else update(rson, mid + 1, r, x);
    }
    else 
    {
        if (f(best[rt], mid) < f(x, mid)) update(rson, mid + 1, r, best[rt]), best[rt] = x;
        else update(lson, l, mid, x);
    }
}
ll query(int rt, int l, int r, int pos)
{
    if (l == r) return f(best[rt], pos);
    int mid = (l + r) / 2;
    ll res = f(best[rt], pos);
    if (pos <= mid) res = max(res, query(lson, l, mid, pos));
    else res = max(res, query(rson, mid + 1, r, pos));
    return res;
}
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int a[maxn];
ll sum[maxn];
int main()
{
    int n = read();
    for (int i = 1; i <= n; i++) 
    {
        a[i] = read(), sum[i] = sum[i - 1] + a[i];
        k[i] = i; b[i] = -sum[i];
        vec.push_back(a[i]);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    int N = vec.size();
    for (int i = 1; i <= n; i++) update(1, 1, N, i); 
    ll init = 0; for (int i = 1; i <= n; i++) init += (ll)a[i] * i;
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        ll res = sum[i] - (ll)a[i] * i + query(1, 1, N, getid(a[i]));
        ans = max(ans, res);
    }
    printf("%lld\n", ans + init);
	return 0;
}