#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 10000019
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
int n, m, a[maxn], b[maxn], vis[maxn * 2];
LL cnt, num;
int sz;
int head[maxn * 4], used[maxn * 4];
struct node{int v, next;}e[maxn << 2];
int tot = 1;
void add(int u, int v)
{
    e[++tot] = {v, head[u]}; head[u] = tot;
    used[tot] = 0;
}
void dfs(int u, int fa)
{
    vis[u] = 1;
    if (u <= n) num++;
    for (int i = head[u]; i; i = e[i].next)
    {
        if (used[i]) continue;
        used[i] = used[i ^ 1] = 1;
        int v = e[i].v;
        if (vis[v]) {cnt++;if(fa==v) sz=2; continue;}
        dfs(v, u);
    }
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        tot = 1;
        for (int i = 1; i <= n + m; i++) head[i] = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &a[i], &b[i]);
            add(i, a[i] + n);
            add(a[i] + n, i);
            add(i, b[i] + n);
            add(b[i] + n, i);
        }
        for (int i = 1; i <= n + m; i++) vis[i] = 0;
        LL ans = 1;
        for (int i = 1; i <= n; i++)
        {
            if (vis[i]) continue; 
            cnt = 0; num = 0;
            sz=0;
            dfs(i, -1);
            if (cnt >= 2) ans = 0;
            else if (cnt == 1) 
            {
                if(sz!=2)
                    ans = MOD(ans * 2);
            }
            else if (cnt == 0) ans = MOD(ans * (num + 1));
        }
        printf("%lld\n", ans);
    }
	return 0;
}
