#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
inline int mul(ll x, ll y) {return x * y % mod;}
inline int add(ll x, ll y) {return (x + y) % mod;}
ll qpow(ll a, ll b)
{
    ll res = 1;
    while (b) {if (b & 1) res = mul(res, a); a = mul(a, a); b /= 2;}
    return res;
}
vector<int>G[MAXN];
ll ans[MAXN], sz[MAXN];
ll fac[MAXN], inv[MAXN];
ll C(int n, int m)
{
    return mul(fac[n], mul(inv[m], inv[n - m]));
}
void dfs1(int u, int f)
{
    sz[u] = 1; int tot = 0;
    for (int v : G[u]) if (v != f)
    {
        dfs1(v, u), sz[u] += sz[v];
        if (tot == 0) tot = sz[v];
        else 
        {
            tot += sz[v];
            ans[1] = mul(ans[1], C(tot, sz[v]));
        }
    }
}
int n;
void dfs2(int u, int f)
{
    for (int v : G[u]) if (v != f)
    {
        ans[v] = mul(mul(ans[u], sz[v]), qpow(n - sz[v], mod - 2));
        dfs2(v, u);
    }
}
int main()
{
    int N = 2e5 + 1;
    fac[0] = 1; for (int i = 1; i <= N; i++) fac[i] = mul(fac[i - 1], i);
    inv[N] = qpow(fac[N], mod - 2); for (int i = N; i; i--) inv[i - 1] = mul(inv[i], i);
    scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) 
    {
        scanf("%d%d", &u, &v);
        G[u].push_back(v);
        G[v].push_back(u);
    }
    ans[1] = 1; dfs1(1, 0);
    dfs2(1, 0);
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
    return 0;
}