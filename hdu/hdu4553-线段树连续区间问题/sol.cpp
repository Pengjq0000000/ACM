#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
struct node {int pre, suf, mx;} T[2][maxn << 2]; // 0-DS 1-NS
int lazy[2][maxn << 2];
void pushup(int rt, int l, int r, int k)
{
    int mid = (l + r) >> 1;
    T[k][rt].pre = T[k][rt << 1].pre + (T[k][rt << 1].pre == mid - l + 1 ? T[k][rt << 1 | 1].pre : 0);
    T[k][rt].suf = T[k][rt << 1 | 1].suf + (T[k][rt << 1 | 1].suf == r - mid ? T[k][rt << 1].suf : 0);
    T[k][rt].mx = max(T[k][rt << 1].mx, T[k][rt << 1 | 1].mx);
    T[k][rt].mx = max(T[k][rt].mx, T[k][rt << 1].suf + T[k][rt << 1 | 1].pre);
}
void build(int rt, int l, int r, int k)
{
    lazy[k][rt] = -1;
    if (l == r)
    {
        T[k][rt].pre = T[k][rt].suf = T[k][rt].mx = 1;
        return;
    }
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid, k);
    build(rt << 1 | 1, mid + 1, r, k);
    pushup(rt, l, r, k);
}
void pushdown(int rt, int l, int r)
{
    int mid = (l + r) >> 1;
    for (int k = 0; k < 2; k++)
    {
        if (lazy[k][rt] == -1) continue;
        lazy[k][rt << 1] = lazy[k][rt << 1 | 1] = lazy[k][rt];
        T[k][rt << 1].pre = T[k][rt << 1].suf = T[k][rt << 1].mx = lazy[k][rt] ? mid - l + 1 : 0;
        T[k][rt << 1 | 1].pre = T[k][rt << 1 | 1].suf = T[k][rt << 1 | 1].mx = lazy[k][rt] ? r - mid : 0;
        lazy[k][rt] = -1;
    }
}
void update(int rt, int l, int r, int L, int R, int k, int val)
{
    if (L <= l && r <= R)
    {
        T[k][rt].pre = T[k][rt].suf = T[k][rt].mx = val ? r - l + 1 : 0;
        lazy[k][rt] = val;
        return;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (L <= mid) update(rt << 1, l, mid, L, R, k, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, k, val);
    pushup(rt, l, r, k);
}
int query(int rt, int l, int r, int k, int need)
{
    if (l == r)
    {
        if (T[k][rt].mx >= need) return l;else return -1;
    }
    pushdown(rt, l, r);
    int mid = (l + r) >> 1;
    if (T[k][rt << 1].mx >= need) return query(rt << 1, l, mid, k, need);
    else if (T[k][rt << 1].suf + T[k][rt << 1 | 1].pre >= need) return mid - T[k][rt << 1].suf + 1;
    else if (T[k][rt << 1 | 1].mx >= need) return query(rt << 1 | 1, mid + 1, r, k, need);
    else return -1;
}

int main()
{
    int t, cas = 0; scanf("%d", &t);
    while (t--)
    {
        printf("Case %d:\n", ++cas);
        int n, m; scanf("%d%d", &n, &m);
        build(1, 1, n, 0);
        build(1, 1, n, 1);
        while (m--)
        {
            char s[10]; scanf(" %s", s);
            int x, y;
            if (s[0] == 'D')
            {
                scanf("%d", &x);
                int tmp = query(1, 1, n, 0, x);
                if (tmp > 0)
                {
                    printf("%d,let's fly\n", tmp);
                    update(1, 1, n, tmp, tmp + x - 1, 0, 0);
                }
                else printf("fly with yourself\n");
            }
            else if (s[0] == 'N')
            {
                scanf("%d", &x);
                int tmp = query(1, 1, n, 0, x);
                if (tmp <= 0) tmp = query(1, 1, n, 1, x);
                if (tmp > 0)
                {
                    printf("%d,don't put my gezi\n", tmp);
                    update(1, 1, n, tmp, tmp + x - 1, 0, 0);
                    update(1, 1, n, tmp, tmp + x - 1, 1, 0);
                }
                else printf("wait for me\n");
            }
            else if (s[0] == 'S')
            {
                scanf("%d%d", &x, &y);
                printf("I am the hope of chinese chengxuyuan!!\n");
                update(1, 1, n, x, y, 0, 1);
                update(1, 1, n, x, y, 1, 1);
            }
        }
    }
    return 0;
}


/*
2
100 3
DS 3
NS 100
DS 4

5 6
DS 3
NS 2
NS 4
STUDY!! 1 5
DS 4
NS 2

*/





