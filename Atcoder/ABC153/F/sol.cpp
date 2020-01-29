#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
pii p[MAXN];
int r[MAXN];
ll lazy[MAXN];
int main()
{
    int n, D, A; scanf("%d%d%d", &n, &D, &A);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].fir, &p[i].sec);
    sort(p + 1, p + 1 + n);
    ll ans = 0;
    for (int i = 1, j = 1; i <= n; i++)
    {
        while (j < n && p[j + 1].fir <= (ll)p[i].fir + 2 * D) j++;
        lazy[i] += lazy[i - 1];
        p[i].sec -= lazy[i];
        if (p[i].sec > 0) 
        {
            ll t = (p[i].sec - 1) / A + 1;
            ans += t;
            lazy[i] += t * A; lazy[j + 1] -= t * A;
        }
    }
    printf("%lld\n", ans);
    return 0;
}