#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
const int MAXN = 1e6 + 7;
char s[MAXN];
struct node{int pre_max, pre_min, sum;}T[MAXN << 2];
int lazy[MAXN << 2];

void pushup(int rt)
{
    T[rt].sum = T[lson].sum + T[rson].sum;
    T[rt].pre_max = max(T[lson].pre_max, T[lson].sum + T[rson].pre_max);
    T[rt].pre_min = min(T[lson].pre_min, T[lson].sum + T[rson].pre_min);
}
void update(int rt, int l, int r, int pos, int v)
{
    if (l == r) {T[rt].sum = T[rt].pre_max = T[rt].pre_min = v; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos, v);
    else update(rson, mid + 1, r, pos, v);
    pushup(rt);
}
int main()
{
    int n; scanf("%d", &n);
    scanf(" %s", s);
    int pos = 1;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == 'L') pos = max(1, pos - 1);
        else if (s[i] == 'R') pos++;
        else if (s[i] == '(') update(1, 1, n, pos, 1);
        else if (s[i] == ')') update(1, 1, n, pos, -1);
        else update(1, 1, n, pos, 0);

        if (T[1].pre_min >= 0 && T[1].sum == 0) printf("%d ", T[1].pre_max);
        else printf("-1 ");
    }
    return 0;
}