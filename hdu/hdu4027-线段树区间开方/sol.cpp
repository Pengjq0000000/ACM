#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
LL T[maxn << 2], a[maxn];
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = a[l]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int L, int R)
{
    if (T[rt] == r - l + 1 || T[rt] == 0) return;
    if (l == r) {T[rt] = sqrt(1.0 * T[rt]); return;}
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    LL res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R);
    if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R);
    return res;
}
int main()
{
    int n, m, cas = 0;
    while (scanf("%d", &n) != EOF)
    {
        printf("Case #%d:\n", ++cas);
        for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
        build(1, 1, n);
        int m; scanf("%d", &m);
        while (m--)
        {
            int op, x, y; scanf("%d%d%d", &op, &x, &y);
            if (x > y) swap(x, y);
            if (op == 0) update(1, 1, n, x, y);
            else if (op == 1) printf("%lld\n", query(1, 1, n, x, y));
        }
        puts("");
    }
    return 0;
}

