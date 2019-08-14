#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
const int N = 1e5 + 2;
int T[maxn << 2], lazy[maxn << 2];
void pushup(int rt) {T[rt] = max(T[rt << 1], T[rt << 1 | 1]);}
void pushdown(int rt, int l, int r)
{
    if (lazy[rt] == 0) return;
    lazy[rt << 1] += lazy[rt]; T[rt << 1] += lazy[rt];
    lazy[rt << 1 | 1] += lazy[rt]; T[rt << 1 | 1] += lazy[rt];
    lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val)
{
    if (L <= l && r <= R) {T[rt] += val; lazy[rt] += val; return;}
    pushdown(rt, l, r);
    int mid = (l + r) / 2;
    if (L <= mid) update(rt << 1, l, mid, L, R, val);
    if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
    pushup(rt);
}

int lp[maxn], rp[maxn];
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &lp[i], &rp[i]); rp[i]--;
        update(1, 1, N, lp[i], rp[i], 1);
    }
    int ans = 1e9;
    for (int i = 1; i <= n; i++)
    {
        update(1, 1, N, lp[i], rp[i], -1);
        ans = min(ans, T[1]);
        update(1, 1, N, lp[i], rp[i], 1);
    }
    printf("%d\n", ans);
	return 0;
}
