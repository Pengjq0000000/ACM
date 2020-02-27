#include<bits/stdc++.h>
#define ll long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int MAXN = 2e5 + 7;
const ll INF = 1e17;
int x[MAXN];
ll y[MAXN];
struct segt
{
    ll T[MAXN << 2], lazy[MAXN << 2];
    void pushup(int rt) {T[rt] = min(T[lson], T[rson]);}
    void build(int rt, int l, int r, int sig)
    {
        if (l == r) {T[rt] = y[l] + sig * l; return;}
        int mid = (l + r) >> 1;
        build(lson, l, mid, sig);
        build(rson, mid + 1, r, sig);
        pushup(rt);
    }
    void update(int rt, ll v) {T[rt] += v; lazy[rt] += v; return;}
    void pushdown(int rt)
    {
        if (!lazy[rt]) return;
        update(lson, lazy[rt]);
        update(rson, lazy[rt]);
        lazy[rt] = 0;
    }
    void modify(int rt, int l, int r, int L, int R, ll v)
    {
        if (L <= l && r <= R) {update(rt, v); return;}
        pushdown(rt);
        int mid = (l + r) >> 1;
        if (L <= mid) modify(lson, l, mid, L, R, v);
        if (mid <  R) modify(rson, mid + 1, r, L, R, v);
        pushup(rt);
    }
    void modify_p(int rt, int l, int r, int pos, ll v)
    {
        if (l == r) {T[rt] = min(T[rt], v); return;}
        pushdown(rt);
        int mid = (l + r) >> 1;
        if (pos <= mid) modify_p(lson, l, mid, pos, v);
        else modify_p(rson, mid + 1, r, pos, v);
        pushup(rt);
    }
    ll query(int rt, int l, int r, int L, int R)
    {
        if (L <= l && r <= R) return T[rt];
        pushdown(rt);
        int mid = (l + r) >> 1;
        ll res = 1e18;
        if (L <= mid) res = min(res, query(lson, l, mid, L, R));
        if (mid <  R) res = min(res, query(rson, mid + 1, r, L, R));
        return res;
    }
}dp[3];
int main()
{
    int n, q; scanf("%d%d", &n, &q); n++;
    int A, B; scanf("%d%d", &A, &B);
    for (int i = 1; i <= q; i++) scanf("%d", &x[i]);
    for (int i = 1; i <= n; i++) y[i] = INF;
    y[A] = abs(x[1] - B); 
    y[B] = abs(x[1] - A);
    dp[0].build(1, 1, n, 0);
    dp[1].build(1, 1, n, 1);
    dp[2].build(1, 1, n, -1);
    for (int i = 2; i <= q; i++)
    {
        ll res = dp[1].query(1, 1, n, x[i] + 1, n) - x[i];
        res = min(res, dp[2].query(1, 1, n, 1, x[i]) + x[i]);
        dp[0].modify(1, 1, n, 1, n, abs(x[i - 1] - x[i]));
        dp[0].modify_p(1, 1, n, x[i - 1], res);
        dp[1].modify(1, 1, n, 1, n, abs(x[i - 1] - x[i]));
        dp[1].modify_p(1, 1, n, x[i - 1], res + x[i - 1]);
        dp[2].modify(1, 1, n, 1, n, abs(x[i - 1] - x[i]));
        dp[2].modify_p(1, 1, n, x[i - 1], res - x[i - 1]);
    }
    printf("%lld\n", dp[0].query(1, 1, n, 1, n));
    return 0;
}