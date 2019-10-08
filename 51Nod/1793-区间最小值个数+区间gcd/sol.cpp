#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int N = 1e5 + 7;
int a[N];
struct node{int MIN, num, gcd;} T[N << 2];
void pushup(int rt)
{
    T[rt].MIN = min(T[lson].MIN, T[rson].MIN);
    T[rt].num = 0;
    if (T[lson].MIN == T[rt].MIN) T[rt].num += T[lson].num;
    if (T[rson].MIN == T[rt].MIN) T[rt].num += T[rson].num;
    T[rt].gcd = __gcd(T[lson].gcd, T[rson].gcd);
}
void build(int rt, int l, int r)
{
    if (l == r)
    {
        T[rt].MIN = T[rt].gcd = a[l]; T[rt].num = 1; 
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
node query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    node resl = {1000000007, 0, 0}, resr = {1000000007, 0, 0};
    if (L <= mid) resl = query(lson, l, mid, L, R);
    if (mid <  R) resr = query(rson, mid + 1, r, L, R);
    node res;
    res.MIN = min(resl.MIN, resr.MIN);
    res.num = 0;
    if (resl.MIN == res.MIN) res.num += resl.num;
    if (resr.MIN == res.MIN) res.num += resr.num;
    res.gcd = __gcd(resl.gcd, resr.gcd);
    return res;
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    int q; scanf("%d", &q);
    while (q--)
    {
        int l, r; scanf("%d%d", &l, &r);
        node res = query(1, 1, n, l, r);
        //printf("MIN = %d num = %d gcd = %d\n", res.MIN, res.num, res.gcd);
        int ans = r - l + 1 - (res.gcd == res.MIN) * res.num;
        printf("%d\n", ans);
    }
    return 0;
}