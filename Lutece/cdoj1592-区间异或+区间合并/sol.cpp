#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node{int suf[2], pre[2], mx[2];} T[maxn << 2];
int a[maxn], lazy[maxn << 2];
void pushup(int rt, int l, int r)
{
	int mid = (l + r) >> 1;
	for (int k = 0; k <= 1; k++)
	{
		int pre = T[rt << 1].pre[k]; 
		int suf = T[rt << 1 | 1].suf[k]; 
		T[rt].pre[k] = pre + (pre == mid - l + 1 ? T[rt << 1 | 1].pre[k] : 0);
		T[rt].suf[k] = suf + (suf == r - mid ? T[rt << 1].suf[k] : 0);
		T[rt].mx[k] = max(T[rt << 1].mx[k], T[rt << 1 | 1].mx[k]);
		T[rt].mx[k] = max(T[rt].mx[k], T[rt << 1].suf[k] + T[rt << 1 | 1].pre[k]); 
	}
}
void build(int rt, int l, int r)
{
	lazy[rt] = 0;
	if (l == r)
	{
		int k = a[l];
		T[rt].pre[k] = T[rt].suf[k] = T[rt].mx[k] = 1;
		return;
	}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt, l, r);
}
void pushdown(int rt)
{
	if (lazy[rt] == 0) return;
	lazy[rt << 1] ^= 1; lazy[rt << 1 | 1] ^= 1;
	swap(T[rt << 1].pre[0], T[rt << 1].pre[1]);
	swap(T[rt << 1].suf[0], T[rt << 1].suf[1]);
	swap(T[rt << 1].mx[0], T[rt << 1].mx[1]);
	swap(T[rt << 1 | 1].pre[0], T[rt << 1 | 1].pre[1]);
	swap(T[rt << 1 | 1].suf[0], T[rt << 1 | 1].suf[1]);
	swap(T[rt << 1 | 1].mx[0], T[rt << 1 | 1].mx[1]);
	lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R)
{
	if (L <=l && r <= R) 
	{
		lazy[rt] ^= 1; 
		swap(T[rt].pre[0], T[rt].pre[1]);
		swap(T[rt].suf[0], T[rt].suf[1]);
		swap(T[rt].mx[0], T[rt].mx[1]);
		return;
	}
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (L <= mid) update(rt << 1, l, mid, L, R);
	if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R);
	pushup(rt, l, r);
}
int query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return T[rt].mx[1];
	pushdown(rt);
	int mid = (l + r) >> 1;
	if (R <= mid) return query(rt << 1, l, mid, L, R);
	else if (L > mid) return query(rt << 1 | 1, mid + 1, r, L, R);
	else
	{
		int mxsuf = min(mid - L + 1, T[rt << 1].suf[1]);
		int mxpre = min(R - mid, T[rt << 1 | 1].pre[1]);
		int lres = query(rt << 1, l, mid, L, R);
		int rres = query(rt << 1 | 1, mid + 1, r, L, R);
		int res = max(lres, rres); res = max(res, mxsuf + mxpre);
		return res;
	}
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(1, 1, n);
	int m; scanf("%d", &m);
	while (m--)
	{
		int op, x, y; scanf("%d%d%d", &op, &x, &y);
		if (op == 1) update(1, 1, n, x, y);
		else printf("%d\n", query(1, 1, n, x, y));
	}
	return 0;
}
