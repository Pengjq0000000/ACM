#include<bits/stdc++.h>
#define lson (T[rt].l)
#define rson (T[rt].r)
using namespace std;
int read() 
{
    int x = 0, f = 1;
    char c = getchar();
    while (c < '0' || c > '9') f = (c == '-') ? -1 : f, c = getchar();
    while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
    return x * f;
}
const int maxn = 2e5 + 7;
vector<int>vec;
inline int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
int n; 
struct node {int MIN, l, r;}T[maxn * 19];
int tot, root[maxn], A[maxn], B[maxn];

void update(int &rt, int l, int r, int pos, int v)
{
    if (!rt) T[rt = ++tot].MIN = 2e9;
    T[rt].MIN = min(T[rt].MIN, v);
    if (l == r) return;
    int mid = (l + r) >> 1;
    if (pos <= mid) update(T[rt].l, l, mid, pos, v);
    else update(T[rt].r, mid + 1, r, pos, v);
}
int query(int rt, int l, int r, int L, int R)
{
    if (!rt) return 2e9;
    if (L <= l && r <= R) return T[rt].MIN;
    int mid = (l + r) >> 1, res = 2e9;
    if (L <= mid && T[rt].l) res = min(res, query(T[rt].l, l, mid, L, R));
    if (mid <  R && T[rt].r) res = min(res, query(T[rt].r, mid + 1, r, L, R));
    return res;
}
bool check(int pos, int x, int y)
{
    if (pos == 0) return true;
    if (x == 1) return false;
    int res = query(root[pos], 1, n, 1, x - 1);
    return res < y;
}
int main()
{
    int t; scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        tot = 0; vec.clear();
        for (int i = 1; i <= n; i++) 
        {
            A[i] = read();
            root[i] = 0;
            vec.push_back(A[i]);
        } 
        for (int i = 1; i <= n; i++) B[i] = read();
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int ans = 0;
        for (int i = 1; i <= n; i++)
        {
            A[i] = getid(A[i]);
            int L = 0, R = i;
            while (L < R)
            {
                int mid = (L + R + 1) >> 1;
                if (check(mid, A[i], B[i])) L = mid;
                else R = mid - 1;
            }
            update(root[L + 1], 1, n, A[i], B[i]);
            ans = max(ans, L + 1);
        }
        printf("%d\n", ans);
        for (int i = 1; i <= tot; i++) T[i].l = T[i].r = T[i].MIN = 0;
    }
    return 0;
}