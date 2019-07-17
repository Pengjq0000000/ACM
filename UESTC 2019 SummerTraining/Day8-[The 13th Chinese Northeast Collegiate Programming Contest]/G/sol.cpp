#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int n;
int l[maxn], r[maxn], ll[maxn], rr[maxn];
LL suml[maxn], sumr[maxn];
vector<int>vv;
int getid(int x) {return lower_bound(vv.begin(), vv.end(), x) - vv.begin();}
LL mi;
void deal()
{
    mi = 1e18;
    sort(l + 1, l + 1 + n);
    sort(r + 1, r + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        suml[i] = suml[i - 1] + vv[l[i]] - vv[0];
        sumr[i] = sumr[i - 1] + vv[r[i]] - vv[0];
    }
    int sz = vv.size();
    int lp = 1, rp = 1;
    for (int i = 0; i < sz; i++)
    {
        LL pos = vv[i];
        while (pos >= vv[l[lp]] && lp <= n) lp++;
        while (pos >= vv[r[rp]] && rp <= n) rp++;
        LL tmp = 0;
        tmp += (suml[n] - suml[lp - 1]) - (pos - vv[0]) * (n - lp + 1);
        tmp += (pos - vv[0]) * (rp - 1) - (sumr[rp - 1]);
        mi = min(mi, tmp);
    }
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        vv.clear();
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
            vv.pb(a); vv.pb(b); vv.pb(c); vv.pb(d);
            l[i] = a; r[i] = c;
            ll[i] = b; rr[i] = d;
        }
        sort(vv.begin(), vv.end());
        vv.erase(unique(vv.begin(), vv.end()), vv.end());
        for (int i = 1; i <= n; i++)
        {
            l[i] = getid(l[i]);
            r[i] = getid(r[i]);
            ll[i] = getid(ll[i]);
            rr[i] = getid(rr[i]);
        }
        LL ans = 0;
        deal(); ans += mi;
        for (int i = 1; i <= n; i++) l[i] = ll[i], r[i] = rr[i];
        deal(); ans += mi;
        printf("%lld\n", ans);
    }
	return 0;
}
