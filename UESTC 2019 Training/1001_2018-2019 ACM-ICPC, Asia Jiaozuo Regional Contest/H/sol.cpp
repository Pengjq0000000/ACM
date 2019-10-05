#include <bits/stdc++.h>
using namespace std;
const int MAXN = 400100;
struct SufArr
{
    int n, N;
    int a[MAXN], Rank[MAXN + 1], SA[MAXN + 2], tmp[MAXN], height[MAXN + 3];
    int cnt[1000010];
    inline bool cmp(int x, int y, int s) { return Rank[x] == Rank[y] && Rank[x + s] == Rank[y + s]; }
    void init()
    {
        for (int i = 1; i <= n; ++i) a[i] = SA[i] = Rank[i] = height[i] = tmp[i] = 0;
        for (int i = 0; i <= n; ++i) cnt[i] = 0;
    }
    void build()
    {
        int i = 1, p = 1, s;
        for (i = 1; i <= n; ++i) ++cnt[a[i]];
        for (i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
        for (i = n; i; --i) SA[cnt[a[i]]--] = i;
        for (i = 1; i <= n; ++i)
        {
            if (i != 1 && a[SA[i]] != a[SA[i - 1]]) ++p;
            Rank[SA[i]] = p;
        }
        for (s = 1; s <= n && p < n; s <<= 1)
        {
            for (i = 1; i <= n; ++i) cnt[i] = 0;
            for (i = 1; i <= n; ++i) ++cnt[Rank[i + s]];
            for (i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
            for (i = n; i; --i) tmp[cnt[Rank[i + s]]--] = i;
            for (i = 1; i <= n; ++i) cnt[i] = 0;
            for (i = 1; i <= n; ++i) ++cnt[Rank[i]];
            for (i = 1; i <= n; ++i) cnt[i] += cnt[i - 1];
            for (i = n; i; --i) SA[cnt[Rank[tmp[i]]]--] = tmp[i];
            p = 1;
            for (i = 1; i <= n; ++i)
            {
                if (i != 1 && !cmp(SA[i], SA[i - 1], s)) ++p;
                tmp[SA[i]] = p;
            }
            for (i = 1; i <= n; ++i) Rank[i] = tmp[i];
        }
    }
    void calc_height()
    {
        int i, u;
        for (i = 1; i <= n; ++i)
        {
            u = Rank[i]; //if (u == 1) continue;
            height[u] = max(0, height[Rank[i - 1]] - 1);
            assert(u >= 0);
            while (a[i + height[u]] == a[SA[u - 1] + height[u]]) ++height[u];
        }
    }
} sa;
int a[MAXN], n, qry_p[MAXN], upd_p[MAXN];

#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define LL long long
LL T[MAXN << 2], lazy[MAXN << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void build(int rt, int l, int r)
{
    lazy[rt] = -1; T[rt] = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void upd(int rt, int l, int r, LL v) {T[rt] = v * (r - l + 1); lazy[rt] = v;}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == -1) return;
    int mid = (l + r) >> 1;
    upd(lson, l, mid, lazy[rt]); 
    upd(rson, mid + 1, r, lazy[rt]);
    lazy[rt] = -1;
}
void update(int rt, int l, int r, int L, int R, LL v)
{
    if (L <= l && r <= R) {upd(rt, l, r, v); return;}
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R, v);
    if (mid <  R) update(rson, mid + 1, r, L, R, v);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1; LL res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}
int stk[MAXN], top;

vector<int>vec;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        vec.clear();
        for (int i = 1; i <= n; ++i)
        {
            scanf("%d", &a[i]);
            vec.push_back(a[i]);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for (int i = 1; i <= n; i++) sa.a[n - i + 1] = getid(a[i]);
        sa.N = vec.size();
        sa.n = n;
        sa.build();
        sa.calc_height();
        for (int i = 1; i <= n; ++i) qry_p[i] = i - sa.height[sa.Rank[n - i + 1]];
        top = 0;
        for (int i = 1; i <= n; i++)
        {
            while (top && a[stk[top]] < a[i]) top--;
            if (top) upd_p[i] = stk[top] + 1;
            else upd_p[i] = 1;
            stk[++top] = i;
        }
        LL ans = 0;
        build(1, 1, n);
        for (int R = 1; R <= n; R++)
        {
            update(1, 1, n, upd_p[R], R, a[R]);
            if (qry_p[R] >= 1) 
            {
                LL det = query(1, 1, n, 1, qry_p[R]);
                assert(det > 0);
                ans += det;
            }
        }
        printf("%lld\n", ans);
        sa.init();
    }
}