#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<string>
#include<cstdio>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
const int INF = 1e9;
struct node{int cover, pre, suf, num, len;} T[maxn << 2];
struct eg
{
    int x, yl, yr, type;
    eg(int x, int yl, int yr, int type) : x(x), yl(yl), yr(yr), type(type) {}
    eg() {}
    bool operator < (const eg &rhs) const
    {
        return x < rhs.x;
    }
}edge[maxn];
vector<int>Y;
void build(int rt, int l, int r)
{
    T[rt].cover = T[rt].pre = T[rt].suf = T[rt].num = 0;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void pushup(int rt, int l, int r)
{
    if (T[rt].cover) {T[rt].len = Y[r + 1] - Y[l]; T[rt].pre = T[rt].suf = T[rt].num = 1;}
    else if (l == r) T[rt].pre = T[rt].suf = T[rt].num = T[rt].len = 0;
    else
    {
        T[rt].len = T[rt << 1].len + T[rt << 1 | 1].len;
        T[rt].pre = T[rt << 1].pre;
        T[rt].suf = T[rt << 1 | 1].suf;
        T[rt].num = T[rt << 1].num + T[rt << 1 | 1].num - (T[rt << 1].suf && T[rt << 1 | 1].pre);
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
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        Y.clear();
        int tot = 0;
        while (n--)
        {
            int xl, xr, yl, yr; scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
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
        int ans = 0, last = 0;
        for (int i = 1; i <= tot; i++)
        {
            int l = getid(edge[i].yl), r = getid(edge[i].yr);
            update(1, 1, mx, l, r - 1, edge[i].type);
            if (i < tot) ans += 2 * (edge[i + 1].x - edge[i].x) * T[1].num;
            ans += abs(T[1].len - last);
            last = T[1].len;
        }
        printf("%d\n", ans);
    }
    return 0;
}


