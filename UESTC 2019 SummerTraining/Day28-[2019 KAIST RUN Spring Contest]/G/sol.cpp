#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 500000 + 7;
int n, m, rt, endp, dep[maxn], val[maxn];
int a[maxn], dp[maxn], ind[maxn], outd[maxn];
int stk[maxn];
set<pii>s[maxn];
int f[maxn][20];
vector<int>E[maxn], G[maxn], T[maxn];
void BFS()
{
    queue<int>q;
    rt = n + 1; endp = n + 2;
    for (int i = 1; i <= n; i++)
    {
        if (!ind[i])
        {
            q.push(i);
            E[rt].pb(i);
            G[i].pb(rt);
        }
        if (!outd[i])
        {
            E[i].pb(endp);
            G[endp].pb(i);
            ind[endp]++;
        }
    }
    int tot = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        a[++tot] = u;
        for (int v : E[u]) if ((--ind[v]) == 0) q.push(v);
    }
    for (int i = 1; i <= tot; i++) printf("%d ", a[i]); puts("");
}
int LCA(int x, int y)
{
    if (dep[x] > dep[y]) swap(x, y);
    for (int i = 19; i >= 0; i--) if (dep[y] > dep[x] && dep[f[y][i]] >= dep[x]) y = f[y][i];
    for (int i = 19; i >= 0; i--) if (f[x][i] != f[y][i]) x = f[x][i], y = f[y][i];
    return x == y ? x : f[x][0];
}

int ans[maxn];
int main()
{
	scanf("%d", &n);
    int len = 0;
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] > stk[len])
        {
            stk[++len] = a[i];
            dp[i] = len;
        }
        else
        {
            int pos = lower_bound(stk + 1, stk + 1 + len, a[i]) - stk;
            stk[pos] = a[i]; dp[i] = pos;
        }
        s[dp[i]].insert(make_pair(a[i], i));
    }
    for (int i = 1; i <= n; i++)
    {
        if (dp[i] == 1) continue;
        for (auto iter = s[dp[i] - 1].begin(); iter != s[dp[i] - 1].end(); iter++)
        {
            if ((iter->fir) > a[i]) break;
            E[i].pb(iter->sec);
            G[iter->sec].pb(i);
            ind[iter->sec]++; outd[i]++;
        }
    }
    BFS();
    dep[rt] = 1;
    for (int i = 1; i <= n + 1; i++)
    {
        int u = a[i], fa = -1;
        for (int v : G[u])
            fa = (fa == -1 ? v : LCA(fa, v));
        dep[u] = dep[fa] + 1; f[u][0] = fa; T[fa].pb(u);
        for (int j = 1; j <= 19; j++) f[u][j] = f[f[u][j - 1]][j - 1];
    }
    for (int i = 1; i <= n; i++) ans[i] = dep[endp] - 2;
    int u = endp;
    while (f[u][0] != 0)
    {
        u = f[u][0];
        ans[u]--;
    }
    for (int i = 1; i <= n; i++) printf("%d ", ans[i]);puts("");
	return 0;
}
