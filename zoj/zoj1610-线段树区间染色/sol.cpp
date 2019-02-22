#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e4 + 7;
int T[maxn << 2], lazy[maxn << 2];
int clr[maxn], ans[maxn];

void build(int rt, int l, int r)
{
    lazy[rt] = -1;
    if (l == r) {T[rt] = -1; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
}

void pushdown(int rt)
{
    if (lazy[rt] == -1) return;
    T[rt << 1] = T[rt << 1 | 1] = lazy[rt];
    lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
    lazy[rt] = -1;
}

void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) 
    {
        T[rt] = lazy[rt] = val;
        return;
    }
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
}

int query(int rt, int l, int r, int pos)
{
    if (l == r) return T[rt];
    pushdown(rt);
    int mid = (l + r) >> 1;
    if (pos <= mid) return query(rt << 1, l, mid, pos);
    else return query(rt << 1 | 1, mid + 1, r, pos);
}

int main()
{
    int m, n = 8007;
    while (scanf("%d", &m) != EOF)
    {
        build(1, 1, n);
        while (m--)
        {
            int x, y, z; scanf("%d%d%d", &x, &y, &z);
            update(1, 1, n, x + 1, y, z);
        }
        MEM(ans, 0); clr[0] = -1;
        for (int i = 1; i <= 8000; i++)
        {
            clr[i] = query(1, 1, n, i);
            if (clr[i] != clr[i - 1]) ans[clr[i]]++;
        }
        for (int i = 0; i <= 8000; i++)
            if (ans[i]) printf("%d %d\n", i, ans[i]);
        puts("");
    }       
    return 0;
}

