#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 107;
 
struct Node {int l, r, sum;}c[maxn * 65];
 
int cnt = 0, Root[maxn * 2];
void Update(int &rt, int pre, int l, int r, int pos)
{
    c[rt = ++cnt] = c[pre];
    c[rt].sum++;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) Update(c[rt].l, c[pre].l, l, mid, pos);
    else Update(c[rt].r, c[pre].r, mid + 1, r, pos);
}
int Query(int rt, int pre, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        return c[rt].sum - c[pre].sum;
    }
    int res = 0;
    int mid = (l + r) >> 1;
    if (L <= mid) res += Query(c[rt].l, c[pre].l, l, mid, L, R);
    if (mid <  R) res += Query(c[rt].r, c[pre].r, mid + 1, r, L, R);
    return res;
}
 
struct node {int l, r; LL sum, tg;}T[maxn * 65];
int tot = 0, root[maxn * 2];
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
 
struct NN
{
    int l, r, x, y;
}Q[maxn];
int h[maxn * 2];
LL Sum[maxn * 2];
const int N = 1e5 + 100;


long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}


int main()
{
    int n, q; n = scan(); q = scan();
    for (int i = 1; i <= n; i++)
    {
        h[i] = scan();
        Sum[i] = Sum[i - 1] + h[i];
        update(root[i], root[i - 1], 1, N, 1, h[i], 1);
        Update(Root[i], Root[i - 1], 1, N, h[i]);
    }
    for (int i = 1; i <= q; i++)
    {
        Q[i].l = scan();
        Q[i].r = scan();
        Q[i].x = scan();
        Q[i].y = scan();
        int L = Q[i].l, R = Q[i].r;
        double sum = Sum[R] - Sum[L - 1];
        double det = (double)sum / Q[i].y;
        double need = (double)sum - det * Q[i].x;
        int ll = 1, rr = N;
        LL res = 0;
        while (ll < rr)
        {
            int mid = (ll + rr) / 2;
            res = query(root[R], root[L - 1], 1, N, 1, mid, 0);
            if (res > need) rr = mid;
            else ll = mid + 1;
        }
        int pos = ll;
        res = query(root[R], root[L - 1], 1, N, 1, ll, 0);
        //printf("sum=%lld", sum);
        //printf("query=[%d, %d] x=%d,y=%d det=%lf res=%lld need=%lf pos = %d ", L, R, Q[i].x, Q[i].y,det,res,need, pos);
        int tmp = 0;
        if (pos - 1 >= 1) tmp = Query(Root[R], Root[L - 1], 1, N, 1, pos - 1);
        //printf("tmp=%d ", tmp);
        int num = (R - L + 1) - tmp;
        //printf("num=%d\n", num);
        double ans = (double)pos - ((double)res - need) / (double)num;
        printf("%.15lf\n", ans);
    }
 
    return 0;
}