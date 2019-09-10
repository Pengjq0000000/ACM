#include<bits/stdc++.h>
using namespace std;
const int maxn = 1e6 + 7;
const int N = 1e6;
struct node{int l, r, v;}T[maxn * 30];
int cnt;
void update(int &rt, int l, int r, int pos, int val)
{
    if (!rt) {rt = ++cnt; T[rt].l = T[rt].r = 0; T[rt].v = 1e9;}
    T[rt].v = min(T[rt].v, val);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, l, mid, pos, val);
    else update(T[rt].r, mid + 1, r, pos, val);
}
int qL, qR;
int query(int rt, int l, int r)
{
    if (!rt) return 1e9;
    if (qL <= l && r <= qR) return T[rt].v;
    int mid = (l + r) >> 1, res = 1e9;
    if (qL <= mid) res = min(res, query(T[rt].l, l, mid));
    if (mid <  qR) res = min(res, query(T[rt].r, mid + 1, r));
    return res;
}
int rt[51];
int main()
{
    int op;
    while (~scanf("%d", &op))
    {
        if (op == 0)
        {
            cnt = 0;
            for (int i = 0; i <= 50; i++) rt[i] = 0;
        }
        else if (op == 1)
        {
            int x, y, c; scanf("%d%d%d", &x, &y, &c);
            update(rt[c], 1, N, y, x);
        }
        else if (op == 2)
        {
            int x; scanf("%d%d%d", &x, &qL, &qR);
            int res = 0;
            for (int i = 0; i <= 50; i++)
            {
                if (!rt[i]) continue;
                int p = query(rt[i], 1, N);
                if (p <= x) res++;
            }
            printf("%d\n", res);
        }
        else return 0;
    }
    return 0;
}
