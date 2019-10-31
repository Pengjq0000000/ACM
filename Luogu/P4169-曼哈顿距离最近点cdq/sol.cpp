#include<bits/stdc++.h>
#define inf 10000000
using namespace std;
const int N = 3e5 + 7;
const int M = N * 5;
struct node{int a, b, op, id;}init[M], p[M], pl[M], pr[M];
int c[1000002], up = 1000001;
inline int lowbit(int x) {return x & -x;}
void ins(int x, int v) {for (; x <= up; x += lowbit(x)) c[x] = max(c[x], v);}
void del(int x) {for (; x <= up; x += lowbit(x)) c[x] = -inf;}
int query(int x) {int res = -inf; for (; x; x -= lowbit(x)) res = max(res, c[x]); return res;}
int ans[N];
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
    // ai <= aj && bi <= bj, dis = aj - ai + bj - bi = aj + bj - (ai + bi)
    for (i = 1, j = 1; j <= cntr; j++)
    {
        if (pr[j].op == 1) continue;
        while (i <= cntl) 
        {
            if (pl[i].op == 2) i++;
            else if (pl[i].a <= pr[j].a) ins(pl[i].b, pl[i].a + pl[i].b), i++;
            else break;
        }
        ans[pr[j].id] = min(ans[pr[j].id], pr[j].a + pr[j].b - query(pr[j].b));
    }
    for (i = 1, j = 1; j <= cntr; j++)
    {
        if (pr[j].op == 1) continue;
        while (i <= cntl) 
        {
            if (pl[i].op == 2) i++;
            else if (pl[i].a <= pr[j].a) del(pl[i].b), i++;
            else break;
        }
    }
}
int main()
{
    // freopen("sol.in", "r", stdin);
    int n, m; scanf("%d%d", &n, &m);
    int tot = 0, qtot = 0;
    for (int i = 1, x, y; i <= n; i++) scanf("%d%d", &x, &y), x++, y++, init[++tot] = {x, y, 1, 0};
    for (int i = 1, x, y, op; i <= m; i++)
    {
        scanf("%d%d%d", &op, &x, &y); x++; y++;
        if (op == 1) init[++tot] = {x, y, 1, 0};
        else init[++tot] = {x, y, 2, ++qtot};
    } 
    for (int i = 1; i <= qtot; i++) ans[i] = 2e9;

    for (int i = 1; i <= tot; i++) p[i] = init[i]; 
    for (int i = 1; i <= up; i++) c[i] = -inf;
    solve(1, tot);
    for (int i = 1; i <= tot; i++) p[i] = init[i], p[i].a = up - p[i].a + 1; 
    for (int i = 1; i <= up; i++) c[i] = -inf;
    solve(1, tot);
    for (int i = 1; i <= tot; i++) p[i] = init[i], p[i].b = up - p[i].b + 1; 
    for (int i = 1; i <= up; i++) c[i] = -inf;
    solve(1, tot);
    for (int i = 1; i <= tot; i++) p[i] = init[i], p[i].a = up - p[i].a + 1, p[i].b = up - p[i].b + 1; 
    for (int i = 1; i <= up; i++) c[i] = -inf;
    solve(1, tot);

    for (int i = 1; i <= qtot; i++) printf("%d\n", ans[i]);
    return 0;
}