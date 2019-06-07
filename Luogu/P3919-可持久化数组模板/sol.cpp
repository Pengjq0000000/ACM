#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
struct node{int l, r, v;}T[maxn * 20];
int root[maxn * 20];
int a[maxn];
int cnt = 0;
void build(int &rt, int l, int r)
{
	rt = ++cnt;
	if (l == r) {T[rt].v = a[l]; return;}
	int mid = (l + r) >> 1; 
	build(T[rt].l, l, mid);
	build(T[rt].r, mid + 1, r);
}
void update(int &rt, int pre, int l, int r, int pos, int val)
{
	T[rt = ++cnt] = T[pre];
	if (l == r) {T[rt].v = val; return;}
	int mid = (l + r) >> 1;
	if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos, val);
	else update(T[rt].r, T[pre].r, mid + 1, r, pos, val);
}
int query(int rt, int l, int r, int pos)
{
	if (l == r) return T[rt].v;
	int mid = (l + r) >> 1;
	if (pos <= mid) return query(T[rt].l, l, mid, pos);
	else return query(T[rt].r, mid + 1, r, pos);
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	build(root[0], 1, n);
	for (int i = 1; i <= m; i++)
	{
		int pre, opt, pos; scanf("%d%d%d", &pre, &opt, &pos);
		if (opt == 1)
		{
			int val; scanf("%d", &val);
			update(root[i], root[pre], 1, n, pos, val);
		}
		else 
		{
			printf("%d\n", query(root[pre], 1, n, pos));
			root[i] = root[pre];
		}
	}
	return 0;
}
