#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
LL T[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void build(int rt, int l, int r)
{
    T[rt] = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int rt, int l, int r, int pos, LL val)
{
    if (l == r) {T[rt] += val; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) / 2;
    LL res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}
int n, m, p;
LL a[maxn];
LL get(int x, int y)
{
    LL val;
    if (x + y <= n)
    {
        if (y <= x) val = (a[y] * a[y] + 1 + x - y);
        else val = (a[x] * a[x] + 1 + x - y);
    }
    else
    {
        if (x >= y) val = (a[x] * a[x] + y - x);
        else val = (a[y - 1] * a[y - 1] + y - x);
    }
    return (LL)n * n - val + 1;
}
LL change(LL val)
{
    LL res = 0;
    while (val) {res += val % 10; val /= 10;}
    return res;
}
struct pp
{
    int id, l, r, op;
};
vector<pp>q[maxn];
vector<pair<int, LL> >Pt[maxn];
LL ans[maxn];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &p);
        int d = -1;
        for (int i = n / 2 + 1; i;)
        {
            a[i] = abs(d);
            i += d; d *= -1;
            d += d / abs(d);
        }
        build(1, 0, n);
        for (int i = 0; i <= n; i++) Pt[i].clear(), q[i].clear();
        for (int i = 1, x, y; i <= m; i++)
        {
            scanf("%d%d", &x, &y);
            LL val = get(x, y);
            //printf("%lld\n", val);
            Pt[x].pb(make_pair(y, change(val)));
        }
        for (int i = 1; i <= p; i++)
        {
            int xl, xr, yl, yr;
            scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
            q[xr].pb({i, yl, yr, 1});
            q[xl - 1].pb({i, yl, yr, -1});
        }
        for (int i = 1; i <= p; i++) ans[i] = 0;
        for (int i = 0; i <= n; i++)
        {
            for (auto x : Pt[i])
            {
                update(1, 0, n, x.fir, x.sec);
                //printf("%d - upd:%d %lld\n", i, x.fir, x.sec);
            }
            for (auto x : q[i])
            {
                ans[x.id] += query(1, 0, n, x.l, x.r) * x.op;
                //printf("%d-l=%d r=%d:%lld\n", i, x.l, x.r, query(1, 0, n, x.l, x.r));
            }
        }
        for (int i = 1; i <= p; i++) printf("%lld\n", ans[i]);
    }
	return 0;
}
