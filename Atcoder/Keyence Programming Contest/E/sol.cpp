#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 2e5 + 7;
const int INF = 1e9;
int head[MAXN];
struct node{int v, next, val;}e[MAXN << 1];
int tot = 1, col[MAXN];
void add(int u, int v)
{
    e[++tot] = {v, head[u], INF};
    head[u] = tot;
}
pii a[MAXN];
int d[MAXN];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &d[i]);
        a[i].fir = d[i], a[i].sec = i;
        col[i] = -1;
    }
    sort(a + 1, a + 1 + n);
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v);
        add(u, v); add(v, u);
    }
    for (int o = 1; o <= n; o++)
    {
        int u = a[o].sec;
        if (col[u] != -1) continue;
        int eid = 0;
        for (int i = head[u]; i; i = e[i].next)
        {
            int v = e[i].v;
            if (d[v] <= d[u]) eid = i;
        }
        if (!eid) 
        {
            puts("-1");
            return 0;
        }
        int v = e[eid].v;
        e[eid].val = e[eid ^ 1].val = d[u];
        if (col[v] == -1) {col[v] = 0; col[u] = 1;}
        else col[u] = col[v] ^ 1;
    }
    for (int i = 1; i <= n; i++) putchar(col[i] ? 'B' : 'W');
    putchar('\n');
    for (int i = 2; i <= tot; i += 2) printf("%d\n", e[i].val);
    return 0;
}