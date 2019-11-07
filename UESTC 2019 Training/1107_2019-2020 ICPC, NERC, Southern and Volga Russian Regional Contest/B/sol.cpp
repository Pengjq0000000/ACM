#include<bits/stdc++.h>
#define ll long long
using namespace std;
int cnt[8010];
int n, k; 
ll ans = 1e18;
ll get(int x)
{
    int MAX = 0;
    for (int i = 1; i <= x / 2; i++) 
        MAX = max(MAX, cnt[i] + cnt[x - i + 1]);
    for (int i = x + 1; i <= k; i++) MAX = max(MAX, cnt[i]);
    return (ll)MAX * (x / 2 + k - x);
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), cnt[x]++;
    sort(cnt + 1, cnt + 1 + k);
    ans = (ll)cnt[k] * k;
    for (int i = 1; 2 * i <= k; i++)
        ans = min(ans, get(2 * i));
    printf("%lld\n", ans);
    return 0;
}