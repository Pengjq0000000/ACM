#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
struct node {int l, r; LL sum, tg;}T[maxn * 65];
int tot = 0, root[maxn];
void update(int &rt, int pre, int l, int r, int L, int R, int val)
{
    T[rt = ++tot] = T[pre];
    T[rt].sum += (LL)val * (R - L + 1);
    if (L <= l && r <= R) {T[rt].tg += val; return;}
    int mid = (l + r) >> 1;
    if (L <= mid) update(T[rt].l, T[pre].l, l, mid, L, min(R, mid), val);
    if (mid <  R) update(T[rt].r, T[pre].r, mid + 1, r, max(L, mid + 1), R, val);
}
LL query(int rt, int pre, int l, int r, int L, int R, LL add)
{
    if (L <= l && r <= R) return T[rt].sum - T[pre].sum + add * (r - l + 1);
    int mid = (l + r) >> 1; LL res = 0;
    add += T[rt].tg - T[pre].tg;
    if (L <= mid) res += query(T[rt].l, T[pre].l, l, mid, L, min(R, mid), add);
    if (mid <  R) res += query(T[rt].r, T[pre].r, mid + 1, r, max(L, mid + 1), R, add);
    return res;
}
vector<int>E[maxn];
int in[maxn], out[maxn], tim = 0, l[maxn], r[maxn];
int t[maxn];
void dfs(int u)
{
    in[u] = ++tim; t[tim] = u;
    for (int v : E[u]) dfs(v);
    out[u] = tim;
}
int main()
{
	int n, m, q; scanf("%d%d", &n, &m);
    l[1] = 1, r[1] = n;
    for (int i = 1, u, v; i <= m; i++)
    {
        scanf("%d%d", &u, &v); E[u].pb(v);
        scanf("%d%d", &l[v], &r[v]);
    }
    dfs(1);
    for (int i = 1; i <= m + 1; i++)
    {
        int u = t[i];
        update(root[i], root[i - 1], 1, n, l[u], r[u], 1);
    }
    scanf("%d", &q);
    while (q--)
    {
        int x, ql, qr; scanf("%d%d%d", &x, &ql, &qr);
        printf("%lld\n", query(root[out[x]], root[in[x] - 1], 1, n, ql, qr, 0));
    }
	return 0;
}
