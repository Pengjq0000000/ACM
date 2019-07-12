#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2007;
bitset<maxn>a[maxn], mp[maxn];
int n, k;
int fa[maxn];
bool done[maxn];
vector<int>part[maxn];
int find(int x) {return x == fa[x] ? fa[x] : fa[x] = find(fa[x]);}
queue<int>q;
int dis[maxn];
bitset<maxn>vis, nxt;
int BFS(int u)
{
    int mx = 0;
    for (int i = 1; i <= n; i++) dis[i] = 0;
    vis.set();
    q.push(u); vis[u] = 0;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        mx = max(mx, dis[u]);
        nxt = a[u] & vis;
        int v = nxt._Find_first();
        while (v <= n)
        {
            dis[v] = dis[u] + 1; q.push(v);
            vis[v] = 0;
            v = nxt._Find_next(v);
        }
    }
    return mx;
}
vector<int>p[maxn];
int tot = 0, VIS[maxn];
void DIV(int u)
{
    for (int i = 1; i <= n; i++) VIS[i] = 0;
    p[++tot].pb(u); VIS[u] = 1;
    int sign = 1;
    while (sign)
    {
        int tmp = tot;
        sign = 0;
        for (int x : p[tmp])
        {
            int v = a[x]._Find_first();
            while (v <= n)
            {
                if (!VIS[v])
                {
                    if (!sign) {sign = 1; tot++; p[tot].pb(v);}
                    else p[tot].pb(v);
                    VIS[v] = 1;
                }
                a[x][v] = a[v][x] = 0;
                v = a[x]._Find_next(v);
            }
        }
    }
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) fa[i] = i;
	for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            char x; scanf(" %c", &x);
            if (x == '1') 
            {
                a[i][j] = 1;
                int u = find(i), v = find(j);
                if (u > v) swap(u, v);
                fa[v] = u;
            } 
        }
    for (int i = 1; i <= n; i++) find(i);
    for (int i = 1; i <= n; i++) part[fa[i]].pb(i);
    for (int i = 1; i <= n; i++)
    {
        if (part[i].size() == 0) continue;
        int mx = -1, st = 0;
        for (int u : part[i])
        {
            int res = BFS(u);
            if (mx < res) mx = res, st = u;
        }
        //printf("mx:%d st:%d\n", mx, st);
        DIV(st);
    }
    //printf("%d\n", tot);
    if (tot < k) {puts("Nope"); return 0;}
    puts("Yep");
    for (int i = 1; i < k; i++)
    {
        printf("%d", (int)p[i].size());
        for (int x : p[i]) printf(" %d", x);
        puts("");
    }
    int sz = 0;
    for (int i = k; i <= tot; i++) sz += p[i].size();
    printf("%d", sz);
    for (int i = k ; i <= tot; i++)
    {
        for (int x : p[i]) printf(" %d", x);
    }
    puts("");
	return 0;
}
/*
8 4
01100000
10010000
10001000
01000001
00100010
00000011
00001100
00010100
 */