#include<iostream>
#include<algorithm>
#include<cstdio>
#include<string>
#include<string.h>
#include<cmath>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1007;
struct mat {int xl, xr, yl, yr;};
int res;
int mx, m, rtx[maxn], rty[maxn]; 
struct tree
{
    int Ty[maxn << 2];
    void _build(int rt, int l, int r)
    {
        Ty[rt] = 0;
        if (l == r) {rty[l] = rt; Ty[rt] = 0; return;}
        int mid = (l + r) >> 1;
        _build(rt << 1, l, mid);
        _build(rt << 1 | 1, mid + 1, r);
    }
    void _update(int rt, int l, int r, int L, int R, int val)
    {
        if (L <= l && r <= R) {Ty[rt] += val; return;}
        int mid = (l + r) >> 1;
        if (L <= mid) _update(rt << 1, l, mid, L, R, val);
        if (mid <  R) _update(rt << 1 | 1, mid + 1, r, L, R, val);
    }
    /*
    void _query(int rt, int l, int r, int pos)
    {
        res += Ty[rt];
        if (l == r) return;
        int mid = (l + r) >> 1;
        if (pos <= mid)  _query(rt << 1, l, mid, pos);
        else _query(rt << 1 | 1, mid + 1, r, pos);
    }
    */
}T[maxn << 2];
void build(int rt, int l, int r)
{
    T[rt]._build(1, 1, mx);
    if (l == r) {rtx[l] = rt; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}
void update(int rt, int l, int r, mat tmp, int val)
{
    if (tmp.xl <= l && r <= tmp.xr) 
    {
        T[rt]._update(1, 1, mx, tmp.yl, tmp.yr, val);
        return;
    }
    int mid = (l + r) >> 1;
    if (tmp.xl <= mid) update(rt << 1, l, mid, tmp, val);
    if (mid <  tmp.xr) update(rt << 1 | 1, mid + 1, r, tmp, val);
}
/*
void query(int rt, int l, int r, int posx, int posy)
{
    T[rt]._query(1, 1, mx, posy);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (posx <= mid) query(rt << 1, l, mid, posx, posy);
    else query(rt << 1 | 1, mid + 1, r, posx, posy);
}
*/
int query(int x, int y)
{
    int res = 0;
    for (int i = rtx[x]; i; i >>= 1)
        for (int j = rty[y]; j; j >>= 1)
            res += T[i].Ty[j];
    return res;
}

int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d%d", &mx, &m);
        build(1, 1, mx);
        for (int k = 1; k <= m; k++)
        {
            char s[10];
            scanf(" %s", s);
            if (s[0] == 'C')
            {
                mat tmp; scanf("%d%d%d%d", &tmp.xl, &tmp.yl, &tmp.xr, &tmp.yr);
                update(1, 1, mx, tmp, 1);
            }
            else if (s[0] == 'Q')
            {
                int x, y; scanf("%d%d", &x, &y);
                res = query(x, y);
                printf("%d\n", res % 2);
            }
        }
        if (t) puts("");
    }
    return 0;
}

