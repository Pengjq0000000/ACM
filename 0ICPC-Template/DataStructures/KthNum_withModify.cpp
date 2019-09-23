#include<bits/stdc++.h>
using namespace std;
const int maxn = 2e5 + 7;
struct node{int l, r, sum;}T[maxn * 20 * 20];
int cnt, rt[maxn];
int lc, rc, lp[21], rp[21];
vector<int>vec;
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
void update(int &rt, int l, int r, int pos, int val)
{
    if (!rt) rt = ++cnt;
    T[rt].sum += val;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, l, mid, pos, val);
    else update(T[rt].r, mid + 1, r, pos, val);
}
int query(int l, int r, int k)
{
    if (l == r) return l;
    int mid = (l + r) >> 1, lsum = 0;
    for (int i = 1; i <= rc; i++) lsum += T[T[rp[i]].l].sum;
    for (int i = 1; i <= lc; i++) lsum -= T[T[lp[i]].l].sum;
    if (lsum >= k)
    {
        for (int i = 1; i <= lc; i++) lp[i] = T[lp[i]].l;
        for (int i = 1; i <= rc; i++) rp[i] = T[rp[i]].l;
        return query(l, mid, k);
    }
    else
    {
        for (int i = 1; i <= lc; i++) lp[i] = T[lp[i]].r;
        for (int i = 1; i <= rc; i++) rp[i] = T[rp[i]].r;
        return query(mid + 1, r, k - lsum);
    }
}
inline int lowbit(int x) {return x & -x;}
int N, n, m, a[maxn];
inline void modify(int x, int p, int val)
{
    for (int i = x; i <= n; i += lowbit(i)) update(rt[i], 1, N, p, val);
}
struct Q{int op, l, r, k;}q[maxn];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vec.push_back(a[i]);
    for (int i = 1; i <= m; i++)
    {
        char ch; int l, r, k;
        scanf(" %c%d%d", &ch, &l, &r);
        if (ch == 'Q') scanf("%d", &k), q[i] = { 1, l, r, k };
        else q[i] = { 2, l, l, r }, vec.push_back(r);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++) a[i] = getid(a[i]);
    for (int i = 1; i <= m; i++)
        if (q[i].op == 2) q[i].k = getid(q[i].k);
    N = vec.size();

    for (int i = 1; i <= n; i++) modify(i, a[i], 1);

    for (int i = 1; i <= m; i++)
    {
        if (q[i].op == 1)
        {
            lc = rc = 0;
            for (int p = q[i].r; p; p -= lowbit(p)) rp[++rc] = rt[p];
            for (int p = q[i].l - 1; p; p -= lowbit(p)) lp[++lc] = rt[p];
            int res = query(1, N, q[i].k);
            printf("%d\n", vec[res - 1]);
        }
        else
        {
            modify(q[i].l, a[q[i].l], -1);
            a[q[i].l] = q[i].k;
            modify(q[i].l, a[q[i].l], 1);
        }
    }
    return 0;
}