#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
const int INF = 1e9;
int a[MAXN];
#define lson (rt << 1)
#define rson (rt << 1 | 1)
struct node{int val, pos;} T[MAXN << 2][2];
bool lazy[MAXN << 2];
node merge(node &Tl, node &Tr)
{
    if (Tl.val < Tr.val) return Tl;
    else return Tr;
}
void pushup(int rt) 
{
    for (int i = 0; i < 2; i++) T[rt][i] = merge(T[lson][i], T[rson][i]);
}
void build(int rt, int l, int r)
{
    if (l == r) 
    {
        T[rt][(l % 2)] = {a[l], l};
        T[rt][(l % 2) ^ 1] = {INF, l};
        return;
    }
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt) {swap(T[rt][0], T[rt][1]); lazy[rt] ^= 1;}
void pushdown(int rt)
{
    if (!lazy[rt]) return;
    update(lson); update(rson);
    lazy[rt] = 0;
}
void modify(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) {update(rt); return;}
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (L <= mid) modify(lson, l, mid, L, R);
    if (mid <  R) modify(rson, mid + 1, r, L, R);
    pushup(rt);
}
node query(int rt, int l, int r, int L, int R, int c)
{
    if (L <= l && r <= R) return T[rt][c];
    int mid = (l + r) >> 1; 
    pushdown(rt);
    node Tl = {INF, -1};
    node Tr = Tl;
    if (L <= mid) Tl = query(lson, l, mid, L, R, c);
    if (mid <  R) Tr = query(rson, mid + 1, r, L, R, c);
    return merge(Tl, Tr);
} 
void modi_pos(int rt, int l, int r, int pos)
{
    if (l == r) { T[rt][0].val = T[rt][1].val = INF; return;}
    int mid = (l + r) >> 1;
    pushdown(rt);
    if (pos <= mid) modi_pos(lson, l, mid, pos);
    else modi_pos(rson, mid + 1, r, pos);
    pushup(rt);
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    set<int>pt; pt.insert(n + 1);
    for (int _ = 1; _ <= n; _ += 2)
    {
        node p1 = T[1][1];
        int pos = *pt.lower_bound(p1.pos) - 1;
        node p2 = query(1, 1, n, p1.pos + 1, pos, 0);
        printf("%d %d ", p1.val, p2.val);
        modi_pos(1, 1, n, p1.pos); pt.insert(p1.pos);
        modi_pos(1, 1, n, p2.pos); pt.insert(p2.pos);
        if (p1.pos + 1 <= p2.pos - 1) modify(1, 1, n, p1.pos + 1, p2.pos - 1);
    }
    return 0;   
}