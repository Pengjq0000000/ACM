#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL ksm(LL a, LL b, LL pp)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = (res * base) % pp;
        base = (base * base) % pp;
        b /= 2;
    }
    return res;
}
int pft[20], g[20];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int p, n, m; scanf("%d%d%d", &p, &n, &m);
        if (p == 2 || p == 5)
        {
            puts("0");
            continue;
        }
        else if (p == 3)
        {
            printf("%lld\n", (LL)n / 3 * m);
            continue;
        }
        int x = p - 1, t = p - 1;
        for (int d = 2; d * d <= t; d++)
        {
            if (t % d == 0)
            {
                if (ksm(10, d, p) == 1) x = min(x, d);
                if (ksm(10, t / d, p) == 1) x = min(x, t / d);
            }
        }
        int tot = 0, tmp = x;
        for (int d = 2; d * d <= tmp; d++)
        {
            if (tmp % d == 0)
            {
                pft[++tot] = d; g[tot] = 0;
                while (tmp % d == 0) tmp /= d, g[tot]++;
            }
            if (tmp == 1) break;
        }
        if (tmp > 1) {pft[++tot] = tmp; g[tot] = 1;}
        //for (int i = 1; i <= tot; i++) printf("%d ", pft[i]); puts("");
        LL ans = 0, bs;
        for (int j = 1; j <= min(30, m); j++)
        {
            bs = 1;
            for (int i = 1; i <= tot; i++)
            {
                int cnt = g[i] / j; if (g[i] % j) cnt++;
                while (cnt--) bs *= pft[i];
            }
            ans += (LL)n / bs;
        }
        bs = 1; for (int i = 1; i <= tot; i++) bs *= pft[i];
        if (m > 30) ans += (LL)(n / bs) * (m - 30);
        printf("%lld\n", ans);
    }
	return 0;
}
