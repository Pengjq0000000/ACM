#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 50007;
int T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
    lazy[rt] = -1;
    if (l == r) {T[rt] = 1; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == -1) return;
    int mid = (l + r) >> 1;
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    T[rt << 1] = (mid - l + 1) * lazy[rt];
    T[rt << 1 | 1] = (r - mid) * lazy[rt];
    lazy[rt] = -1;
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R)
    {
        T[rt] = (r - l + 1) * val;
        lazy[rt] = val;
        return;
    }
    pushdown(rt, l ,r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R);
    if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}
int cur;
void queryl(int rt, int l, int r, int L, int R)
{
    if (l == r) {if (T[rt] >0) cur = min(cur, l); return; }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= l && r <= R)
    {
        if (T[rt << 1] > 0) queryl(rt << 1, l, mid, L, R);
        else queryl(rt << 1 | 1, mid + 1, r, L, R);
        return;
    }
    if (L <= mid) queryl(rt << 1, l, mid, L, R);
    if (mid <  R) queryl(rt << 1 | 1, mid + 1, r, L, R);
}
int queryr(int x, int n, int k)
{
    int l = x, r = n;
    while (l < r)
    {
        int mid = (l + r) >> 1;
        int tmp = query(1, 1, n, x, mid);
        if (tmp >= k) r = mid;
        else l = mid + 1;
    }
    return l;
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        int n, m; scanf("%d%d", &n, &m);
        build(1, 1, n);
        while (m--)
        {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            x++;
            if (op == 1)
            {
                cur = n + 1; queryl(1, 1, n, x, n);
                int l = cur;
                if (l == n + 1)
                {
                    printf("Can not put any one.\n");
                    continue;
                }
                int r = queryr(l, n, min(y, query(1, 1, n, x, n)));
                printf("%d %d\n", l - 1, r - 1);
                update(1, 1, n, l, r, 0);
            }
            else if (op == 2)
            {
                y++;
                printf("%d\n", y - x + 1 - query(1, 1, n, x, y));
                update(1, 1, n, x, y, 1);
            }
        }
        puts("");
    }
    return 0;
}

/*
2
10 5
1 3 5
2 4 5
1 1 8
2 3 6
1 8 8
10 6
1 2 5
2 3 4
1 0 8
2 2 5
1 4 4
1 2 3
*/

