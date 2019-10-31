#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int maxn = 1e5 + 7;
inline int lowbit(int x) {return x & -x;}
int n, m, tot, c[maxn];
void update(int x, int v) {for (; x <= n; x += lowbit(x)) c[x] += v;}
int query(int x) {int res = 0; for (; x; x -= lowbit(x)) res += c[x]; return res;}
struct node{int id, b, c, v;}p[maxn << 1], pl[maxn << 1], pr[maxn << 1];
int pos[maxn];
ll ans[maxn << 1];
int merge(node *a, int l, int r)
{
    int mid = (l + r) >> 1, sz = 0;
    int i = l, j = mid + 1;
    while (i <= mid || j <= r)
    {
        if (i > mid) {a[++sz] = p[j++]; continue;}
        if (j > r) {a[++sz] = p[i++]; continue;}
        if (p[i].b <= p[j].b) a[++sz] = p[i++];
        else a[++sz] = p[j++];
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
        while (i <= cntl && pl[i].b <= pr[j].b) update(pl[i].c, pl[i].v), i++;
        ans[pr[j].id] += pr[j].v * (query(n) - query(pr[j].c));
    }
    for (i = 1, j = 1; j <= cntr; j++)
        while (i <= cntl && pl[i].b <= pr[j].b) update(pl[i].c, -pl[i].v), i++;

    for (i = cntl, j = cntr; j; j--)
    {
        while (i && pl[i].b >= pr[j].b) update(pl[i].c, pl[i].v), i--;
        ans[pr[j].id] += pr[j].v * query(pr[j].c - 1);
    }
    for (i = cntl, j = cntr; j; j--)
        while (i && pl[i].b >= pr[j].b) update(pl[i].c, -pl[i].v), i--;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1, x; i <= n; i++) scanf("%d", &x), p[++tot] = {i, x, i, 1}, pos[x] = i;
    for (int i = 1, x; i <= m; i++) scanf("%d", &x), p[++tot] = {i + n, x, pos[x], -1};
    solve(1, tot);
    for (int i = 1; i <= tot; i++) ans[i] += ans[i - 1];
    for (int i = 0; i < m; i++) printf("%lld\n", ans[i + n]);
    return 0;
}