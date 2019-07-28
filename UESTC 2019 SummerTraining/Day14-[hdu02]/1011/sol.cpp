#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
struct node
{
    int sz, v[50];
    void push_back(int x) {v[sz++] = x;}
    void print() {for (int i = 0; i < sz; i++) printf("%d ", v[i]); puts("");}
}T[maxn << 2];
void unite(node &res, node x, node y)
{
    int sz1 = x.sz, sz2 = y.sz;
    int pos1 = 0, pos2 = 0;
    //printf("x:");x.print();
    //printf("y:");y.print();
    res.sz = 0;
    while (res.sz < 50 && (pos1 < sz1 || pos2 < sz2))
    {
        if (pos1 == sz1) res.pb(y.v[pos2++]);
        else if (pos2 == sz2) res.pb(x.v[pos1++]);
        else if (x.v[pos1] > y.v[pos2]) res.pb(x.v[pos1++]);
        else res.pb(y.v[pos2++]);
    }
    //printf("res:");res.print();
}
void pushup(int rt) {unite(T[rt], T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r)
{
    T[rt].sz = 0;
    if (l == r) {T[rt].pb(a[l]); return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}

node rres;
void query(int rt, int l, int r, int L, int R)
{
    //printf("l=%d r=%d\n", l, r);
    if (L <= l && r <= R) {unite(rres, rres, T[rt]); return;}
    int mid = (l + r) >> 1;
    if (L <= mid) query(rt << 1, l, mid, L, R);
    if (mid <  R) query(rt << 1 | 1, mid + 1, r, L, R);
}
int main()
{
    int n, m;
    while (scanf("%d%d", &n, &m) != EOF)
    {
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        build(1, 1, n);
        while (m--)
        {
            int l, r; scanf("%d%d", &l, &r);
            rres.sz = 0;
            query(1, 1, n, l, r);
            LL ans = -1;
            int sz = rres.sz;
            for (int i = 0; i < sz - 2; i++)
            {
                if (rres.v[i] < rres.v[i + 1] + rres.v[i + 2]) 
                {
                    ans = (LL)rres.v[i] + rres.v[i + 1] + rres.v[i + 2];
                    break;
                }
            }
            printf("%lld\n", ans);
        }
    }
	return 0;
}
/*
12 11
1 1 1 2 3 3 3 3 4 4 5 1
2 4
1 3
1 6
2 7
4 5
4 8
10 12
3 5
3 6
1 10
1 12
 */