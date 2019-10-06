#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int maxn = 1e6 + 7;
int vis[maxn], prime[maxn], minprim[maxn], tot = 0;
void get_prime(int maxl)
{
    minprim[1] = 1;
    for (int i = 2; i <= maxl; i++)
    {
        if (!vis[i]) {prime[++tot] = i; minprim[i] = i;}
        for (int j = 1; j <= tot; j++)
        {
            if (i * prime[j] > maxl) break;
            vis[i * prime[j]] = 1;
            minprim[i * prime[j]] = prime[j];
            if (i % prime[j] == 0) break;
        }
    }
}
#define lson (rt << 1)
#define rson (rt << 1 | 1)
LL T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = T[lson] + T[rson];}
void upd(int rt, int l, int r, LL v) {T[rt] += v * (r - l + 1); lazy[rt] += v;}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == 0) return;
    int mid = (l + r) >> 1;
    upd(lson, l, mid, lazy[rt]);
    upd(rson, mid + 1, r, lazy[rt]);
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int v)
{
    if (L <= l && r <= R) {upd(rt, l, r, v); return;}
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(lson, l, mid, L, R, v);
    if (mid <  R) update(rson, mid + 1, r, L, R, v);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    LL res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}
vector<int>vec;
int lst[maxn];
int main()
{
    get_prime(1000005);
    int n; scanf("%d", &n);
    LL ans = 0;
    for (int i = 1; i <= n; i++)
    {
        int x; scanf("%d", &x);
        vec.clear();
        while (x > 1) 
        {
            int p = minprim[x];
            vec.push_back(p);
            while (x % p == 0) x /= p;
        }
        for (int p : vec)
        {
            update(1, 1, n, lst[p] + 1, i, 1);
            lst[p] = i;
        }
        ans += query(1, 1, n, 1, i);
    }
    printf("%lld\n", ans);
    return 0;
}