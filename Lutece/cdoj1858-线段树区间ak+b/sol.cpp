#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define uint unsigned int
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node{uint sum, lazy, K, A, B, det;} T[maxn << 2];
uint a[maxn];
int n, m; 

void pushup(int rt) 
{
	T[rt].sum = T[rt << 1].sum + T[rt << 1 | 1].sum;
	T[rt].A = T[rt << 1].A + T[rt << 1 | 1].A;
}
void build(int rt, int l, int r)
{
	if (l == r) {T[rt].A = a[l]; T[rt].sum = 0; return;}
	int mid = (l + r) >> 1;
	build(rt << 1, l, mid);
	build(rt << 1 | 1, mid + 1, r);
	pushup(rt);
}
void pushdown(int rt, uint l, uint r)
{
	uint mid = (l + r) >> 1;
	uint len1 = mid - l + 1, len2 = r - mid;
	
	T[rt << 1].A += T[rt].lazy * len1;
	T[rt << 1].lazy += T[rt].lazy;
	T[rt << 1].det += T[rt].det + T[rt].lazy * T[rt << 1].K;
	T[rt << 1].K += T[rt].K; T[rt << 1].B += T[rt].B;
	T[rt << 1].sum += T[rt].K * T[rt << 1].A;
	T[rt << 1].sum -= T[rt].det * len1;
	T[rt << 1].sum += T[rt].B * len1; 
	
	T[rt << 1 | 1].A += T[rt].lazy * len2;
	T[rt << 1 | 1].lazy += T[rt].lazy;
	T[rt << 1 | 1].det += T[rt].det + T[rt].lazy * T[rt << 1 | 1].K;
	T[rt << 1 | 1].K += T[rt].K; T[rt << 1 | 1].B += T[rt].B;
	T[rt << 1 | 1].sum += T[rt].K * T[rt << 1 | 1].A;
	T[rt << 1 | 1].sum -= T[rt].det * len2;
	T[rt << 1 | 1].sum += T[rt].B * len2; 
	
	T[rt].K = T[rt].lazy = T[rt].B = T[rt].det = 0;
}
void update(int rt, int l, int r, int L, int R, uint val, uint b, int op)
{
	if (L <= l && r <= R)
	{
		if (op == 1)
		{
			T[rt].lazy += val; 
			T[rt].A += val * (uint)(r - l + 1);
			T[rt].det += T[rt].K * val;
		}
		else if (op == 2)
		{
			T[rt].B += b; T[rt].K += val;
			T[rt].sum += b * (uint)(r - l + 1);
			T[rt].sum += val * T[rt].A;
		}
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) update(rt << 1, l, mid, L, R, val, b, op);
	if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val, b, op);
	pushup(rt);
}
uint query(int rt, int l, int r, int L, int R)
{
	if (L <= l && r <= R) return T[rt].sum;
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	uint res = 0;
	if (L <= mid) res += query(rt << 1, l, mid, L, R);
	if (mid <  R) res += query(rt << 1 | 1, mid + 1, r, L, R);
	return res;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%u", &a[i]);
	build(1, 1, n);
	while (m--)
	{
		int op; scanf("%d", &op);
		int l, r; uint k, b;
		if (op == 1) {scanf("%d%d%u", &l, &r, &k); update(1, 1, n, l, r, k, 0, 1);}
		else if (op == 2) {scanf("%d%d%u%u", &l, &r, &k, &b); update(1, 1, n, l, r, k, b, 2);}
		else if (op == 3) {scanf("%d%d", &l, &r); printf("%u\n", query(1, 1, n, l, r));}
	}
	return 0;
}
