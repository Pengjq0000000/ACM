#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;

int T[maxn << 2], lazy[maxn << 2];

void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
    lazy[rt] = 0;
    if (l == r) {T[rt] = 1;return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void pushdown(int rt, int l ,int r)
{
    if (!lazy[rt]) return;
    int mid = (l + r) >> 1;
    T[rt << 1] = lazy[rt] * (mid - l + 1);
    T[rt << 1 | 1] = lazy[rt] * (r - mid);
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = 0; 
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R)
    {
        T[rt] = (r - l + 1) * val;
        lazy[rt] = val; 
        return;
    }
    pushdown(rt, l, r);
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

int main()
{
    int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        build(1, 1, n);
        while (m--)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            update(1, 1, n, x, y, z);
        }
        //int res = 0;
        //for (int i = 1; i <= n; i++) res += query(1, 1, n, i);
        printf("Case %d: The total value of the hook is %d.\n", ++cas, query(1, 1, n, 1, n));
    }
    return 0;
}

