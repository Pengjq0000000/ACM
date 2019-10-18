#include<bits/stdc++.h>
#define P pair<long long, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
const int maxn = 5e4 + 7;
int pos[maxn], vis[maxn];
P a[maxn];
bool cmp(P &x, P &y) {return x.sec < y.sec;}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i].fir), a[i].sec = i;
    sort(a + 1, a + 1 + n);
    ll MIN = a[1].fir;
    for (int i = 1; i <= n; i++) pos[a[i].sec] = i;
    sort(a + 1, a + 1 + n, cmp);
    ll ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i]) continue;
        int x = i, cnt = 0;
        ll sum = 0, mi = 1e9;
        while (!vis[x]) 
        {
            sum += a[x].fir; mi = min(mi, a[x].fir); 
            vis[x] = 1; x = pos[x];
            cnt++;
        }
        ans += min(sum + mi * (cnt - 2), (sum - mi + MIN) + MIN * (cnt - 2) + 2ll * (mi + MIN));
    }
    printf("%lld\n", ans);
    return 0;
}