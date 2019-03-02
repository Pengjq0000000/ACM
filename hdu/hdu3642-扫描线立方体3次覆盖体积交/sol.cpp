#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
const int INF = 1e9;
struct node{int cover, len[4];} T[maxn << 2];
struct eg
{
    int x, yl, yr, zl, zr, type;
    eg(int x, int yl, int yr, int zl, int zr, int type) : x(x), yl(yl), yr(yr), zl(zl), zr(zr), type(type) {}
    eg(){}
    bool operator < (const eg &rhs) const
    {
        return x < rhs.x;
    }
}edge[maxn];
vector<int>Y, z;

void build(int rt, int l, int r)
{
    T[rt].cover = 0;
    MEM(T[rt].len, 0);
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void pushup(int rt, int l, int r)
{   
    for (int i = 1; i <= 3; i++)
    {
        if (T[rt].cover >= i) T[rt].len[i] = Y[r + 1] - Y[l];
        else if (l == r) T[rt].len[i] = 0;
        else for (int k = 0; k < i; k++)
            if (T[rt].cover == k) T[rt].len[i] = T[rt << 1].len[i - k] + T[rt << 1 | 1].len[i - k];
    }
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) T[rt].cover += val;
    else
    {
        int mid = (l + r) >> 1;
        if (L <= mid) update(rt << 1, l, mid, L, R, val);
        if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
    }
    pushup(rt, l, r);
}
int getid(int x) {return lower_bound(Y.begin(), Y.end(), x) - Y.begin();}
eg seg[maxn];
int main()
{
    int t, cas = 0; scanf("%d", &t);
    while (t--)
    {
        Y.clear(); z.clear();
        int n; scanf("%d", &n);
        int tot = 0;
        while(n--)
        {
            int xl, xr, yl, yr, zl, zr;
            scanf("%d%d%d%d%d%d", &xl, &yl, &zl, &xr, &yr, &zr);
            edge[++tot] = eg(xl, yl, yr, zl, zr, 1);
            edge[++tot] = eg(xr, yl, yr, zl, zr, -1);
            z.pb(zl); z.pb(zr);
            Y.pb(yl); Y.pb(yr);
        }
        Y.pb(-INF);
        sort(edge + 1, edge + 1 + tot);
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        int mx = Y.size() - 1;
        sort(z.begin(), z.end());
        z.erase(unique(z.begin(), z.end()), z.end());
        LL ans = 0, area = 0;
        build(1, 1, mx);
        for (int i = 0; i < (int)z.size() - 1; i++)
        {
            int cnt = 0;
            for (int j = 1; j <= tot; j++)
                if (edge[j].zl <= z[i] && z[i] < edge[j].zr) seg[++cnt] = edge[j];
            area = 0;
            for (int j = 1; j <= cnt; j++)
            {
                int l = getid(seg[j].yl), r = getid(seg[j].yr);
                update(1, 1, mx, l, r - 1, seg[j].type);
                if (j < cnt) area += (LL)(seg[j + 1].x - seg[j].x) * T[1].len[3];
            }
            ans += area * (z[i + 1] - z[i]);
        }
        printf("Case %d: %lld\n", ++cas, ans);
    }
    return 0;
}

