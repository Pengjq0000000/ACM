#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int MAXN = 1e6 + 7;
struct node{ll val; int p;}T[MAXN << 2];
ll lazy[MAXN << 2];
void pushup(int rt) 
{
    if (T[lson].val >= T[rson].val) T[rt] = T[lson];
    else T[rt] = T[rson];
}
void build(int rt, int l, int r)
{
    T[rt].val = lazy[rt] = 0;
    if (l == r) {T[rt].p = l; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid); build(rson, mid + 1, r);
    pushup(rt);
}
void upd(int rt, ll x) {T[rt].val += x; lazy[rt] += x;}
void pushdown(int rt) 
{
    if (!lazy[rt]) return;
    upd(lson, lazy[rt]); upd(rson, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, ll x)
{
    if (L <= l && r <= R) {upd(rt, x); return;}
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (L <= mid) update(lson, l, mid, L, R, x);
    if (mid <  R) update(rson, mid + 1, r, L, R, x);
    pushup(rt);
}
node query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1; 
    node resl = {(ll)-1e16, -1}, resr = {(ll)-1e16, -1};
    pushdown(rt);
    if (L <= mid) resl = query(lson, l, mid, L, R);
    if (mid <  R) resr = query(rson, mid + 1, r, L, R);
    return resl.val >= resr.val ? resl : resr;
}
vector<int>vec;
inline int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin();}
vector<pii>X[MAXN];
pii p[MAXN]; 
int c[MAXN];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d%d", &p[i].fir, &p[i].sec, &c[i]); 
        if (p[i].fir < p[i].sec) swap(p[i].fir, p[i].sec);
        vec.push_back(p[i].fir); vec.push_back(p[i].sec);
    }
    vec.push_back(0);
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1, x, y; i <= n; i++)
    {
        x = getid(p[i].fir), y = getid(p[i].sec);
        X[x].emplace_back(y, c[i]);
    }
    int N = vec.size(); N--;
    build(1, 0, N);
    ll res = 0; pii ans = {(int)2e9, (int)2e9};
    for (int i = 0; i <= N; i++)
    {
        X[i].emplace_back(i, i == 0 ? -1 : -(vec[i] - vec[i - 1]));
        sort(X[i].begin(), X[i].end());
        ll det = 0;
        for (int j = 0; j < (int)X[i].size() - 1; j++)
        {
            int st = X[i][j].fir, ed = X[i][j + 1].fir - 1;
            det += X[i][j].sec;
            if (st > ed) continue;
            update(1, 0, N, st, ed, -det);
        }
        det += X[i].rbegin()->sec;
        update(1, 0, N, i, N, -det); 
        ll all = -query(1, 0, N, i, i).val; 
        if (res < all + 1) {res = all + 1; ans = {vec[0], vec[i]};}
        if (i == 0) continue;
        node qres = query(1, 0, N, 0, i - 1); 
        if (res < all + qres.val + vec[qres.p + 1] - vec[qres.p]) 
        {
            res = all + qres.val + vec[qres.p + 1] - vec[qres.p]; 
            ans = {vec[qres.p + 1], vec[i]};
        }
    }
    printf("%lld\n", res);
    printf("%d %d %d %d\n", ans.fir, ans.fir, ans.sec, ans.sec);
    return 0;
}