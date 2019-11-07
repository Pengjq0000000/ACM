#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 7;
ll a[N], b[N], suma[N], sumb[N];
int ans[N], cnt; 
int n, k; 
bool can_win(ll pa, ll pb, int pos)
{
    int l = pos, r = n;
    while (l < r)
    {
        int mid = (l + r + 1) >> 1;
        ll x = suma[mid] - suma[pos] + pa;
        if (x < k) l = mid;
        else r = mid - 1;
    }
    if (pa + suma[l] - suma[pos] >= k) return false;
    ll y = pb + sumb[l] - sumb[pos];
    if (y >= k) return true;
    else return false; 
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), suma[i] = suma[i - 1] + a[i];
        for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), sumb[i] = sumb[i - 1] + b[i];
        cnt = 0; int flag = 0;
        ll pa = 0, pb = 0;
        if (can_win(0, 0, 0)) 
        {
            puts("0"); puts("");
            continue;
        }
        for (int i = 1; i <= n; i++)
        {
            ll det = min(pa, pb);
            if (pa + a[i] >= k)
            {
                pa -= det; pb -= det;
                ans[++cnt] = i - 1;
            }
            pa += a[i]; pb += b[i];
            if (pa >= k) {flag = 0; break;}
            det = min(pa, pb);
            if (can_win(pa - det, pb - det, i)) 
            {
                flag = 1;
                ans[++cnt] = i;
                break;
            }
        } 
        if (!flag) {puts("-1"); continue;}
        printf("%d\n", cnt);
        for (int i = 1; i <= cnt; i++) printf("%d%c", ans[i], i == cnt ? '\n' :' ');
    }
    return 0;
}