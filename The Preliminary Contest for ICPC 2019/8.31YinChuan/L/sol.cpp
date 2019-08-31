#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
struct node{int min, lazy, cnt;}T[maxn << 2];
void pushup(int rt)
{
    T[rt].min = min(T[lson].min, T[rson].min);
    T[rt].cnt = 0;
    if (T[lson].min == T[rt].min) T[rt].cnt += T[lson].cnt;
    if (T[rson].min == T[rt].min) T[rt].cnt += T[rson].cnt;
}
void pushdown(int rt)
{
    if (T[rt].lazy == 0) return;
    T[lson].lazy += T[rt].lazy; T[lson].min += T[rt].lazy;
    T[rson].lazy += T[rt].lazy; T[rson].min += T[rt].lazy;
    pushup(rt);
    T[rt].lazy = 0;
}
void build(int rt, int l, int r)
{
    T[rt].lazy = 0;
    if (l == r)
    {
        T[rt].min = 0; T[rt].cnt = 1;
        return;
    }
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R)
    {
        T[rt].lazy += val;
        T[rt].min += val;
        return;
    }
    int mid = (l + r) / 2;
    pushdown(rt);
    if (L <= mid) update(lson, l, mid, L, R, val);
    if (mid <  R) update(rson, mid + 1, r, L, R, val);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt].min == -1 ? T[rt].cnt : 0;
    int mid = (l + r) / 2;
    pushdown(rt);
    int res = 0;
    if (L <= mid) res += query(lson, l, mid, L, R);
    if (mid <  R) res += query(rson, mid + 1, r, L, R);
    return res;
}
stack<pii>stkgt, stkls;
unordered_map<int, int>last;
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        last.clear();
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]), last[a[i]] = 0;
        build(1, 1, n);
        while (stkgt.size()) stkgt.pop();
        while (stkls.size()) stkls.pop();
        LL ans = 0;
        for (int i = 1; i <= n; i++)
        {
            int pos = last[a[i]], val;
            update(1, 1, n, pos + 1, i, -1);
            last[a[i]] = i;

            int now = i;
            while (stkgt.size() && stkgt.top().fir <= a[i])
            {
                pos = stkgt.top().sec; val = stkgt.top().fir; stkgt.pop();
                update(1, 1, n, pos, now - 1, a[i] - val);
                now = pos;
            }
            stkgt.push(make_pair(a[i], now));

            now = i;
            while (stkls.size() && stkls.top().fir >= a[i])
            {
                pos = stkls.top().sec; val = stkls.top().fir; stkls.pop();
                update(1, 1, n, pos, now - 1, -(a[i] - val));
                now = pos;
            }
            stkls.push(make_pair(a[i], now));
            ans += query(1, 1, n, 1, i);
        }
        printf("Case #%d: %lld\n", ++cas, ans);
    }
	return 0;
}
