#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define int long long
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e6 + 7;
vector<int>v;
int w[maxn], h[maxn], f[maxn];
int mx[maxn];
int getid(int x)
{
    return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int fa(int x)
{
    return f[x] == x ? f[x] : f[x] = fa(f[x]);
}
signed main()
{
    int n; scanf("%lld", &n);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &w[i], &h[i]);
        v.pb(w[i]); v.pb(h[i]);
        ans += (LL)w[i] + (LL)h[i];
    }
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());
    //printf("%lld\n", ans);
    for (int x : v) ans -= (LL)x;
    //printf("%lld\n", ans);

    for (int i = 1; i <= 2000000; i++) f[i] = i;
    int tot = v.size();
    int sp = tot + 3;
    for (int i = 1; i <= n; i++)
    {
        int u = getid(w[i]), v = getid(h[i]);
        int fu = fa(u), fv = fa(v);
        if(f[fu]==sp || f[fv] == sp)
		{
			f[fu] = sp;
			f[fv] = sp;
			continue;
		}
        if (fu != fv) f[fu] = fv;
        else f[fu] = sp;
    }
    for (int i = 1; i <= tot + 3; i++) f[i] = fa(i);
    for (int i = 1; i <= tot + 3; i++)
        mx[f[i]] = max(mx[f[i]], v[i - 1]);
    for (int i = 1; i <= tot; i++) ans += (LL)mx[i];
    printf("%lld\n", ans);
	return 0;
}
