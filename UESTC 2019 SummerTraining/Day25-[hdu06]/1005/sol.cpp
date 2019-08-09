#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2007;
vector<int>xv, yv;
LL sum[maxn][maxn], w[maxn][maxn];
int x[maxn], y[maxn], ww[maxn];
vector<int>p[maxn];

struct node
{
    LL suf, pre, res, sum;
}T[maxn << 2];
void pushup(int rt)
{
    T[rt].suf = max(T[rt << 1 | 1].suf, T[rt << 1 | 1].sum + T[rt << 1].suf);
    T[rt].pre = max(T[rt << 1].pre, T[rt << 1].sum + T[rt << 1 | 1].pre);
    T[rt].res = max(T[rt << 1].res, T[rt << 1 | 1].res);
    T[rt].res = max(T[rt].res, T[rt << 1 | 1].pre + T[rt << 1].suf);
    T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
}
void build(int rt, int l, int r)
{
    T[rt].suf = T[rt].pre = T[rt].res = T[rt].sum = 0;
    if (l == r) return;
    int mid = (l + r) / 2;
    build(rt << 1, l , mid);
    build(rt << 1 | 1, mid + 1, r); 
}
void update(int rt, int l, int r, int pos, LL x)
{
    if (l == r) 
    {
        T[rt].sum += x;
        T[rt].pre = T[rt].suf = T[rt].res = max(0ll, T[rt].sum);
        return;
    }
    int mid = (l + r) / 2;
    if (pos <= mid) update(rt << 1, l, mid, pos, x);
    else update(rt << 1 | 1, mid + 1, r, pos, x);
    pushup(rt);
}
int main()
{
	int tt; scanf("%d", &tt);
    while (tt--)
    {
        xv.clear(); yv.clear();
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d%d%d", &x[i], &y[i], &ww[i]);
            xv.pb(x[i]); yv.pb(y[i]);
        }
        sort(xv.begin(), xv.end()); xv.erase(unique(xv.begin(), xv.end()), xv.end());
        sort(yv.begin(), yv.end()); yv.erase(unique(yv.begin(), yv.end()), yv.end());
        int N = xv.size(), M = yv.size();
        for (int i = 1; i <= M; i++) p[i].clear();
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= M; j++)
                w[i][j] = 0;
        for (int i = 1; i <= n; i++)
        {
            x[i] = lower_bound(xv.begin(), xv.end(), x[i]) - xv.begin() + 1;
            y[i] = lower_bound(yv.begin(), yv.end(), y[i]) - yv.begin() + 1;
            w[x[i]][y[i]] += ww[i];
            p[y[i]].pb(x[i]);
        }
        for (int i = 1; i <= M; i++)
        {
            sort(p[i].begin(), p[i].end());
            p[i].erase(unique(p[i].begin(), p[i].end()), p[i].end());
        }
        LL ans = 0;
        for (int i = 1; i <= M; i++)
        {
            build(1, 1, N);
            for (int j = i; j <= M; j++)
            {
                for (int pos : p[j]) 
                {
                    update(1, 1, N, pos, w[pos][j]); 
                }
                ans = max(ans, T[1].res);
            }
        }
        printf("%lld\n", ans);
    }
	return 0;
}
