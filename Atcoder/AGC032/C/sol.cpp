#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int MAXN = 4e5 + 7;
int n, m; 
struct node{int v, next;}e[MAXN];
int head[MAXN], d[MAXN], tot = 1, vis[MAXN];
void add(int u, int v) {e[++tot] = {v, head[u]}; head[u] = tot; d[v]++;}
int a[MAXN << 1], cnt = 0;
void dfs(int u)
{
    for (int &i = head[u]; i; i = e[i].next)
    {
        if (vis[i]) continue;
        vis[i] = vis[i ^ 1] = 1;
        dfs(e[i].v);
    }
    a[++cnt] = u;
}
int pos[MAXN], nxt[MAXN];
int T[MAXN << 2];
inline void pushup(int rt) {T[rt] = min(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = nxt[l]; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int res = 2e9, mid = (l + r) >> 1;
    if (L <= mid) res = min(res, query(lson, l, mid, L, R));
    if (mid <  R) res = min(res, query(rson, mid + 1, r, L, R));
    return res;
}
bool check()
{
    cnt--;
    for (int i = cnt + 1; i <= cnt * 2; i++) a[i] = a[i - cnt];
    for (int i = 1; i <= cnt * 2; i++) nxt[i] = 2e9;
    for (int i = 1; i <= cnt * 2; i++) nxt[pos[a[i]]] = i, pos[a[i]] = i;
    build(1, 1, cnt * 2);
    for (int i = 1; i <= cnt; i++) if (nxt[i] <= i + cnt - 1)
    {
        int pos = query(1, 1, cnt * 2, nxt[i], i + cnt - 1);
        if (pos <= i + cnt - 1) 
        {
            return true;
        }
    }
    return false;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, u, v; i <= m; i++) scanf("%d%d", &u, &v), add(u, v), add(v, u);
    for (int i = 1; i <= n; i++) if (d[i] & 1)
    {
        puts("No");
        return 0;
    }
    dfs(1); 
    check() ? puts("Yes") : puts("No");
    return 0;
}