#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 51;
ll a[MAXN];
int n;
int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    ll ans = 0, MAX;
    while ((MAX = *max_element(a + 1, a + 1 + n)) >= n)
    {
        for (int i = 1; i <= n; i++)
        {
            ll t = (a[i] - (a[i] % n)) / n;
            ans += t;
            a[i] %= n;
            for (int j = 1; j <= n; j++) if (j != i) a[j] += t;
        }
    }
    printf("%lld\n", ans);
    return 0;
}