#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 1e5 + 7;
const int mod = 1e9 + 7;
inline int add(int x, int y) {int res = x + y; if (res >= mod) res -= mod; return res;}
inline int mul(int x, int y) {ll res = (ll)x * y; res -= res / mod * mod; return res;}
vector<int>G[MAXN];
int dp[MAXN][2];
void dfs(int u, int f) // 0-white 1-black
{
    dp[u][0] = dp[u][1] = 1;
    for (int v : G[u]) if (v != f)
    {
        dfs(v, u);
        dp[u][0] = mul(dp[u][0], add(dp[v][0], dp[v][1]));
        dp[u][1] = mul(dp[u][1], dp[v][0]);
    }
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++) scanf("%d%d", &u, &v), G[u].push_back(v), G[v].push_back(u);
    dfs(1, 0);
    printf("%d\n", add(dp[1][0], dp[1][1]));
    return 0;
}