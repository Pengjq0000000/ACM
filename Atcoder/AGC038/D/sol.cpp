#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
int x[MAXN], y[MAXN], c[MAXN];
int f[MAXN], cnt0, cnt1, used;
int find(int x) {return x == f[x] ? f[x] : f[x] = find(f[x]);}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x != y) f[x] = y, cnt0--, used++;
}
int main()
{
    int n, q; ll m; scanf("%d%lld%d", &n, &m, &q);
    cnt0 = n; used = 0; cnt1 = 0;
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= q; i++)
    {
        scanf("%d%d%d", &x[i], &y[i], &c[i]);
        x[i]++; y[i]++;
        if (!c[i]) unite(x[i], y[i]);
        else 
        {
            cnt1++;
            if (m == n - 1) {puts("No"); return 0;}
        }
    }
    m -= used;
    if (!cnt1)
    {
        (m >= cnt0 - 1 && m <= (ll)cnt0 * (cnt0 - 1) / 2) ? puts("Yes") : puts("No");
        return 0;
    }
    else 
    {
        if (cnt0 == 2) {puts("No"); return 0;}
        for (int i = 1; i <= q; i++) if (c[i])
            if (find(x[i]) == find(y[i])) {puts("No"); return 0;}
        (m >= cnt0 && m <= (ll)cnt0 * (cnt0 - 1) / 2) ? puts("Yes") : puts("No");
    }
    return 0;
}