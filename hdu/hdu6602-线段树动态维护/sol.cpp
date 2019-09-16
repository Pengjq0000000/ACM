#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = min(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    T[rt] = lazy[rt] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void upd(int rt, int tag) {T[rt] += tag; lazy[rt] += tag;}
void pushdown(int rt)
{
    if (lazy[rt] == 0) return;
    upd(lson, lazy[rt]); upd(rson, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {upd(rt, val); return;}
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R, val);
    if (mid <  R) update(rson, mid + 1, r, L, R, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    int mid = (l + r) >> 1;
    if (L <= l && r <= R)
    {
        if (l == r) return T[rt] == 0 ? l : -1;
        pushdown(rt);
        if (T[lson] <= T[rson]) return query(lson, l, mid, L, R);
        else return query(rson, mid + 1, r, L, R);
    }
    pushdown(rt);
    int res = -1;
    if (L <= mid) res = query(lson, l, mid, L, R);
    if (mid < R && res == -1) res = query(rson, mid + 1, r, L, R);
    return res;
}
int a[maxn];
int lst[maxn], pre[maxn], nxt[maxn], prek[maxn];
int p[maxn], cnt[maxn];
void print(int *a, int n)
{
    for (int i = 1; i <= n; i++)
        printf("%d%c", a[i], i == n ? '\n' : ' ');
}
int main()
{
    int n, c, k;
    while (~scanf("%d%d%d", &n, &c, &k))
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), pre[i] = nxt[i] = prek[i] = 0;
        for (int i = 1; i <= c; i++) p[i] = lst[i] = cnt[i] = 0;
        int col;
        for (int i = 1; i <= n; i++)
        {
            col = a[i];
            nxt[lst[col]] = i; pre[i] = lst[col]; lst[col] = i;
            if (!p[col]) p[col] = i;
        }
        for (int i = 1; i <= n; i++)
        {
            col = a[i];
            cnt[col]++;
            if (cnt[col] >= k) prek[i] = p[col], p[col] = nxt[p[col]];
        }
        build(1, 1, n);
        int ans = 0;
        //print(pre, n);
        for (int i = 1; i <= n; i++)
        {
            update(1, 1, n, pre[i] + 1, i, 1);
            if (prek[i]) update(1, 1, n, pre[prek[i]] + 1, prek[i], -1);
            int pos = query(1, 1, n, 1, i);
            if (pos > 0) ans = max(ans, i - pos + 1);
        }
        printf("%d\n", ans);
    }
    return 0;
}
