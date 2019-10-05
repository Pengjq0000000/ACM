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
int T[maxn << 2], a[maxn];
void pushup(int rt) {T[rt] = min(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = a[l]; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R, int val)
{
    int mid = (l + r) >> 1;
    if (L <= l && r <= R)
    {
        if (l == r) return T[rt] <= val ? l : -1;
        if (T[lson] <= val) return query(lson, l, mid, L, R, val);
        else return query(rson, mid + 1, r, L, R, val);
    }
    int res = -1;
    if (L <= mid) res = query(lson, l, mid, L, R, val);
    if (res > 0) return res;
    if (mid <  R) res = query(rson, mid + 1, r, L, R, val);
    return res; 
}
int main()
{
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        int q; scanf("%d", &q);
        while (q--)
        {
            int l, r; scanf("%d%d", &l, &r);
            int now = l, ans = a[l];
            while (1)
            {
                int pos = query(1, 1, n, now + 1, r, ans);
                if (pos == -1) {printf("%d\n", ans); break;}
                ans %= a[pos];
                now = pos;
            }
        }
    }
	return 0;
}
