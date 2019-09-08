#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    T[rt] = -2e9 - 1;
    if (l == r) return;
    int mid = (l + r) >> 1;
    build(lson, l, mid);
    build(rson, mid + 1, r);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) {T[rt] = val; return;}
    int mid = (l + r) >> 1;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
int query(int rt, int l, int r, int val)
{
    if (l == r) return T[rt] >= val ? l : -1;
    int mid = (l + r) >> 1;
    if (T[rson] >= val) return query(rson, mid + 1, r, val);
    else return query(lson, l, mid, val);
}

int n, m;
int ans[maxn];
pii a[maxn];
int main()
{
	scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i].first), a[i].second = i;
    sort(a + 1, a + 1 + n);
    build(1, 1, n);
    for (int i = n; i >= 1; i--)
    {
        //printf("%d %d\n", a[i].first, a[i].second);
        int pos = query(1, 1, n, a[i].first);
        if (pos < a[i].second) ans[a[i].second] = -1;
        else ans[a[i].second] = pos - a[i].second - 1;
        update(1, 1, n, a[i].second, a[i].first - m);
    }
    for (int i = 1; i <= n; i++) 
        printf("%d%c", ans[i], i == n ? '\n' : ' ');
	return 0;
}
