#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn], deg[maxn], dep[maxn], f[maxn];
vector<int>E[maxn], leaf[maxn], G[maxn];
struct node{int u, v, w;}ans[maxn * 10], e[maxn];
int tot = 0, rt;
void dfs(int u, int fa)
{
    for (int v : E[u])
    {
        if (v == fa) continue;
        G[u].pb(v); dep[v] = dep[u] + 1; f[v] = u;
        if (deg[v] == 1) {leaf[u].pb(v); continue;}
        dfs(v, u);
        for (int x : leaf[v]) leaf[u].pb(x); 
    }
}
int flag;
void get(int u, int goal)
{
    if (u == goal) flag = 1;
    for (int v : G[u]) get(v, goal);
}
void deal(int u, int l, int w)
{
    if (u == rt) {ans[++tot] = {u, l, w}; return;}
    int x;
    for (int v : G[u])
    {
        flag = 0; get(v, l); if (flag == 1) continue;
        if (leaf[v].size() == 0) x = v;
        else x = leaf[v][0];
    }
    ans[++tot] = {l, rt, w / 2};
    ans[++tot] = {l, x, w / 2};
    ans[++tot] = {rt, x, -w / 2}; 
}
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d%d%d", &e[i].u, &e[i].v, &e[i].w);
        E[e[i].u].pb(e[i].v); E[e[i].v].pb(e[i].u);
        deg[e[i].u]++; deg[e[i].v]++;
    }
    if (n == 2) 
    {
        puts("YES"); puts("1");
        printf("%d %d %d\n", e[1].u, e[1].v, e[1].w);
        return 0;
    }
    for (int u = 1; u <= n; u++)
        if (deg[u] == 2) {puts("NO"); return 0;}
    puts("YES");
    rt = 1; while (deg[rt] != 1) rt++; //printf("rt:%d\n", rt);
    dfs(rt, -1);
    for (int i = 1; i < n; i++)
    {
        int u = e[i].u, v = e[i].v;
        if (dep[u] > dep[v]) swap(u, v);
        if (deg[v] == 1) deal(u, v, e[i].w);
        else 
        {
            deal(u, leaf[v][0], e[i].w);
            deal(v, leaf[v][0], -e[i].w);
        }
    }
    printf("%d\n", tot);
    for (int i = 1; i <= tot; i++) printf("%d %d %d\n", ans[i].u, ans[i].v, ans[i].w); 
	return 0;
}
