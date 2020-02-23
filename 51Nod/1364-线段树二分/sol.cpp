#include<iostream>
#include<assert.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int MAXN = 1e5 + 7;
struct node{int num, MAX, pos;}T[MAXN << 2];
int a[MAXN];
node merge(node &Tl, node &Tr)
{
    node res;
    res = Tl.MAX >= Tr.MAX ? Tl : Tr;
    res.num = Tl.num + Tr.num;
    return res;
}
void pushup(int rt) {T[rt] = merge(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = {1, a[l], l}; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
int getpos(int rt, int l, int r, int k)
{
    if (l == r) {assert(k >= 1); return l;}
    int mid = (l + r) >> 1;
    if (T[lson].num >= k) return getpos(lson, l, mid, k);
    else return getpos(rson, mid + 1, r, k - T[lson].num);
}
node query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    node resl = {0, 0, 0}, resr = {0, 0, 0};
    if (L <= mid) resl = query(lson, l, mid, L, R);
    if (mid <  R) resr = query(rson, mid + 1, r, L, R);
    return merge(resl, resr);
}
void update(int rt, int l, int r, int pos)
{
    if (l == r) {T[rt] = {0, 0, 0}; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos);
    else update(rson, mid + 1, r, pos);
    pushup(rt);
}
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    for (int i = 1; i <= n; i++)
    {
        int pos = getpos(1, 1, n, k + 1);
        node res = query(1, 1, n, 1, pos);
        printf("%d\n", res.MAX);
        k -= query(1, 1, n, 1, res.pos).num - 1;
        update(1, 1, n, res.pos);
    }
    return 0;
}