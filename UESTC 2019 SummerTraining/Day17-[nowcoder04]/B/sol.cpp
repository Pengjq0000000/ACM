#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define Lbs LinearBase
#define usint unsigned int
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int N_bs = 31;
const int maxn = 5e4 + 7;
struct LinearBase
{
    usint bs[N_bs + 1], num[N_bs + 1];
    int tot = 0;
    void init() {tot = 0; MEM(bs, 0);}
    void add(usint x) {num[tot++] = x;}
    void insert(usint x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if (x & (1 << i)) 
                if (!bs[i]) {bs[i] = x; break;}
                else x ^= bs[i];
        }
    }
    inline void build() {for (int i = 0; i < tot; i++) insert(num[i]);}
    inline bool check(usint x)
    {
        for (int i = N_bs; i >= 0; i--)
        {
            if (x & (1 << i))
                if (!bs[i]) return false;
                else x ^= bs[i];
        }
        return true;
    }
}T[maxn << 2], a[maxn];
void GetCross(Lbs A, Lbs B, Lbs &res)
{
    res.init();
    usint d[N_bs + 1], all[N_bs + 1];
    for (int i = 0; i <= N_bs; i++) all[i] = A.bs[i], d[i] = 0;
    for (int i = N_bs; i >= 0; i--)
    {
        if (B.bs[i])
        {
            usint k = (1ll << i), v = B.bs[i];
            bool can = true;
            for (int j = N_bs; j >= 0; j--)
            {
                if (v & (1ll << j))
                {
                    if (!all[j]) {can = false; all[j] = v; d[j] = k; break;}
                    else k ^= d[j], v ^= all[j];
                }
            }
            if (can)
            {
                v = 0;
                for (int j = 0; j <= N_bs; j++)
                {
                    if (k & (1ll << j)) v ^= B.bs[j];
                }
                res.add(v);
            }
        }
    }
    res.build();
}

void pushup(int rt) {GetCross(T[rt << 1], T[rt << 1 | 1], T[rt]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = a[l]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
bool res;
void query(int rt, int l, int r, int L, int R, usint x)
{
    if (!res) return;
    if (L <= l && r <= R) {res = T[rt].check(x); return;}
    int mid = (l + r) >> 1;
    if (L <= mid) query(rt << 1, l, mid, L, R, x);
    if (mid <  R) query(rt << 1 | 1, mid + 1, r, L, R, x);
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        int sz; scanf("%d", &sz);
        while (sz--) {usint x; scanf("%u", &x); a[i].add(x);}
        a[i].build();
    }
    build(1, 1, n);
    while (m--)
    {
        int l, r; usint x; scanf("%d%d%u", &l, &r, &x);
        res = true; query(1, 1, n, l, r, x);
        res ? puts("YES") : puts("NO");
    }
	return 0;
}
