#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
ll T[MAXN << 2], lazy[MAXN << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void upd(int rt, ll v) {T[rt] += v; lazy[rt] += v;}
void pushdown(int rt)
{
    if (!lazy[rt]) return;
    upd(lson, lazy[rt]); 
    upd(rson, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, ll v)
{
    if (L <= l && r <= R) {upd(rt, v); return;}
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (L <= mid) update(lson, l, mid, L, R, v);
    if (mid <  R) update(rson, mid + 1, r, L, R, v);
    pushup(rt);
}
ll query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1; ll res = 0;
    pushdown(rt);
    if (L <= mid) res = max(res, query(lson, l, mid, L, R));
    if (mid <  R) res = max(res, query(rson, mid + 1, r, L, R));
    return res;
}
vector<pii>p[MAXN];
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1, x, y, w; i <= m; i++)
    {
        scanf("%d%d%d", &x, &y, &w);
        p[y].emplace_back(x, w);
    }
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, n, i, i, query(1, 1, n, 1, i));
        for (auto x : p[i]) update(1, 1, n, x.fir, i, x.sec);
    }
    printf("%lld\n", max(0ll, query(1, 1, n, 1, n)));
    return 0;
}