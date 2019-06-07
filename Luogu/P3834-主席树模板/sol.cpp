#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
struct node{int l, r, sum;}T[maxn * 20];
vector<int>vv; 
int getid(int x) {return lower_bound(vv.begin(), vv.end(), x) - vv.begin() + 1;}
int a[maxn], root[maxn];

int cnt = 0;
void update(int &rt, int pre, int l, int r, int pos)
{
	T[rt = ++cnt] = T[pre];
	T[rt].sum++;
	if (l == r) return;
	int mid = (l + r) >> 1;
	if (pos <= mid) update(T[rt].l, T[pre].l, l, mid, pos);
	else update(T[rt].r, T[pre].r, mid + 1, r, pos);
}
int query(int rt, int pre, int l, int r, int k)
{
	if (l == r) return l;
	int sum = T[T[rt].l].sum - T[T[pre].l].sum;
	int mid = (l + r) >> 1; 
	if (sum >= k) return query(T[rt].l, T[pre].l, l, mid, k);
	else return query(T[rt].r, T[pre].r, mid + 1, r, k - sum);
}

int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]), vv.pb(a[i]);
	sort(vv.begin(), vv.end());
	vv.erase(unique(vv.begin(), vv.end()), vv.end());
	for (int i = 1; i <= n; i++)
	{
		a[i] = getid(a[i]);
		update(root[i], root[i - 1], 1, n, a[i]);
	}
	while (m--)
	{
		int x, y, k; scanf("%d%d%d", &x, &y, &k);
		int pos = query(root[y], root[x - 1], 1, n, k);
		printf("%d\n", vv[pos - 1]);
	}
	return 0;
}
