

struct node {int l, r; LL sum, tg;}T[maxn * 65];
int tot = 0, root[maxn];
void update(int &rt, int pre, int l, int r, int L, int R, int val)
{
    T[rt = ++tot] = T[pre];
    T[rt].sum += (LL)val * (R - L + 1);
    if (L <= l && r <= R) {T[rt].tg += val; return;}
    int mid = (l + r) >> 1;
    if (L <= mid) update(T[rt].l, T[pre].l, l, mid, L, min(R, mid), val);
    if (mid <  R) update(T[rt].r, T[pre].r, mid + 1, r, max(L, mid + 1), R, val);
}
LL query(int rt, int pre, int l, int r, int L, int R, LL add)
{
    if (L <= l && r <= R) return T[rt].sum - T[pre].sum + add * (r - l + 1);
    int mid = (l + r) >> 1; LL res = 0;
    add += T[rt].tg - T[pre].tg;
    if (L <= mid) res += query(T[rt].l, T[pre].l, l, mid, L, min(R, mid), add);
    if (mid <  R) res += query(T[rt].r, T[pre].r, mid + 1, r, max(L, mid + 1), R, add);
    return res;
}

