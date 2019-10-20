#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define ll long long
using namespace std;
const int maxn = 2e5 + 7;
vector<int>vec;
inline int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int sum[maxn];
struct opt{int op, l, r;}Q[maxn];
struct seg_tree
{
    int T[maxn << 2], lazy[maxn << 2];
    void pushup(int rt) {T[rt] = T[lson] + T[rson];}
    void build(int rt, int l, int r)
    {
        T[rt] = lazy[rt] = 0;
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(lson, l, mid);
        build(rson, mid + 1, r);
    }
    void upd(int rt, int len, int v) {T[rt] = (ll)v * len; lazy[rt] = v;}
    void pushdown(int rt, int l, int r)
    {
        if (!lazy[rt]) return;
        int mid = (l + r) >> 1;
        upd(lson, sum[mid + 1] - sum[l], lazy[rt]);
        upd(rson, sum[r + 1] - sum[mid + 1], lazy[rt]);
        lazy[rt] = 0;
    }
    void update(int rt, int l, int r, int L, int R)
    {
        if (L <= l && r <= R) {upd(rt, sum[r + 1] - sum[l], 1); return;}
        pushdown(rt, l, r);
        int mid = (l + r) >> 1;
        if (L <= mid) update(lson, l, mid, L, R);
        if (mid <  R) update(rson, mid + 1, r, L, R);
        pushup(rt);
    }
    int query(int rt, int l, int r, int L, int R)
    {
        if (L <= l && r <= R) return T[rt];
        pushdown(rt, l, r);
        int mid = (l + r) >> 1, res = 0;
        if (L <= mid) res += query(lson, l, mid, L, R);
        if (mid <  R) res += query(rson, mid + 1, r, L, R);
        return res;
    }
}T1, T2;
int main()
{
    int n, m, q; 
    while (~scanf("%d%d%d", &n, &m, &q))
    {
        vec.clear();
        for (int i = 1; i <= q; i++)
        {
            scanf("%d%d%d", &Q[i].op, &Q[i].l, &Q[i].r);
            Q[i].r++;
            vec.push_back(Q[i].l);
            vec.push_back(Q[i].r);
        }
        vec.push_back(n + 1); vec.push_back(m + 1);
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int N = vec.size();
        sum[0] = 0;
        for (int i = 1; i <= N; i++) sum[i] = vec[i - 1];
        N--;
        T1.build(1, 1, N); T2.build(1, 1, N);
        ll ans = (ll)n * m;
        for (int i = 1; i <= q; i++)
        {
            int op = Q[i].op;
            int l = getid(Q[i].l), r = getid(Q[i].r) - 1;
            int x, X, Y; ll det;
            if (op == 1)
            {
                x = (Q[i].r - Q[i].l) - T1.query(1, 1, N, l, r);
                X = T1.T[1], Y = max(0, T2.T[1] - 1);
                det = (ll)x * (m - 1 - Y);
                if (X == 0) det += Y;
                ans -= det;
                T1.update(1, 1, N, l, r);
            }
            else 
            {
                x = (Q[i].r - Q[i].l) - T2.query(1, 1, N, l, r);
                X = T2.T[1], Y = max(0, T1.T[1] - 1);
                det = (ll)x * (n - 1 - Y);
                if (X == 0) det += Y;
                ans -= det;
                T2.update(1, 1, N, l, r);
            }
            //printf("x=%d X=%d Y=%d det=%lld\n", x, X, Y, det);
            printf("%lld\n", ans);
        }
    }
    return 0;
}