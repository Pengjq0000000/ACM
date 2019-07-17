#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL T[maxn << 2];
LL a[maxn], b[maxn];
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
    if (l == r) 
	{
		T[rt] = max(0ll, b[l]); 
		return;
	}
    int mid= (l + r) / 2;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos)
{
    if (l == r)
    {
        T[rt] = max(0ll, b[l]);
        return ;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos);
    else update(rt << 1 | 1, mid + 1, r, pos);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) / 2;
    LL res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R);
    if (mid < R) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}
LL TT[maxn << 2];
void pushup_TT(int rt) {TT[rt] = TT[rt << 1] + TT[rt << 1 | 1];}
void build_TT(int rt, int l, int r)
{
    if (l == r) {TT[rt] = b[l];return ;}
    int mid= (l + r) / 2;
    build_TT(rt << 1, l, mid);
    build_TT(rt << 1 | 1, mid + 1, r);
    pushup_TT(rt);
}
void update_TT(int rt, int l, int r, int pos)
{
    if (l == r)
    {
        TT[rt] = b[l];
        return ;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update_TT(rt << 1, l, mid, pos);
    else update_TT(rt << 1 | 1, mid + 1, r, pos);
    pushup_TT(rt);
}
LL query_TT(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return TT[rt];
    int mid = (l + r) / 2;
    LL res = 0;
    if (L <= mid) res += query_TT(rt << 1, l, mid, L, R);
    if (mid <  R) res += query_TT(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}

int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), b[i] = a[i] - a[i - 1];
        b[n + 1] = -a[n];
        build(1, 1, n + 1);
        build_TT(1, 1, n + 1);
        while (m--)
        {
            int op; scanf("%d", &op);
            if (op == 2)
            {
                int l, r; scanf("%d%d", &l, &r);
                LL ans = query(1, 1, n + 1, l, r);
                LL tmp = 0;
                if (l > 1)
                {
                    tmp = query_TT(1, 1, n + 1, 1, l - 1);
                }
                ans = ans + tmp;
                if (b[l] < 0) ans += b[l];
                printf("%lld\n", ans);
            }
            else
            {
                int l, r, k; scanf("%d%d%d", &l, &r, &k);
                b[l] += k; b[r + 1] -= k;
                update(1, 1, n + 1, l);
                update(1, 1, n + 1, r + 1);
                update_TT(1, 1, n + 1, l);
                update_TT(1, 1, n + 1, r + 1);
            }
        }
    }
	return 0;
}