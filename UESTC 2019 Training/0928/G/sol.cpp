#include<bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 7;
int f[maxn * 52], lst[maxn * 52];
int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void unite_f(int u, int v)
{
    u = find(u), v = find(v);
    if (u == v) return;
    f[u] = v;
}
int glst(int x) {return x == lst[x] ? x : lst[x] = glst(lst[x]);}
void unite_lst(int u, int v)
{
    u = glst(u), v = glst(v);
    if (u > v) swap(u, v);
    lst[u] = v;
}
inline int id(int x, int y) {return (x - 1) * 100000 + y;}
bool vis[52 * maxn];
int main()
{
    int q; scanf("%d", &q);
    for (int i = 1; i <= 100000 * 50; i++) f[i] = lst[i] = i;
    while (q--)
    {
        int t, xl, xr, yl, yr; scanf("%d %d %d %d %d", &t, &xl, &yl, &xr, &yr);
        if (t == 1) 
        {
            int u = find(id(xl, yl)), v = find(id(xr, yr));
            printf("%d\n", u == v && vis[u] && vis[v] ? 1 : 0);
            continue;
        }
        if (xl > xr) swap(xl, xr);
        if (yl > yr) swap(yl, yr);
        int faim = find(id(xl, yl));
        for (int x = xl; x <= xr; x++)
        {
            int lstaim = glst(id(x, yr));
            for (int u = id(x, yl); u <= id(x, yr); u++)
            {   
                int nxt = glst(u);
                vis[u] = 1;
                unite_lst(u, lstaim);
                unite_f(u, faim);
                u = nxt;
            }
            int ud = id(x, yl - 1), up = id(x, yr + 1);
            if (yl > 1 && vis[ud]) unite_f(ud, id(x, yl)), unite_lst(ud, id(x, yl));
            if (yr < 100000 && vis[up]) unite_f(up, id(x, yr)), unite_lst(up, id(x, yr)); 
        }
        if (xl > 1)
            for (int u = id(xl - 1, yl); u <= id(xl - 1, yr); u++)
            {
                if (vis[u]) unite_f(u, id(xl, yl));
                u = glst(u);
            }
        if (xr < 50)
            for (int u = id(xr + 1, yl); u <= id(xr + 1, yr); u++)
            {
                if (vis[u]) unite_f(u, id(xl, yl));
                u = glst(u);
            }
    }
    return 0;
}