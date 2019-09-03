#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define lson (rt << 1)
#define rson (rt << 1 | 1)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int n, y;
int t[maxn], k[maxn], best[maxn << 2];
LL ans[maxn];
LL f(int id, int x) {return (LL)k[id] * x + t[id];}
LL g(int x) {return t[x - 1] + y;}
void update(int rt, int l, int r, int x)
{
    if (f(x, l) > f(best[rt], l) && f(x, r) > f(best[rt], r)) {best[rt] = x; return;}
    if (f(x, l) <= f(best[rt], l) && f(x, r) <= f(best[rt], r)) return;
    int mid = (l + r) / 2;
    if (k[best[rt]] < k[x])
    {
        if (f(best[rt], mid) < f(x, mid)) update(lson, l, mid, best[rt]), best[rt] = x;
        else update(rson, mid + 1, r, x);
    }
    else
    {
        if (f(best[rt], mid) < f(x, mid)) update(rson, mid + 1, r, best[rt]), best[rt] = x;
        else update(lson, l, mid, x);
    }
}
LL query(int rt, int l, int r, int pos)
{
    if (l == r) return f(best[rt], pos);
    int mid = (l + r) / 2;
    LL res = f(best[rt], pos);
    if (pos <= mid) res = max(res, query(lson, l, mid, pos));
    else res = max(res, query(rson, mid + 1, r, pos));
    return res;
}
LL F(int pos, int x) {return max(g(pos), query(1, 1, y, x));}

int main()
{
	while (~scanf("%d %d", &n, &y))
    {
        for (int i = 1; i <= (y << 2); i++) best[i] = 0;
        t[0] = -y;
        for (int i = 1; i <= n; i++) scanf("%d", &t[i]), k[i] = n - i + 1;
        sort(t + 1, t + 1 + n);
        int minpos = n;
        update(1, 1, y, minpos);
        LL now, nex;
        for (int x = y; x >= 1; x--)
        {
            now = F(minpos, x);
            nex = max(f(minpos - 1, x), F(minpos - 1, x));
            while (minpos > 1 && nex <= now) 
            {
                minpos--;
                update(1, 1, y, minpos);
                now = nex;
                nex = max(f(minpos - 1, x), F(minpos - 1, x));
            }
            ans[x] = now;
        }
        for (int i = 1; i <= y; i++) printf("%lld%c", ans[i], i == y ? '\n' : ' ');
    }
	return 0;
}
