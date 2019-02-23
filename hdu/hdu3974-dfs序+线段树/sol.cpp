#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 50007;
struct node{int v, next;}e[maxn];
int head[maxn], tot;
void add(int u, int v)
{
    ++tot;
    e[tot].v = v; e[tot].next = head[u];
    head[u] = tot;
}
int T[maxn << 2], lazy[maxn << 2], deg[maxn], in[maxn], out[maxn], cnt;


void build(int rt, int l, int r)
{
    lazy[rt] = -1;
    if (l == r) {T[rt] = -1; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void pushdown(int rt)
{
    if (lazy[rt] == -1) return;
    T[rt << 1] = T[rt << 1 | 1] = lazy[rt];
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = -1;
} 
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {T[rt] = lazy[rt] = val; return;}
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
}
int query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}

void dfs(int u, int fa)
{
    in[u] = ++cnt;
    for (int i = head[u]; i; i = e[i].next)
    {
        int v = e[i].v;
        if (v == fa) continue;
        dfs(v, u);
    }
    out[u] = cnt;
}
int main()
{
    int t, cas = 0; scanf("%d", &t);
    while (t--)
    {
        printf("Case #%d:\n", ++cas);
        MEM(head, 0); cnt = tot = 0;
        MEM(deg, 0);
        int n; scanf("%d", &n);
        for (int i = 1; i < n; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
            add(v, u); deg[u]++;
        }
        int root = 0;
        for (int i = 1; i <= n; i++) if (deg[i] == 0) {root = i; break;}
        dfs(root, 0);
        build(1, 1, n);
        int m; scanf("%d", &m);
        while (m--)
        {
            char s[2]; int x, y;
            scanf(" %s", s);
            if (s[0] == 'C')
            {
                scanf("%d", &x);
                printf("%d\n", query(1, 1, n, in[x]));
            }
            else if (s[0] == 'T')
            {
                scanf("%d%d", &x, &y);
                update(1, 1, n, in[x], out[x], y);
            }
        }
    }
    return 0;
}

