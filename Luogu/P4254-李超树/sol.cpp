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
const int maxn = 1e5 + 7;
const int N = 1e5 + 7;
int best[N << 2];
double k[maxn], b[maxn];
double f(int id, int x) {return k[id] * (x - 1) + b[id];}
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
double query(int rt, int l, int r, int pos)
{
    if (l == r) return f(best[rt], pos);
    int mid = (l + r) / 2;
    double res = f(best[rt], pos);
    if (pos <= mid) res = max(res, query(lson, l, mid, pos));
    else res = max(res, query(rson, mid + 1, r, pos));
    return res;
}
int main()
{
	int n, cnt = 0; scanf("%d", &n);
    while (n--)
    {
        char s[10]; scanf("%s", s);
        if (s[0] == 'P') 
        {
            ++cnt; scanf("%lf%lf", &b[cnt], &k[cnt]);
            update(1, 1, N, cnt);
        }
        else 
        {
            int x; scanf("%d", &x);
            printf("%d\n", (int)query(1, 1, N, x) / 100);
            //printf("%lf\n", query(1, 1, n, x));
        }
    }
	return 0;
}
