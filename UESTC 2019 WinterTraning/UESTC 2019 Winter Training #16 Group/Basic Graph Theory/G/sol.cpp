#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6 + 7;
const int INF = 1e9;
struct node
{
    int v, w, next;
}e[maxn];
int head[maxn], tot;
int val[maxn];
void add(int u, int v, int w)
{
    ++tot;
    e[tot].v = v; e[tot].w = w; e[tot].next = head[u];
    head[u] = tot;
}

int n, cas = 0;
int dis[maxn], vis[maxn], cnt[maxn];
queue<int>q;
int spfa(int s)
{
    while (!q.empty()) q.pop();
    for (int i = 1; i <= n; i++) {dis[i] = -INF; vis[i] = cnt[i] = 0;}
    q.push(s); dis[s] = 0; vis[s] = cnt[s] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        vis[u] = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v, w = e[i].w;
            if (dis[u] + w > dis[v])
            {
                dis[v] = dis[u] + w;
                if (!vis[v])
                {
                    cnt[v]++; if (cnt[v] > n) return 0;
                    vis[v] = 1;
                    q.push(v);
                }
            }
        }
    }
    return 1;
}
int main()
{ 
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        for (int i = 1; i <= n; i++) scanf("%d", &val[i]);
        tot = 0; MEM(head, 0);
        char s[10]; int x, y;
        while (scanf(" %s", s) != EOF)
        {
            if (s[0] == '#') break;
            int x, y; scanf("%d%d", &x, &y);
            if (s[0] == 'F' && s[2] == 'S') add(y, x, -val[x]);
            else if (s[0] == 'F' && s[2] == 'F') add(y, x, val[y] - val[x]);
            else if (s[0] == 'S' && s[2] == 'F') add(y, x, val[y]);
            else if (s[0] == 'S' && s[2] == 'S') add(y, x, 0);
        } 
        int root = 0;
        for (int i = 1; i <= n; i++) add(root, i, 0);
        printf("Case %d:\n", ++cas);
        if (spfa(root))
        {
            //int mi = INF;
            //for (int i = 1; i <= n; i++) mi = min(mi, dis[i]);
            for (int i = 1; i <= n; i++) printf("%d %d\n", i, dis[i]);
        }
        else puts("impossible");
        puts("");
    }
    return 0;
}

