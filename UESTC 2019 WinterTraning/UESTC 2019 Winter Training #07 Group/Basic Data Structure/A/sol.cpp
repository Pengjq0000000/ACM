#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
const int INF = mod;
struct sg
{
    int l, r, type;
    bool operator < (const sg &rhs) const
    {
        if (l == rhs.l) return r < rhs.r;
        return l < rhs.l;
    }
}seg[maxn];
struct node{int max, add, alt;} T[maxn << 2][2];
int ans[maxn];

void pushup(int rt, int k) {T[rt][k].max = max(T[rt << 1][k].max, T[rt << 1 | 1][k].max);}
void mark(int rt, int k, int type, int val)
{
    if (type == 1)  // add
    {
        T[rt][k].add += val; T[rt][k].alt += val;
        T[rt][k].max += val;
    }
    else // alt
    {
        T[rt][k].max = max(T[rt][k].max, val);
        T[rt][k].alt = max(T[rt][k].alt, val);
    }
}

void pushdown(int rt, int k)
{
    if (T[rt][k].add > 0)
    {
        mark(rt << 1, k, 1, T[rt][k].add);
        mark(rt << 1 | 1, k, 1, T[rt][k].add);
        T[rt][k].add = 0;
    }
    if (T[rt][k].alt > 0)
    {
        mark(rt << 1, k, 2, T[rt][k].alt);
        mark(rt << 1 | 1, k, 2, T[rt][k].alt);
        T[rt][k].alt = 0;
    }
}

void update_add(int rt, int l, int r, int L, int R, int k, int val)
{
    if (L <= l && r <= R)
    {
        mark(rt, k, 1, val);
        return;
    }
    pushdown(rt, k);
    int mid = (l + r) >> 1;
    if (L <= mid) update_add(rt << 1, l, mid, L, R, k, val);
    if (mid <  R) update_add(rt << 1 | 1, mid + 1, r, L, R, k, val);
    pushup(rt, k);
}

void update_alt(int rt, int l, int r, int L, int R, int k, int val)
{
    if (L <= l && r <= R)
    {
        mark(rt, k, 2, val);
        return;
    }
    
    pushdown(rt, k);
    int mid = (l + r) >> 1;
    if (L <= mid) update_alt(rt << 1, l, mid, L, R, k, val);
    if (mid <  R) update_alt(rt << 1 | 1, mid + 1, r, L, R, k, val);
    pushup(rt, k);
}

int query(int rt, int l, int r, int pos, int k)
{
    if (l == r) return T[rt][k].max;
    pushdown(rt, k);
    int mid = (l + r) >> 1;
    int res = -INF;
    if (pos <= mid) res = max(res, query(rt << 1, l, mid, pos, k));
    else res = max(res, query(rt << 1 | 1, mid + 1, r, pos, k));
    return res;
}

void solve()
{
    int n, m; scanf("%d %d", &n, &m);
    MEM(T, 0);
    for (int i = 1; i <= m; i++)
    {
        char s[3]; scanf(" %s", s);
        if (s[0] == 'E' || s[0] == 'C') seg[i].type = 0;
        else seg[i].type = 1;
    }
    for (int i = 1; i <= m; i++) scanf("%d", &seg[i].l);
    for (int i = 1; i <= m; i++) scanf("%d", &seg[i].r);
    sort(seg + 1, seg + 1 + m);
    for (int i = 1; i <= m; i++)
    {
        if (seg[i].l > seg[i].r) continue;
        update_add(1, 1, n, seg[i].r, n, seg[i].type, 1);
        int tmp = query(1, 1, n, seg[i].l, 1 - seg[i].type) + 1;
        update_alt(1, 1, n, seg[i].r, n, seg[i].type, tmp);
    }
    for (int i = 1; i <= m; i++) ans[i] = INF;
    for (int pos = n; pos >= 1; pos--)
    {
        int res1 = query(1, 1, n, pos, 0);
        int res2 = query(1, 1, n, pos, 1);
        ans[res1] = ans[res2] = pos;
    }
    for (int i = m - 1; i >= 1; i--) ans[i] = min(ans[i], ans[i+1]);
    for (int i = 1; i <= m; i++)
        printf("%d ", ans[i] == INF ? -1 : ans[i]);
    printf("\n");
}
int main()
{
    int T; scanf("%d", &T);
    while (T--) solve();
    return 0;
}


