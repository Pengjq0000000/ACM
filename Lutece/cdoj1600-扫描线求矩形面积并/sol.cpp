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
struct eg
{
    double x, yl, yr; int type;
    eg(double x, double yl, double yr, int type) : x(x), yl(yl), yr(yr), type(type){}
    eg(){}
    bool operator < (const eg &rhs) const
    {
        return x < rhs.x;
    }
}edge[maxn];

vector<double> Y;
int getid(double x) {return lower_bound(Y.begin(), Y.end(), x) - Y.begin();}

struct node{int cover; double len;}T[maxn << 2];
void build(int rt, int l, int r)
{
    T[rt].cover = 0; T[rt].len = 0.0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void pushup(int rt, int l, int r)
{
    if (T[rt].cover) T[rt].len = Y[r + 1] - Y[l];
    else if (l == r) T[rt].len = 0;
    else T[rt].len = T[rt << 1].len + T[rt << 1 | 1].len;
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
int main()
{
    int n;
    while(scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        int tot = 0; Y.clear();
        for (int i = 1; i <= n; i++)
        {
            double xl, xr, yl, yr; scanf("%lf%lf%lf%lf", &xl, &yl, &xr, &yr);
            edge[++tot] = eg(xl, yl, yr, 1);
            edge[++tot] = eg(xr, yl, yr, -1);
            Y.pb(yl); Y.pb(yr);
        }
        Y.pb(-INF);
        sort(edge + 1, edge + 1 + tot);
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        int mx = Y.size() - 1;
        build(1, 1, mx);
        double ans = 0;
        for (int i = 1; i < tot; i++)
        {
            int l = getid(edge[i].yl), r = getid(edge[i].yr);
            update(1, 1, mx, l, r - 1, edge[i].type);
            ans += (edge[i + 1].x - edge[i].x) * T[1].len;
        }
        printf("%.2lf\n",ans);
    }
    return 0;
}

