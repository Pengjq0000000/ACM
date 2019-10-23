#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define inf 1e9
using namespace std;
const int maxn = (1 << 20) + 7;
int from[maxn], dis[maxn];
struct edge{int u, v, w;}e[maxn * 20];
int tot;
bool cmp (edge &x, edge &y) {return x.w < y.w;}
queue<int>q;
int f[maxn];
int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        int bits = (1 << n);
        for (int i = 0; i < bits; i++) from[i] = 0, dis[i] = inf;

        char s[30];
        for (int i = 1; i <= m; i++)
        {
            scanf(" %s", s + 1); int val = 0;
            for (int j = 1; j <= n; j++) val = val * 2 + (s[j] == 'L');
            from[val] = i;
            q.push(val); dis[val] = 0;
        }
        tot = 0;
        while (!q.empty())
        {
            int u = q.front(); q.pop();
            for (int i = 0; i < n; i++)
            {
                int v = u ^ (1 << i);
                if (dis[v] == inf) dis[v] = dis[u] + 1, from[v] = from[u], q.push(v);
                else if (from[u] != from[v]) 
                {
                    int len = dis[u] + dis[v] + 1;
                    e[++tot] = {from[u], from[v], len};
                }
            }
        }
        assert(tot <= bits * n);
        for (int i = 1; i <= m; i++) f[i] = i;
        int ans = 0;
        sort(e + 1, e + 1 + tot, cmp);
        for (int i = 1; i <= tot; i++)
        {
            int u = fa(e[i].u), v = fa(e[i].v);
            if (u != v) f[u] = v, ans += e[i].w;
        }
        printf("%d\n", ans);
    }
    return 0;
}