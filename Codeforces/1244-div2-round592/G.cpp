#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e6 + 7;
int a[MAXN];
int main()
{
    int n; ll k; scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++) a[i] = i;
    ll now = (ll)n * (n + 1) / 2;
    if (k < now) {puts("-1"); return 0;}
    for (int i = 1; i <= n / 2; i++)
    {
        int det = (a[n + 1 - i] - a[i]);
        if (now + det <= k) now += det, swap(a[n + 1 - i], a[i]);
        else 
        {
            for (int j = n + 1 - i; j > i; j--)
                if (now + a[j] - a[i] <= k) 
                {
                    now += a[j] - a[i];
                    swap(a[i], a[j]);
                    break;
                }
            break;
        }
    }
    printf("%lld\n", now);
    for (int i = 1; i <= n; i++) printf("%d%c", i, " \n"[i == n]);
    for (int i = 1; i <= n; i++) printf("%d%c", a[i], " \n"[i == n]);
    return 0;
}