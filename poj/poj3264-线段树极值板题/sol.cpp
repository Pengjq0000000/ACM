#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstdio>
#include<cstdlib>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 50007;
const int INF = 1e9;
struct node {int max, min;}T[maxn << 2];
int a[maxn];
void pushup(int rt)
{
    T[rt].max = max(T[rt << 1].max, T[rt << 1 | 1].max);
    T[rt].min = min(T[rt << 1].min, T[rt << 1 | 1].min);
}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt].max = T[rt].min = a[l]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
int query_max(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].max;
    int mid = (l + r) >> 1;
    int res = -INF;
    if (L <= mid) res = max(res, query_max(rt << 1, l, mid, L, R));
    if (mid <  R) res = max(res, query_max(rt << 1 | 1, mid + 1, r, L, R));
    return res; 
}
int query_min(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].min;
    int mid = (l + r) >> 1;
    int res = INF;
    if (L <= mid) res = min(res, query_min(rt << 1, l, mid, L, R));
    if (mid <  R) res = min(res, query_min(rt << 1 | 1, mid + 1, r, L, R));
    return res;
}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    build(1, 1, n);
    while (m--)
    {
        int x, y; scanf("%d%d", &x, &y);
        printf("%d\n",query_max(1, 1, n, x, y) - query_min(1, 1, n, x, y));
    }
    return 0;
}

