#include<bits/stdc++.h>
using namespace std;
namespace IO
{
    int aa; bool bb; char ch;
    int input()
    {
        while(ch = getchar(), (ch < '0' || ch > '9') && ch != '-');
        ch == '-' ? (bb = 1, aa = 0) : (bb = 0, aa = ch - '0');
        while(ch = getchar(), (ch >= '0' && ch <= '9'))
            aa = aa * 10 + ch - '0';
        return (bb ? (-aa) : (aa));
    }
    void print(int x)
    {
        if (x == 0) return;
        if (x >= 10) print(x / 10);
        putchar('0' + x % 10);
    }
    void output(int x)
    {
        if (x < 0) putchar('-'), x = -x;
        if (x == 0) putchar('0');
        else print(x);
    }
}
const int MAXN = 1e6 + 7;
struct node{int v, next, id;}e[MAXN << 2];
int head[MAXN], tot = 1;
void add(int u, int v, int id)
{
    e[++tot] = {v, head[u], id};
    head[u] = tot;
}
int oddc = 0, oddc_eid = 0;
int dep[MAXN], lazy[MAXN];
void dfs(int u, int eid)
{
    for (int i = head[u]; i; i = e[i].next)
    {
        if (i == (eid ^ 1)) continue;
        int v = e[i].v;
        if (!dep[v]) 
        {
            dep[v] = dep[u] + 1;
            dfs(v, i);
            lazy[u] += lazy[v];
        }
        else 
        {
            if (dep[u] < dep[v]) continue;
            int g = ((dep[u] - dep[v] + 1) & 1);
            if (g) lazy[u]++, lazy[v]--, oddc++, oddc_eid = e[i].id; // odd circle
            else lazy[u]--, lazy[v]++; // even circle
        }
    }
}
vector<int>ans;
int vis[MAXN];
void DFS(int u)
{
    vis[u] = 1;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v; 
        if (vis[v]) continue;
        if (lazy[v] == oddc) ans.push_back(e[i].id);
        DFS(v);
    }
}
int main()
{
    int n = IO::input(), m = IO::input();
    int selfc = 0, self_eid = 0;
    for (int i = 1, u, v; i <= m; i++)
    {
        u = IO::input(), v = IO::input();
        if (u == v) selfc++, self_eid = i;
        else add(u, v, i), add(v, u, i);
    }
    for (int u = 1; u <= n; u++) if (!dep[u]) dep[u] = 1, dfs(u, 0);
    if (!oddc)
    {
        if (!selfc)
        {
            IO::output(m); putchar('\n');
            for (int i = 1; i <= m; i++) IO::output(i), putchar(" \n"[i == m]);
        }
        else 
        {
            if (selfc == 1) puts("1"), IO::output(self_eid);
            else puts("0");
        }
    }
    else 
    {
        if (selfc) {puts("0"); return 0;}
        if (oddc == 1) ans.push_back(oddc_eid);
        for (int u = 1; u <= n; u++) if (!vis[u]) DFS(u);
        sort(ans.begin(), ans.end());
        IO::output(ans.size()); putchar('\n');
        int p = 0;
        for (int x : ans) p++, IO::output(x), putchar(" \n"[p == ans.size()]);
    }
    return 0;
}