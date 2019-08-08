#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 7;
const int N = 1e7 + 7;
LL xx[maxn], yy[maxn], X[maxn], Y[maxn], A[3], B[3], C[3], M[3];
struct node{LL sum, lazy; int l, r;}T[N];
int tot = 1;
void pushup(int rt) {T[rt].sum = T[T[rt].l].sum + T[T[rt].r].sum;}
void pushdown(int rt, int &lson, int &rson, int l, int r)
{
    if (T[rt].lazy == 0) return;
    if (!lson) lson = (++tot);
    if (!rson) rson = (++tot);
    int mid = (l + r) / 2;
    T[lson].lazy += T[rt].lazy; T[lson].sum += T[rt].lazy * (mid - l + 1);
    T[rson].lazy += T[rt].lazy; T[rson].sum += T[rt].lazy * (r - mid);
    T[rt].lazy = 0;
}
void update(int &rt, int l, int r, int L, int R)
{
    if (!rt) rt = (++tot);
    if (L <= l && r <= R)
    {
        T[rt].sum += (r - l + 1); T[rt].lazy++;
        return;
    }
    pushdown(rt, T[rt].l, T[rt].r, l, r);
    int mid = (l + r) / 2;
    if (L <= mid) update(T[rt].l, l, mid, L, R);
    if (mid <  R) update(T[rt].r, mid + 1, r, L, R);
    pushup(rt);
}
int query(int rt, int l, int r, LL k)
{
    if (l == r) return l;
    pushdown(rt, T[rt].l, T[rt].r, l, r);
    int mid = (l + r) / 2;
    if (T[T[rt].l].sum >= k) return query(T[rt].l, l, mid, k);
    else return query(T[rt].r, mid + 1, r, k - T[T[rt].l].sum);
}

int main()
{
	int n; scanf("%d", &n);
    scanf("%lld%lld%lld%lld%lld%lld", &xx[1], &xx[2], &A[1], &B[1], &C[1], &M[1]);
    scanf("%lld%lld%lld%lld%lld%lld", &yy[1], &yy[2], &A[2], &B[2], &C[2], &M[2]);
    X[1] = min(xx[1], yy[1]) + 1; Y[1] = max(xx[1], yy[1]) + 1;
    X[2] = min(xx[2], yy[2]) + 1; Y[2] = max(xx[2], yy[2]) + 1;
    for(int i = 3; i <= n; i++)
    {
        xx[i] = (A[1] * xx[i - 1] + B[1] * xx[i - 2] + C[1]) % M[1];
        yy[i] = (A[2] * yy[i - 1] + B[2] * yy[i - 2] + C[2]) % M[2];
        X[i] = min(xx[i], yy[i]) + 1; Y[i] = max(xx[i], yy[i]) + 1;
    }
    int root = 1;
    int INF = 1e9;
    LL sum = 0;
    for (int i = 1, x, y; i <= n; i++)
    {
        x = X[i], y = Y[i];
        sum += (LL)(y - x + 1);
        update(root, 1, INF, x, y);
        printf("%d\n", query(root, 1, INF, (sum + 1) / 2));
    }
	return 0;
}
