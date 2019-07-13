#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int n, m;
int a[maxn], l[maxn], r[maxn], res[maxn];
vector<int>pos;
int T[maxn << 2];
void pushup(int rt) {T[rt] = min(T[rt << 1], T[rt << 1 | 1]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = res[l]; return;}
    int mid = (l + r) >> 1;
    build(rt << 1, l, mid);
    build(rt << 1 | 1, mid + 1, r);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int mid = (l + r) >> 1;
    int res = 2e9;
    if (L <= mid) res = min(res, query(rt << 1, l, mid, L, R));
    if (mid <  R) res = min(res, query(rt << 1 | 1, mid + 1, r, L, R));
    return res;
}
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] == 0) pos.pb(i); 
        else a[i]++, l[i] = r[i] = 2e9;
    } 
    for (int st : pos)
    {
        for (int i = st + 1; a[i] != 0 && i <= n; i++)
        {
            r[i] = max(r[i - 1], a[i]);
        }
    }
    reverse(pos.begin(), pos.end());
    for (int st: pos)
    {
        for (int i = st - 1; a[i] != 0 && a[i] >= 1; i--)
        {
            l[i] = max(l[i + 1], a[i]);
            res[i] = min(l[i], r[i]);
        }
    }
    // for (int i = 1; i <= n; i++) printf("%d ", l[i]); puts("");
    // for (int i = 1; i <= n; i++) printf("%d ", r[i]); puts("");
    // for (int i = 1; i <= n; i++) printf("%d ", res[i]); puts("");
    build(1, 1, n);
    while (m--)
    {
        int l, r, x; scanf("%d%d%d", &l, &r, &x);
        int tmp = query(1, 1, n, l, r);
        if (tmp <= x) puts("Yes");
        else puts("No");
    }
	return 0;
}
