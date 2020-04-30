#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
const int MAXN = 40;
vector<int>G[MAXN];
int n, m, d[MAXN];
int cnt0 = 0, numC = 0;
int f[MAXN];
int fa(int x) {return x == f[x] ? f[x] : fa(f[x]);}
void init()
{
    for (int u = 0; u < n; u++) 
    {
        if (!d[u]) cnt0++;
        f[u] = u;
    }
    for (int u = 0; u < n; u++)
        for (int v : G[u])
        {
            int x = fa(u), y = fa(v);
            if (x == y) continue;
            if (x < y) swap(x, y);
            f[x] = y;
        }
    for (int u = 0; u < n; u++) if (fa(u) == u) numC++;
}
ll cal1() {return (1ll << cnt0);}
queue<pii>q; 
int clr[MAXN];
bool bfs(int s)
{
    q.push({s, clr[s] = 1}); 
    while (q.size())
    {
        int u = q.front().fir, nxt = q.front().sec ^ 1; q.pop();
        for (int v : G[u]) if (clr[v] == -1) q.push({v, clr[v] = nxt});
        else if (clr[v] ^ nxt) return true;
    }
    return false;
}
ll cal2()
{
    for (int u = 0; u < n; u++) clr[u] = -1;
    bool flag = 0;
    for (int u = 0; u < n; u++) if (clr[u] == -1) flag |= bfs(u);
    return flag ? 0 : (1ll << numC);
}
ll cal3() {return (1ll << numC);}
ll dp[1 << 20];
int e[MAXN], g[MAXN], is[1 << 20];
ll cal4()
{
    int n1 = n / 2; // 0 ~ n1 - 1
    int n2 = n - n1; // n1 ~ n - 1
    for (int u = 0; u < n1; u++)
    {
        e[u] = 1ll << u;
        for (int v : G[u]) if (v < n1) e[u] |= (1 << v);
    }
    dp[0] = 1;
    for (int s = 1, U = ((1 << n1) - 1); s < (1 << n1); s++)
    {
        int u = __builtin_ctz(s & -s);
        int s1 = s ^ (1 << u);
        int s2 = (U ^ e[u]) & s1;
        dp[s] = dp[s1] + dp[s2];
    }
    for (int u = n1; u < n; u++) 
    {
        e[u - n1] = 0;
        for (int v : G[u]) 
        {
            if (v < n1) g[u - n1] |= (1 << v);
            else e[u - n1] |= (1 << (v - n1));
        }
    }
    ll res = dp[(1 << n1) - 1];
    is[0] = 1; 
    for (int s = 1, U = ((1 << n1) - 1); s < (1 << n2); s++)
    {
        int u = __builtin_ctz(s & -s);
        if (!is[s ^ (1 << u)]) continue;
        if (e[u] & s) continue;
        is[s] = 1;
        int sta = 0;
        for (int i = 0; i < n2; i++) if (s >> i & 1) sta |= g[i];
        res += dp[U ^ sta];
    }
    return res;
}
int main()
{
    scanf("%d%d", &n, &m); 
    if (!m) {puts("0"); return 0;}
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v); 
        u--; v--;
        G[u].push_back(v); G[v].push_back(u);
        d[u]++; d[v]++;
    }
    ll ans = (1ll << n); init();
    ans += cal1() * 2 + cal2() - cal3() - cal4() * 2;
    printf("%lld\n", ans);
    return 0;
}