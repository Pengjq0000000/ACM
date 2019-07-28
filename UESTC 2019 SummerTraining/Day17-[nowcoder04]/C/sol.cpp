#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e6 + 7;
LL sum[maxn];
struct node{LL mx, mi;}T[maxn << 2];
void pushup(int rt) 
{
    T[rt].mx = max(T[rt << 1].mx, T[rt << 1 | 1].mx);
    T[rt].mi = min(T[rt << 1].mi, T[rt << 1 | 1].mi);
}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt].mx = T[rt].mi = sum[l]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
LL query_min(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].mi;
    int mid = (l + r) >> 1;
    LL res = 1e18;
    if (L <= mid) res = min(res, query_min(rt << 1, l, mid, L, R));
    if (mid <  R) res = min(res, query_min(rt << 1 | 1, mid + 1, r, L, R));
    return res;
}
LL query_max(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].mx;
    int mid = (l + r) >> 1;
    LL res = -1e18;
    if (L <= mid) res = max(res, query_max(rt << 1, l, mid, L, R));
    if (mid <  R) res = max(res, query_max(rt << 1 | 1, mid + 1, r, L, R));
    return res;
}
LL a[maxn], b[maxn];
stack<int>stk;
int posl[maxn], posr[maxn];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    for (int i = 1; i <= n; i++) scanf("%lld", &b[i]), sum[i] = sum[i - 1] + b[i];
    while (!stk.empty()) stk.pop();
    for (int i = 1; i <= n; i++)
    {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if (stk.empty()) posl[i] = 0;
        else posl[i] = stk.top();
        stk.push(i);
    }
    while (!stk.empty()) stk.pop();
    for (int i = n; i >= 1; i--)
    {
        while (!stk.empty() && a[stk.top()] >= a[i]) stk.pop();
        if (stk.empty()) posr[i] = n + 1;
        else posr[i] = stk.top();
        stk.push(i);
    }
    //for (int i = 1; i <= n; i++) printf("%d ", posl[i]);puts("");
    //for (int i = 1; i <= n; i++) printf("%d ", posr[i]);puts("");
    build(1, 0, n);
    LL ans = -1e18;
    for (int i = 1; i <= n; i++)
    {
        int l = posl[i], r = posr[i] - 1;
        LL  sumr, suml;
        if (a[i] > 0)
        {
            sumr = query_max(1, 0, n, i, r);
            suml = query_min(1, 0, n, l, i - 1);
        }
        else 
        {
            sumr = query_min(1, 0, n, i, r);
            suml = query_max(1, 0, n, l, i - 1);
        }
        ans = max(ans, a[i] * (sumr - suml));
        
    }
    printf("%lld\n", ans);
	return 0;
}
