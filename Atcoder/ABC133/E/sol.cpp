#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL fac[maxn], inv[maxn];
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = MOD(res * base);
        base = MOD(base * base);
        b /= 2;
    }
    return res;
}
int n, k;
LL ans = 1;
LL cal(int n, int m) 
{
    if (n < m) return 0;
    return MOD(fac[n] * inv[n - m]);
}
vector<int>E[maxn];
void dfs(int u, int fa)
{
    for (int v : E[u])
    {
        if (v == fa) continue;
        dfs(v, u);
    }
    if (fa == -1) ans = MOD(ans * cal(k - 1, E[u].size()));
    else ans = MOD(ans * cal(k - 2, E[u].size() - 1));
}
int main()
{
	scanf("%d%d", &n, &k);
    fac[0] = 1; for (int i = 1; i <= 100000; i++) fac[i] = MOD(fac[i - 1] * i);
    inv[100000] = ksm(fac[100000], mod - 2); inv[0] = 1;
    for (int i = 100000 - 1; i >= 1; i--) inv[i] = MOD(inv[i + 1] * (i + 1));
    for (int i = 1; i < n; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        E[u].pb(v); E[v].pb(u);
    }
    ans = k;
    dfs(1, -1);
    printf("%lld\n", ans);
	return 0;
}
