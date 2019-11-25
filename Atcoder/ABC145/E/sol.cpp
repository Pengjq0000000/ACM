#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 3007;
int dp[MAXN << 1];
pii a[MAXN];
int main()
{
    int n, T; scanf("%d%d", &n, &T);
    for (int i = 1; i <= n; i++) scanf("%d%d", &a[i].fir, &a[i].sec);
    int ans = 0;
    sort(a + 1, a + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        for (int j = T + 3000; j >= a[i].fir; --j) if (j - a[i].fir < T)
            ans = max(ans, dp[j] = max(dp[j], dp[j - a[i].fir] + a[i].sec));
    }
    printf("%d\n", ans);
    return 0;
}