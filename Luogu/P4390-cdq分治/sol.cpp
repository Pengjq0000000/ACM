#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int W, c[maxn * 10];
inline int lowbit(int x) {return x & -x;}
void update(int x, int v) {for (; x <= W; x += lowbit(x)) c[x] += v;}
int query(int x) {int res = 0; for (; x; x -= lowbit(x)) res += c[x]; return res;}
struct node{int a, b, v, op, id;}p[maxn], pl[maxn], pr[maxn];
int ans[maxn];
int merge(node *a, int l, int r)
{
    int mid = (l + r) >> 1, sz = 0;
    int i = l, j = mid + 1;
    while (i <= mid || j <= r)
    {
        if (i > mid) a[++sz] = p[j++];
        else if (j > r) a[++sz] = p[i++];
        else 
        {
            if (p[i].a <= p[j].a) a[++sz] = p[i++];
            else a[++sz] = p[j++];
        }
    }
    for (int i = l, pt = 0; i <= r; i++) p[i] = a[++pt];
    return sz;
}
void solve(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid); solve(mid + 1, r);
    int cntl = merge(pl, l, mid);
    int cntr = merge(pr, mid + 1, r);

    int i, j;
    for (i = 1, j = 1; j <= cntr; j++)
    {
        if (pr[j].op == 1) continue;
        while (i <= cntl)
        {
            if (pl[i].op == 2) i++;
            else if (pl[i].a <= pr[j].a) update(pl[i].b, pl[i].v), i++;
            else break;
        }
        ans[pr[j].id] += query(pr[j].b) * pr[j].v;
    }
    for (i = 1, j = 1; j <= cntr; j++)
    {
        if (pr[j].op == 1) continue;
        while (i <= cntl)
        {
            if (pl[i].op == 2) i++;
            else if (pl[i].a <= pr[j].a) update(pl[i].b, -pl[i].v), i++;
            else break;
        }
    }
}
int main()
{
    int op, tot, qtot;
    while (~scanf("%d", &op))
    {
        if (op == 3) break;
        if (op == 0) scanf("%d", &W), tot = qtot = 0;
        else if (op == 1) 
        {
            ++tot; 
            scanf("%d%d%d", &p[tot].a, &p[tot].b, &p[tot].v);
            p[tot].op = 1;
        }
        else if (op == 2)
        {
            int xl, yl, xr, yr; scanf("%d%d%d%d", &xl, &yl, &xr, &yr);
            p[++tot] = {xr, yr, 1, 2, ++qtot};
            p[++tot] = {xl - 1, yr, -1, 2, qtot};
            p[++tot] = {xr, yl - 1, -1, 2, qtot};   
            p[++tot] = {xl - 1, yl - 1, 1, 2, qtot};
        }
    } 
    solve(1, tot);
    for (int i = 1; i <= qtot; i++) printf("%d\n", ans[i]); 
    return 0;
}