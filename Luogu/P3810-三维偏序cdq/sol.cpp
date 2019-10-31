#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
int n, k;
inline int lowbit(int x) {return x & -x;}
int N, c[maxn], cnt[maxn];
void update(int x, int v) {for (; x <= k; x += lowbit(x)) c[x] += v;}
int query(int x) {int res = 0; for (; x; x -= lowbit(x)) res += c[x]; return res;}
int ans[maxn], f[maxn];
struct node{int id, a, b, c;}tmp[maxn], p[maxn], pl[maxn], pr[maxn];
bool cmp1(node &x, node &y) 
{
    if (x.a != y.a) return x.a < y.a;
    if (x.b != y.b) return x.b < y.b;
    return x.c < y.c;
}
bool cmp2(node &x, node &y) {return x.b < y.b;}
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
    return sz;
}
void solve(int l, int r)
{
    if (l == r) return;
    int mid = (l + r) >> 1;
    solve(l, mid);
    solve(mid + 1, r);

    int cntl = merge(pl, l, mid);
    int cntr = merge(pr, mid + 1, r);
    for (int i = l, pt = 0; i <= mid; i++) p[i] = pl[++pt];
    for (int i = mid + 1, pt = 0; i <= r; i++) p[i] = pr[++pt];

    int now = 1;
    for (int i = 1; i <= cntr; i++)
    {
        while (now <= cntl && pl[now].b <= pr[i].b) update(pl[now].c, cnt[pl[now].id]), now++;
        ans[pr[i].id] += query(pr[i].c);
    }
    now = 1;
    for (int i = 1; i <= cntr; i++)
        while (now <= cntl && pl[now].b <= pr[i].b) update(pl[now].c, -cnt[pl[now].id]), now++;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d%d%d", &tmp[i].a, &tmp[i].b, &tmp[i].c);
    sort(tmp + 1, tmp + 1 + n, cmp1);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        if (tmp[i].a == p[tot].a && tmp[i].b == p[tot].b && tmp[i].c == p[tot].c) cnt[tot]++;
        else 
        {
            p[++tot] = tmp[i];
            p[tot].id = tot;
            cnt[tot] = 1;
        }
    }
    solve(1, tot);
    for (int i = 1; i <= tot; i++) f[ans[i] + cnt[i] - 1] += cnt[i];
    for (int i = 0; i < n; i++) printf("%d\n", f[i]);
    return 0;
}