#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int fa[maxn], sz[maxn], deg[maxn];
LL num[maxn];
int find(int x) {return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);}
int vis[maxn];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) fa[i] = i;
    for (int i = 1; i <= m; i++)
    {
        int u, v; scanf("%d%d", &u, &v);
        deg[u]++; deg[v]++;
        int fu = find(u), fv = find(v);
        if (fu != fv)
        {
            fa[fu] = fv;
            //sz[fv] += sz[fu];
        }
    }
    for (int i = 1; i <= n; i++) find(i);
    for (int i = 1; i <= n; i++)
    {
        num[find(i)] += deg[i];
        sz[find(i)] += 1;
    }
    // for (int i = 1; i <= n; i++) printf("%d ", sz[i]);puts("");
    // for (int i = 1; i <= n; i++) printf("%d ", fa[i]);puts("");
    // for (int i = 1; i <= n; i++) printf("%lld ", num[i]);puts("");
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        if (sz[i] > 1)
        {
            ans += num[i] / 2 - sz[i] + 1;
        }
    }
    printf("%lld\n", ans);
	return 0;
}
