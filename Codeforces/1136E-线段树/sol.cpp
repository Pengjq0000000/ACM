#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
const LL INF = 1e18;
LL T[maxn << 2], lazy[maxn << 2];
LL sum[maxn], a[maxn], k[maxn], det[maxn];
void pushup(int rt) {T[rt] = T[rt << 1] + T[rt << 1 | 1];}
void build(int rt, int l, int r)
{
	lazy[rt] = -INF;
	if (l == r) {T[rt] = a[l]; return;}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}
void pushdown(int rt, int l, int r)
{
	if (lazy[rt] == -INF) return;
	int mid = (l + r) >> 1;
	lazy[rt << 1] = lazy[rt << 1 | 1] = lazy[rt];
	T[rt << 1] = lazy[rt] * (mid - l + 1);
	T[rt << 1 | 1] = lazy[rt] * (r - mid);
	lazy[rt] = -INF;
}
void update(int rt, int l, int r, int L, int R, LL val)
{
	if (L <= l && r <= R)
	{
		T[rt] = val * (r - l + 1);
		lazy[rt] = val;
		return;
 	}
 	pushdown(rt, l, r);
 	int mid = (l + r) >> 1;
 	if (L <= mid) update(rt << 1, l, mid, L, R, val);
 	if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
 	pushup(rt);
}
LL query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return T[rt];
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	LL res = 0;
	if (L <= mid) res += query(rt << 1, l, mid, L, R);
	if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
	for (int i = 1; i < n; i++) scanf("%lld", &k[i]), sum[i] = sum[i - 1] + k[i];
	for (int i = 1; i < n; i++) 
	{
		LL tmp = sum[n - 1] - sum[i - 1];
		a[i] += tmp;
		det[i] = det[i - 1] + tmp;
	}
	det[n] = det[n - 1];
	build(1, 1, n);
	int q; scanf("%d", &q);
	while (q--)
	{
		char op[2]; int x, y;
		scanf(" %s", op); scanf("%d%d", &x, &y);
		if (op[0] == '+') 
		{
			LL tmp = query(1, 1, n, x, x) + y;
			int l = x, r = n;
			while (l < r)
			{
				int mid = (l + r + 1) >> 1;
				LL ck = query(1, 1, n, mid, mid);
				if (ck <= tmp) l = mid;
				else r = mid - 1;
			}
			update(1, 1, n, x, l, tmp);
		}
		else if (op[0] == 's')
		{
			printf("%lld\n", query(1, 1, n, x, y) - (det[y] - det[x - 1]));
		}
	}
	return 0;
}
