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
const int maxn = 2e5 + 7;
const int N = 1e5;
int n, r, a[maxn], cnt[maxn];
vector<int>Y[maxn];
int T[maxn << 2];
void pushup(int rt) {T[rt] = max(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = a[l]; return;}
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, int val)
{
    if (l == r) {T[rt] += val; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, val);
    else update(rson, mid + 1, r, pos, val);
    pushup(rt);
}
int main()
{
	scanf("%d%d", &n, &r);
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        Y[x].pb(y);
        cnt[y]++;
    }
    for (int i = 0; i <= N; i++)
    {
        a[i] = cnt[i];
        if (i + r <= N) a[i] += cnt[i + r];
        if (i + 2 * r <= N) a[i] += cnt[i + 2 * r];
    }
    build(1, 0, N);
    int ans = 0;
    for (int X = 0; X <= N; X++)
    {
        int res = 0;
        for (int i = 0; i <= 2; i++)
        {
            int x = X + i * r;
            if (x > N) break;
            for (int y : Y[x])
            {
                res++;
                update(1, 0, N, y, -1);
                if (y - r >= 0) update(1, 0, N, y - r, -1);
                if (y - 2 * r >= 0) update(1, 0, N, y - 2 * r, -1);
            }
        }
        ans = max(res + T[1], ans);
        for (int i = 0; i <= 2; i++)
        {
            int x = X + i * r;
            if (x > N) break;
            for (int y : Y[x])
            {
                update(1, 0, N, y, 1);
                if (y - r >= 0) update(1, 0, N, y - r, 1);
                if (y - 2 * r >= 0) update(1, 0, N, y - 2 * r, 1);
            }
        }
    }
    printf("%d\n", ans);
	return 0;
}
