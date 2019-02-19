#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int up = 20;
const int maxn = 2e6 + 7;
struct node{LL tot; int t;}table[maxn];
map<LL, LL>exist[30];
LL fac[22], S, a[30];
int n, k, cnt = 0;

void dfs(int now, int t, LL tot)
{
    if (tot > S || t > k) return;
    if (now > n / 2)
    {
        table[++cnt].tot = tot;
        table[cnt].t = t;
        return;
    }
    dfs(now + 1, t, tot);
    dfs(now + 1, t, tot + a[now]);
    if (a[now] < up &&  S - tot - fac[a[now]] >= 0) dfs(now + 1, t + 1, tot + fac[a[now]]);
}

void DFS(int now, int t, LL tot)
{
    if (tot > S || t > k) return;
    if (now > n)
    {
        exist[t][tot]++;
        return;
    }
    DFS(now + 1, t, tot);
    DFS(now + 1, t, tot + a[now]);
    if (a[now] < up && S - tot - fac[a[now]] >= 0) DFS(now + 1, t + 1, tot + fac[a[now]]);
}

int main()
{
    scanf("%d%d%lld", &n, &k, &S);
    fac[0] = 1; for (int i = 1; i < up; i++) fac[i] = fac[i - 1] * i;
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    dfs(1, 0, 0);
    DFS(n / 2 + 1, 0, 0);
    LL ans = 0;
    for (int i = 1; i <= cnt; i++)
    {
        for (int j = 0; j <= k - table[i].t; j++) ans += exist[j][S - table[i].tot];
    }
    printf("%lld\n", ans);
    return 0;
}

