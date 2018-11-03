#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

using namespace std;
const int maxn = 1e5 + 7;
struct Node
{
    int lazy, sum, min;
} seg[maxn * 4];
int n, m, b[maxn];

void pushup(int rt)
{
    seg[rt].sum = seg[rt << 1].sum + seg[rt << 1 | 1].sum;
    seg[rt].min = min(seg[rt << 1].min, seg[rt << 1 | 1].min);
}

void pushdown(int rt, int l, int r)
{
    if(seg[rt].lazy)
    {
        int mid = (l + r) >> 1;
        seg[rt << 1].min += seg[rt].lazy;
        seg[rt << 1 | 1].min += seg[rt].lazy;
        seg[rt << 1].lazy += seg[rt].lazy;
        seg[rt << 1 | 1].lazy += seg[rt].lazy;
        seg[rt].lazy = 0;
    }
}

void build(int rt, int l, int r)
{
    seg[rt].lazy = 0;
    if(l == r)
    {
        seg[rt].sum = 0;
        seg[rt].min = b[l];
        return;
    }
    int mid = (l + r) >> 1;
    build(lson);
    build(rson);
    pushup(rt);
}

void update1(int rt, int l, int r, int L, int R, int x)
{
    if(L <= l && r <= R)
    {
        seg[rt].lazy += x;
        seg[rt].min += x;
        return;
    }
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    if(mid >= L) update1(lson, L, R, x);
    if(mid < R) update1(rson, L, R, x);
    pushup(rt);
}

void update2(int rt, int l, int r, int L, int R)
{

    if(L <= l && r <= R && l == r)
    {
        seg[rt].min = b[l];
        seg[rt].sum++;
        return ;
    }
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    if(mid >= L && seg[rt << 1].min == 0) update2(lson, L, R);
    if(mid < R && seg[rt << 1 | 1].min == 0) update2(rson, L, R);
    pushup(rt);
}

int querySum(int rt, int l, int r, int L, int R)
{
    if(L <= l && r <= R) return seg[rt].sum;
    int mid = (l + r) >> 1;
    pushdown(rt, l, r);
    int ans = 0;
    if(mid >= L) ans += querySum(lson, L, R);
    if(mid < R) ans += querySum(rson, L, R);
    return ans;
}


int main()
{
    while(scanf("%d%d", &n, &m) != EOF)
    {
        for(int i = 1; i <= n; i++) scanf("%d", &b[i]);
        build(1, 1, n);
        while(m--)
        {
            int l, r; char s[10]; scanf("%s %d %d", s, &l, &r);
            if(s[0] == 'a')
            {
                update1(1, 1, n, l, r, -1);
                update2(1, 1, n, l, r);
            }
            else
            {
                printf("%d\n", querySum(1, 1, n, l, r));
            }

        }
    }
    return 0;
}


/*
5 12
1 5 2 4 3
add 1 4
query 1 4
add 2 5
query 2 5
add 3 5
query 1 5
add 2 4
query 1 4
add 2 5
query 2 5
add 2 2
query 1 5
*/

