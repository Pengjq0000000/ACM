#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, deg[maxn], in[maxn], out[maxn], id[maxn];
LL k, a[maxn];
vector<int>E[maxn];
vector<LL>vec;
int tim, sz[maxn];
void dfs(int u, int fa)
{
    in[u] = ++tim; id[tim] = u;
    for (int v : E[u]) 
        if (v != fa) 
        {
            dfs(v, u);
        }
    out[u] = tim;
}
struct node{int l, r, sum;}T[maxn * 20];
int root[maxn], cnt;
int getid(LL x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
void update(int &rt, int pre, int l, int r, int pos)
{
    T[rt = ++cnt] = T[pre];
    T[rt].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos);
    else update(T[rt].r, T[pre].r, mid + 1, r, pos);
}
int query(int rt, int pre, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].sum - T[pre].sum;
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) res += query(T[rt].l, T[pre].l, l, mid, L, R);
    if (mid <  R) res += query(T[rt].r, T[pre].r, mid + 1, r, L, R);
    return res;
}
int main()
{
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%lld", &n, &k);
        vec.clear();
        for (int i = 1; i <= n; i++) 
        {
            scanf("%lld", &a[i]); vec.pb(a[i]);
            if (a[i] != 0) vec.pb(k / a[i]);
            deg[i] = 0; E[i].clear();
            root[i] = 0;
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        for (int i = 1, u, v; i < n; i++)
        {
            scanf("%d%d", &u, &v);
            E[u].pb(v); E[v].pb(u);
            deg[v]++;
        }
        int rt = 0;
        for (int i = 1; i <= n; i++) if (!deg[i]) {rt = i; break;}
        tim = 0; dfs(rt, 0);
        int N = 2 * n; cnt = 0;
        for (int i = 1; i <= n; i++) 
            update(root[i], root[i - 1], 1, N, getid(a[id[i]]));
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            if (a[i] == 0)
            {
                ans += query(root[out[i]], root[in[i] - 1], 1, N, 1, N);
                ans--;
            }
            else 
            {
                ans += query(root[out[i]], root[in[i] - 1], 1, N, 1, getid(k / a[i]));
                if (a[i] <= k / a[i]) ans--;
            }
        }
        printf("%lld\n", ans);
        for (int i = 0; i <= cnt; i++) T[i].l = T[i].r = T[i].sum = 0;
    }
	return 0;
}
