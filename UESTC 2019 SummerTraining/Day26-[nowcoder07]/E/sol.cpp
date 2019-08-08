#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 4e5 + 7;
LL xx[maxn], yy[maxn], X[maxn], Y[maxn], A[3], B[3], C[3], M[3]; 
vector<int>v;
struct node{int lp, rp; LL sum, lazy;}T[(maxn * 3) << 2];
void build(int rt, int l, int r)
{
    if (l == r)
    {
        T[rt].lp = v[l - 1];
        T[rt].rp = v[l] - 1;
        T[rt].sum = T[rt].lazy = 0;
        return;
    }
    int mid = (l + r) / 2;
    build(rt << 1, l , mid);
    build(rt << 1 | 1, mid + 1, r);
    T[rt].lp = T[rt << 1].lp;
    T[rt].rp = T[rt << 1 | 1].rp;
}
void pushup(int rt) {T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;}
void pushdown(int rt)
{
    if (T[rt].lazy == 0) return;
    T[rt << 1].lazy += T[rt].lazy;
    T[rt << 1 | 1].lazy += T[rt].lazy;
    T[rt << 1].sum += T[rt].lazy * (T[rt << 1].rp - T[rt << 1].lp + 1);
    T[rt << 1 | 1].sum += T[rt].lazy * (T[rt << 1 | 1].rp - T[rt << 1 | 1].lp + 1);
    T[rt].lazy = 0;
}
void update(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R)
    {
        T[rt].sum += (LL)(T[rt].rp - T[rt].lp + 1);
        T[rt].lazy++;
        return;
    }
    pushdown(rt);
    int mid = (l + r) / 2;
    if (L <= mid) update(rt << 1, l, mid, L, R);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R);
    pushup(rt);
}
int query(int rt, int l, int r, LL k)
{
    if (l == r)
    {
        LL len = T[rt].rp - T[rt].lp + 1;
        assert(T[rt].sum % len == 0);
        LL x = T[rt].sum / (T[rt].rp - T[rt].lp + 1);
        int res = T[rt].lp - 1 + (k - 1) / x + 1;
        return res;
    }
    pushdown(rt);
    int mid = (l + r) / 2;
    if (T[rt << 1].sum >= k) return query(rt << 1, l, mid, k);
    else return query(rt << 1 | 1, mid + 1, r, k - T[rt << 1].sum);
}



int getid(int x) {return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;}
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
    for (int i = 1, x, y; i <= n; i++)
    {
        x = X[i]; y = Y[i] + 1;
        v.pb(x); v.pb(y);
    }
    v.pb(1); v.pb(1000000000 + 1);
    sort(v.begin(), v.end());
    v.erase(unique(v.begin(), v.end()), v.end());

    int N = v.size(); N--;
    build(1, 1, N);
    LL tot = 0;
    for (int i = 1, x, y; i <= n; i++)
    {
        tot += Y[i] - X[i] + 1;
        x = getid(X[i]); y = getid(Y[i] + 1) - 1;
        update(1, 1, N, x, y);
        printf("%d\n", query(1, 1, N, (tot + 1) / 2));
    }
	return 0;
}
