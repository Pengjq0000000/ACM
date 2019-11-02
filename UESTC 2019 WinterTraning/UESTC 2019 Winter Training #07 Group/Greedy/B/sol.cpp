#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
const int INF = 1e9+7;
struct node 
{
    int v, next;
    node(int v, int next):v(v), next(next){}
    node(){}
}e[maxn*2];
int head[maxn], deg[maxn], leaf[maxn], dp[maxn][2];
int tot;
void add(int u,int v)
{
    ++tot;
    e[tot] = node(v, head[u]);
    head[u] = tot;
}

void dfs(int u, int fa)
{
    if (deg[u] == 1) leaf[u] = 1;
    dp[u][0] = 0; dp[u][1] = INF;
    for (int i = head[u]; i; i = e[i].next)    
    {
        int v = e[i].v; if (v == fa) continue;
        dfs(v, u); leaf[u] += leaf[v];
        int d = (leaf[v] & 1) ? 1 : 2;
        dp[u][0] += dp[v][0] + d;
    }
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v; if (v == fa) continue;
        if (leaf[v] == 1) dp[u][1] = min(dp[u][1], dp[u][0]);
        int d = (leaf[v] & 1) ? 1 : -1;
        dp[u][1] = min(dp[u][1], dp[u][0] - dp[v][0] + dp[v][1] + d);
    }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        tot = 0;for (int i = 1; i <= n; i++) head[i] = deg[i] = leaf[i] = 0;
        for (int i = 1; i < n; i++)
        {
            int u, v; scanf("%d%d",&u, &v);
            add(u, v); add(v, u);
            deg[u]++; deg[v]++; 
        }
        if (n <= 2) {printf("%d\n", n - 1); continue;}
        int root = 0, cnt = 0;
        for (int i = 1; i <= n; i++) 
        {
            if (deg[i] == 1) cnt++;
            if (!root && deg[i] > 1) root = i;
        }
        dfs(root, 0);
        printf("%d\n", dp[root][cnt&1]);
    }
    return 0;
}

