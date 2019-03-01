#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
struct node{int cover; double len;}T[maxn << 2];
struct eg
{
    double x, yl, yr, type;
    eg(double x, double yl, double yr, double type) : x(x), yl(yl), yr(yr), type(type) {}
    eg(){}
    bool operator < (const eg &rhs) const
    {
        if (x == rhs.x) return yl < rhs.yl;
        return x < rhs.x;
    }
}edge[maxn];
vector<double>Y;
void pushup(int rt, int l, int r)
{
    if (T[rt].cover > 0) T[rt].len = Y[r] - Y[l];
    else if (r - l == 1) T[rt].len = 0;
    else T[rt].len = T[rt << 1].len + T[rt << 1 | 1].len;
}
void build(int rt, int l, int r)
{
    T[rt].cover = T[rt].len = 0;
    if (r - l == 1) return;
    int mid = (l + r + 1) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid, r);
}
void update(int rt, int l, int r, double L, double R, int val)
{
    if (L <= Y[l] && Y[r] <= R) T[rt].cover += val;
    else
    {
        int mid = (l + r + 1) >> 1;
        if (L < Y[mid]) update(rt << 1, l, mid, L, R, val);
        if (Y[mid] <  R) update(rt << 1 | 1, mid, r, L, R, val);
    }
    pushup(rt, l, r);
}
int main()
{
    int n, cas = 0;
    while (scanf("%d", &n) != EOF)
    {
        if (n == 0) break;
        int tot = 0;
        for (int i = 1; i <= n; i++)
        {
            double xl, xr, yl, yr; scanf("%lf%lf%lf%lf", &xl, &yl, &xr, &yr);
            edge[++tot] = eg(xl, yl, yr, 1); Y.pb(yl);
            edge[++tot] = eg(xr, yl, yr, -1); Y.pb(yr);
        }
        sort(Y.begin(), Y.end());
        Y.erase(unique(Y.begin(), Y.end()), Y.end());
        int mx = Y.size() - 1;
        build(1, 0, mx);
        sort(edge + 1, edge + 1 + tot);
        double ans = 0;
        for (int i = 1; i < tot; i++)
        {
            double l = edge[i].yl, r = edge[i].yr;
            update(1, 0, mx, l, r, edge[i].type);
            ans += (edge[i + 1].x - edge[i].x) * T[1].len;
        }
        printf("Test case #%d\n", ++cas);
        printf("Total explored area: %.2lf\n\n", ans);
    }
    return 0;
}







