#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int a[3007], cnt[3007], n;
void print(int *a, int n)
{
    for (int i = 1; i <= n; i++) 
        printf("%d%c", a[i], i == n ? '\n' : ' ');
}
LL ksm(LL a, LL b)
{
    LL res = 1;
    while (b)
    {
        if (b & 1) res = MOD(res * a);
        a = MOD(a * a);
        b /= 2;
    }
    return res;
}
LL ans;
LL fac[3007], inv[3007];
void init()
{
    fac[0] = 1; for (int i = 1; i <= 3000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[3000] = ksm(fac[3000], mod - 2);
    for (int i = 3000; i >= 1; i--) inv[i - 1] = MOD(inv[i] * i); 
}
void dfs(int now, int last, int sum, int mul)
{
    if (now == n + 1)
    {
        if (sum == mul)
        {
            print(a, n);
            LL tmp = fac[n];
            for (int i = 1; i <= n; i++)
                tmp = MOD(tmp * inv[cnt[i]]);
            ans = MOD(ans + tmp);
        }
        return;
    }
    if (sum + (n - now + 1) == mul)
    {
        print(a, now - 1);
        LL tmp = fac[n];
        for (int i = 1; i <= n; i++)
        {
            tmp = MOD(tmp * inv[cnt[i]]);
        }
        tmp = MOD(tmp * inv[n - now + 1]);
        ans = MOD(ans + tmp);
    }
    if (sum + (n - now + 1) < mul) return;
    
    for (int i = last; i > 1; i--)
    {
        a[now] = i;
        cnt[i]++;
        dfs(now + 1, i, sum + a[now], mul * a[now]);
        cnt[i]--;
    }
}
int main()
{
    init();
    scanf("%d", &n);
    dfs(1, n, 0, 1);
    /* 
    for (int i = 1; i <= 3000; i++)
    {
        ans = 0;
        n = i;
        dfs(1, n, 0, 1);
        printf("%lld,", ans);
    }
    */
    return 0;
}
