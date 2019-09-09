#include<algorithm>
#include<cstdio>
#include<cmath>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int T[21][maxn << 2][2], lazy1[21][maxn << 2], lazy2[21][maxn << 2];
int bit[21][maxn];
void pushup(int k, int rt)
{
   for (int i = 0; i <= 1; i++) T[k][rt][i] = T[k][lson][i] + T[k][rson][i];
}
void build(int k, int rt, int l, int r)
{
    lazy2[k][rt] = -1; lazy1[k][rt] = 0;
    if (l == r) {T[k][rt][bit[k][l]] = 1; return;}
    int mid = (l + r) >> 1;
    build(k, lson, l, mid);
    build(k, rson, mid + 1, r);
    pushup(k, rt);
}
void change(int k, int rt, int l, int r, int op, int val)
{
    if (op == 1)
    {
        swap(T[k][rt][0], T[k][rt][1]);
        if (lazy2[k][rt] != -1) lazy2[k][rt] ^= 1, lazy1[k][rt] = 0;
        else lazy1[k][rt] ^= 1;
    }
    else if (op == 2)
    {
        T[k][rt][val] = (r - l + 1);
        T[k][rt][val ^ 1] = 0;
        lazy1[k][rt] = 0; lazy2[k][rt] = val;
    }
}
void pushdown(int k, int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    if (lazy1[k][rt])
    {
        change(k, lson, l, mid, 1, -1);
        change(k, rson, mid + 1, r, 1, -1);
        lazy1[k][rt] = 0;
    }
    if (lazy2[k][rt] != -1)
    {
        change(k, lson, l, mid, 2, lazy2[k][rt]);
        change(k, rson, mid + 1, r, 2, lazy2[k][rt]);
        lazy2[k][rt] = -1;
    }
    pushup(k, rt);
}
void update(int k, int rt, int l, int r, int L, int R, int op, int val)
{
    if (L <= l && r <= R)
    {
        change(k, rt, l, r, op, val);
        return;
    }
    pushdown(k, rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(k, lson, l, mid, L, R, op, val);
    if (mid <  R) update(k, rson, mid + 1, r, L, R, op, val);
    pushup(k, rt);
}
int query(int k, int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[k][rt][1];
    pushdown(k, rt, l, r);
    int mid = (l + r) >> 1;
    int res = 0;
    if (L <= mid) res += query(k, lson, l, mid, L, R);
    if (mid <  R) res += query(k, rson, mid + 1, r, L, R);
    return res;
}
int n, a[maxn];
const int maxk = 3;
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        int tmp = a[i];
        for (int k = 0; k < maxk; k++)
        {
            bit[k][i] = (tmp & 1);
            tmp /= 2;
        }
    }
    for (int k = 0; k < maxk; k++) build(k, 1, 1, n);
    int q; scanf("%d", &q);
    while (q--)
    {
        int op, l, r, x;
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d%d", &l, &r);
            LL res = 0, base = 1;
            for (int k = 0; k < maxk; k++)
            {
                int tmp = query(k, 1, 1, n, l, r);
                res += base * tmp;
                base *= 2;
            }
            printf("%lld\n", res);
        }
        else
        {
            scanf("%d%d%d", &l, &r, &x);
            for (int k = 0; k < maxk; k++)
            {
                int now = (x & 1);
                if (op == 2 && now == 1) update(k, 1, 1, n, l, r, 1, -1);
                else
                {
                    if (op == 3 && now == 1) update(k, 1, 1, n, l, r, 2, 1);
                    else if (op == 4 && now == 0) update(k, 1, 1, n, l, r, 2, 0);
                }
                x /= 2;
            }
        }
    }
	return 0;
}
