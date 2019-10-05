#include<bits/stdc++.h>
#define LL long long
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define MOD(x) ((x) % mod)
#define mod 1000000007
using namespace std;

const int maxn = 2e5 + 7;
LL po[maxn];
int cnt[maxn];

LL T[maxn << 2];
void pushup(int rt) {T[rt] = MOD(T[lson] + T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = po[cnt[l]]; return;}
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos)
{
    if (l == r) {cnt[l]--; T[rt] = po[cnt[l]]; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos);
    else update(rson, mid + 1, r, pos);
    pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    LL res = 0;
    if (L <= mid) res = MOD(res + query(lson, l, mid, L, R));
    if (mid <  R) res = MOD(res + query(rson, mid + 1, r, L, R));
    return res;
}
int vis[maxn], pos[maxn];
int main()
{
    po[0] = 0;
    for (int i = 1; i <= 200000; i++) po[i] = MOD(po[i - 1] * 2 + 1);
    int n, m;
    while (scanf("%d %d", &n, &m) == 2)
    {
        for (int i = 1; i <= m; i++) cnt[i] = vis[i] = pos[i] = 0; 
        for (int i = 1; i <= n; i++)
        {
            int num; scanf("%d", &num);
            for (int j = 1, x; j <= num; j++) 
            {
                scanf("%d", &x); if (!pos[x] || pos[x] > j) pos[x] = j;
            }
        }
        for (int i = 1; i <= m; i++) cnt[pos[i]]++;
        build(1, 1, m);
        LL ans = m + 1;
        for (int i = 1, x; i <= m; i++)
        {
            scanf("%d", &x);
            if (pos[x]) update(1, 1, m, pos[x]);
            if (pos[x]) ans = MOD(ans + query(1, 1, m, 1, pos[x]));
            else ans = MOD(ans + T[1]);
        }
        printf("%lld\n", ans);
    }
}