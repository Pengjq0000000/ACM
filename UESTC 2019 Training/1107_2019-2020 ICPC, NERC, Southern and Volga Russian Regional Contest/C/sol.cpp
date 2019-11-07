#include<bits/stdc++.h>
#define ll long long
#define fir first
#define sec second
#define pil pair<int, long long>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int maxn = 2e5 + 7;
ll T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void upd(int rt, ll v) {T[rt] += v; lazy[rt] += v;}
void pushdown(int rt) {upd(lson, lazy[rt]); upd(rson, lazy[rt]); lazy[rt] = 0;}
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
    int mid = (l + r) >> 1;
    pushdown(rt);
    ll res = -1e18;
    if (L <= mid) res = max(res, query(lson, l, mid, L, R));
    if (mid <  R) res = max(res, query(rson, mid + 1, r, L, R));
    return res; 
}
int getpos(int rt, int l, int r, ll v)
{
    if (l == r) return l;
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (T[lson] == v) return getpos(lson, l, mid, v);
    else return getpos(rson, mid + 1, r, v);
}
struct node{int x; ll y; int id;};
vector<node>p[maxn];
int S[maxn];
const int N = 200000;
int main()
{
    int n; ll k; scanf("%d%lld", &n, &k);
    for (int i = 1; i <= n; i++)
    {
        int l, r; ll s; scanf("%d%d%lld", &l, &r, &s);
        p[r].push_back({l, s, i});
    }
    ll ans = 0; 
    int ansl = -1, ansr = 0;
    for (int R = 1; R <= N; R++)
    {
        update(1, 1, N, 1, R, -k);
        for (auto pt : p[R]) update(1, 1, N, 1, pt.x, pt.y);
        ll res = query(1, 1, N, 1, R);
        if (res > ans) 
        {
            ans = res;
            ansl = getpos(1, 1, N, res); 
            ansr = R;
        }
    }
    if (ans == 0) {puts("0"); return 0;}
    int cnt = 0;
    for (int i = ansl; i <= ansr; i++)
    {
        for (auto pt : p[i]) if (pt.x >= ansl) S[++cnt] = pt.id;
    }
    printf("%lld %d %d %d\n", ans, ansl, ansr, cnt);
    for (int i = 1; i <= cnt; i++) printf("%d%c", S[i], i == cnt ? '\n' : ' ');
    return 0;
}