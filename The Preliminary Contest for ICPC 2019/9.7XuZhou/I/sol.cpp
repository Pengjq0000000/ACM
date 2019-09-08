#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define pii pair<int, int>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
LL T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == 0) return;
    int mid = (l + r) >> 1;
    lazy[lson] += lazy[rt];
    T[lson] += lazy[rt] * (mid - l + 1);
    lazy[rson] += lazy[rt];
    T[rson] += lazy[rt] * (r - mid);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R)
    {
        T[rt] += (r - l + 1) * val;
        lazy[rt] += val;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R, val);
    if (mid <  R) update(rson, mid + 1, r, L, R, val);
    pushup(rt);
}

LL query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(lson, l, mid, pos);
    else return query(rson, mid + 1, r, pos);
}
int n, q, a[maxn], pos[maxn];
LL ans[maxn];
vector<int>dpos[maxn];
vector<pii> qR[maxn];
int main()
{
	scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]), pos[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = a[i]; j <= n; j += a[i])
        {
            dpos[j].pb(i);
            dpos[a[i]].pb(pos[j]);
        }
    }
    for (int i = 1, l, r; i <= q; i++)
    {
        scanf("%d%d", &l, &r);
        qR[r].pb(make_pair(l, i));
    }
    for (int R = 1; R <= n; R++)
    {
        for (int p : dpos[a[R]])
        {
            if (p < R) update(1, 1, n, 1, p, 1);
        }
        for (pii x : qR[R])
        {
            ans[x.second] = query(1, 1, n, x.first);
        }
    }
    for (int i = 1; i <= q; i++)
        printf("%lld\n", ans[i]);
	return 0;
}
