#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
const int maxn = 2e5 + 7;
struct node{int l, r, sum;}T[maxn * 200];
int cnt = 0, rt[maxn];
void update(int &rt, int pre, int l, int r, int pos, int val)
{
    if (!rt) rt = ++cnt;
    T[rt].sum += val;
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos, val);
    else update(T[rt].r, T[pre].r, mid + 1, r, pos, val);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].sum;
    int mid = (l + r) >> 1, res = 0;
    if (L <= mid) res += query(T[rt].l, l, mid, L, R);
    if (mid <  R) res += query(T[rt].r, mid + 1, r, L, R);
    return res;
}
int n, q, a[maxn], b[maxn];
inline int lowbit(int x) {return x & -x;}
inline void add(int x, int val)
{
    for (int p = x; p <= n; p += lowbit(p))
        update(rt[p], rt[p], 1, n, b[x], val);
}
int main()
{
    n = scan(); q = scan();
    for (int i = 1; i <= n; i++)
    {
        a[i] = scan();
        if (a[i] != a[i - 1]) b[i] = a[i];
    }
    for (int i = 1; i <= n; i++) if (b[i]) add(i, 1);

    while (q--)
    {
        int op, l, r, x, y;
        op = scan(); l = scan(); r = scan();
        if (op == 1)
        {
            if (a[l] == r) continue;
            if (b[l]) add(l, -1); b[l] = 0;
            a[l] = r;
            if (a[l] == a[l + 1]) { add(l + 1, -1); b[l + 1] = 0; }
            if (a[l] != a[l - 1]) {  b[l] = a[l]; add(l, 1); }
            else b[l] = 0;
        }
        else
        {
            x = scan(); y = scan();
            int ans = 0;
            for (int p = l - 1; p; p -= lowbit(p)) ans -= query(rt[p], 1, n, x, y);
            for (int p = r; p; p -= lowbit(p)) ans += query(rt[p], 1, n, x, y);
            if (a[l] == a[l - 1] && x <= a[l] && a[l] <= y) ans++;
            printf("%d\n", ans);
        }
    }
}
