#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 10007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
struct node
{
    LL alt, mul, add;
    LL sum[4];
}T[maxn << 2];
void pushup(int rt)
{
    for (int i = 1; i <= 3; i++) 
        T[rt].sum[i] = MOD(T[rt << 1].sum[i] + T[rt << 1 | 1].sum[i]);
} 
void build(int rt, int l, int r)
{
    T[rt].alt = T[rt].add = 0;
    T[rt].mul = 1;
    if (l == r) {MEM(T[rt].sum, 0); return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l ,mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
void pushdown(int rt, int l, int r)
{
    int mid = (l + r) >> 1; 
    LL tmp;
    if (T[rt].alt > 0)
    {
        T[rt << 1].alt = T[rt << 1 | 1].alt = T[rt].alt;
        T[rt << 1].add = T[rt << 1 | 1].add = 0;
        T[rt << 1].mul = T[rt << 1 | 1].mul = 1;
        tmp = T[rt].alt;
        for (int i = 1; i <= 3; i++)
        {
            T[rt << 1].sum[i] = MOD((mid - l + 1) * tmp);
            T[rt << 1 | 1].sum[i] = MOD((r - mid) * tmp);
            tmp = MOD(tmp * T[rt].alt);
        } 
        T[rt].alt = 0;
    }
    if (T[rt].mul > 1)
    {
        T[rt << 1].mul = MOD(T[rt << 1].mul * T[rt].mul);
        T[rt << 1].add = MOD(T[rt << 1].add * T[rt].mul);
        T[rt << 1 | 1].mul = MOD(T[rt << 1 | 1].mul * T[rt].mul);
        T[rt << 1 | 1].add = MOD(T[rt << 1 | 1].add * T[rt].mul);
        tmp = T[rt].mul;
        for (int i = 1; i <= 3; i++)
        {
            T[rt << 1].sum[i] = MOD(T[rt << 1].sum[i] * tmp);
            T[rt << 1 | 1].sum[i] = MOD(T[rt << 1 | 1].sum[i] * tmp);
            tmp = MOD(tmp * T[rt].mul);
        }
        T[rt].mul = 1;
    }
    if (T[rt].add > 0)
    {
        T[rt << 1].add = MOD(T[rt << 1].add + T[rt].add);
        T[rt << 1 | 1].add = MOD(T[rt << 1 | 1].add + T[rt].add);
        
        LL val = T[rt].add;
        
        T[rt << 1].sum[3] = MOD(T[rt << 1].sum[3] + MOD((mid - l + 1) * val * val * val) + MOD(3 * val * (T[rt << 1].sum[2] + T[rt << 1].sum[1] * val)));
        T[rt << 1].sum[2] = MOD(T[rt << 1].sum[2] + MOD((mid - l + 1) * val * val) + MOD(2 * val * T[rt << 1].sum[1]));
        T[rt << 1].sum[1] = MOD(T[rt << 1].sum[1] + MOD((mid - l + 1) * val));
        
        T[rt << 1 | 1].sum[3] = MOD(T[rt << 1 | 1].sum[3] + MOD((r - mid) * val * val * val) + MOD(3 * val * (T[rt << 1 | 1].sum[2] + T[rt << 1 | 1].sum[1] * val)));
        T[rt << 1 | 1].sum[2] = MOD(T[rt << 1 | 1].sum[2] + MOD((r - mid) * val * val) + MOD(2 * val * T[rt << 1 | 1].sum[1]));
        T[rt << 1 | 1].sum[1] = MOD(T[rt << 1 | 1].sum[1] + MOD((r - mid) * val));
        
        T[rt].add = 0;
    }
}
void update_add(int rt, int l, int r, int L, int R, LL val)
{
    if (L <= l && r <= R) 
    {
        T[rt].add = MOD(T[rt].add + val);
        T[rt].sum[3] = MOD(T[rt].sum[3] + MOD((r - l + 1) * val * val * val) + MOD(3 * val * (T[rt].sum[2] + T[rt].sum[1] * val)));
        T[rt].sum[2] = MOD(T[rt].sum[2] + MOD((r - l + 1) * val * val) + MOD(2 * val * T[rt].sum[1]));
        T[rt].sum[1] = MOD(T[rt].sum[1] + MOD((r - l + 1) * val));
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update_add(rt << 1, l, mid, L, R, val);
    if (mid <  R) update_add(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}
void update_mul(int rt, int l, int r, int L, int R, LL val)
{
    if (L <= l && r <= R)
    {
        T[rt].mul = MOD(T[rt].mul * val);
        T[rt].add = MOD(T[rt].add * val);
        LL tmp = val;
        for (int i = 1; i <= 3; i++)
        {
            T[rt].sum[i] = MOD(T[rt].sum[i] * tmp);
            tmp = MOD(tmp * val);
        }
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update_mul(rt << 1, l, mid, L, R, val);
    if (mid <  R) update_mul(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);    
}
void update_alt(int rt, int l, int r, int L, int R, LL val)
{
    if (L <= l && r <= R)
    {
        T[rt].alt = val; T[rt].add = 0; T[rt].mul = 1;
        LL tmp = val; 
        for (int i = 1; i <= 3; i++)
        {
            T[rt].sum[i] = MOD((r - l + 1) * tmp);
            tmp = MOD(tmp * val);
        }
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update_alt(rt << 1, l, mid, L, R, val);
    if (mid <  R) update_alt(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);  
}
LL query(int rt, int l, int r, int L, int R, int k)
{
    if (L <= l && r <= R) return T[rt].sum[k];
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    LL res = 0;
    if (L <= mid) res += query(rt << 1, l, mid, L, R, k);
    if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R, k);
    return MOD(res);
}
int main()
{
    int n, m; 
    while (scanf("%d%d", &n, &m))
    {
        if (n == 0 && m == 0) break;
        build(1, 1, n);
        while (m--)
        {
            int op, x, y, c; scanf("%d%d%d%d", &op, &x, &y, &c);
            if (op == 1) update_add(1, 1, n, x, y, c);
            else if (op == 2) update_mul(1, 1, n, x, y, c);
            else if (op == 3) update_alt(1, 1, n, x, y, c);
            else printf("%lld\n", MOD(query(1, 1, n, x, y, c)));
        }
    }
    return 0;
}

