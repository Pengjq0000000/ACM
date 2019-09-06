#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1 << 18;
LL dp[maxn][40];
int cnt[maxn];
int num[40], s[40], lazy[40];
void solve1(int n, int k)
{
    for (int sta = 0; sta < (1 << (k - 1)); sta++)
        for (int i = 0; i <= n; i++)
            dp[sta][i] = 0;
    dp[0][0] = 1;
    for (int i = 0; i < n; i++)
        for (int sta = 0; sta < (1 << min(i, k - 1)); sta++)
        {
            //printf("dp[%d][%d]=%lld\n", sta, i, dp[sta][i]);
            int nxt = (sta & ((1 << (k - 2)) - 1)) << 1;
            int f = (cnt[sta] & 1) ^ num[i + 1];
            dp[nxt][i + 1] = MOD(dp[nxt][i + 1] + dp[sta][i] * (1 + f));
            if (i + 1 <= n - k + 1)
                dp[nxt + 1][i + 1] = MOD(dp[nxt + 1][i + 1] + dp[sta][i] * (1 + (f ^ 1)));
        }
    LL ans = 0;
    for (int i = 0 ; i < (1 << (k - 1)); i++)
        ans = MOD(ans + dp[i][n]);
    printf("%lld\n", ans);
}
void solve2(int n, int k)
{
    int sz = n - k + 1; LL ans = 0;
    for (int sta = 0; sta < (1 << sz); sta++)
    {
        int tmp = sta, flag = 0, cnt = 0;
        for (int i = 1; i <= n; i++) lazy[i] = 0;
        for (int i = 1; i <= sz; i++)
        {
            s[sz - i + 1] = tmp & 1;
            tmp >>= 1;
        }
        for (int i = 1; i <= n; i++)
        {
            flag ^= lazy[i];
            if (i <= sz && s[i]) flag ^= 1, lazy[i + k] ^= 1;
            if (flag ^ num[i]) cnt++;
        }
        //printf("sta=%d cnt=%d\n", sta, cnt);
        ans = MOD(ans + (1ll << cnt));
    }
    printf("%lld\n", ans);
}
int main()
{
    for (int i = 1; i < maxn; i++)
    {
        int tmp = (i & -i);
        cnt[i] = cnt[i ^ tmp] + 1;
    }
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, k; scanf("%d%d", &n, &k);
        for (int i = 1; i <= n; i++) scanf("%d", &num[i]);
        if (k <= 18) solve1(n, k);
        else solve2(n, k);

        //if (n - k + 1 <= 17) solve2(n, k);
        //else solve1(n, k);
    }
    return 0;
}
