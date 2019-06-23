#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
const int N = 2e5 + 7;
struct node
{
	int val, id;
	bool operator < (const node &rhs) const
	{
		return val > rhs.val;
	}
};
struct seg
{
	int l, r; 
	bool operator < (const seg &rhs) const
	{
		if (r == rhs.r) return l < rhs.l;
		return r < rhs.r;
	}
}a[maxn];
vector<int>v;
priority_queue<node>pq;
int getid(int x) {return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;}
int T[N << 2], lazy[N << 2];
void pushup(int rt) {T[rt] = max(T[rt << 1], T[rt << 1 | 1]);}
void pushdown(int rt, int l, int r)
{
	if (lazy[rt] == 0) return;
	int mid = (l + r) >> 1;
	lazy[rt << 1] += lazy[rt]; lazy[rt << 1 | 1] += lazy[rt];
	T[rt << 1] += lazy[rt];
	T[rt << 1 | 1] += lazy[rt];
	lazy[rt] = 0;
}
void update(int rt, int l, int r, int L, int R, int val)
{
	if (L <= l && r <= R)
	{
		lazy[rt] += val; 
		T[rt] += val;
		return;
	}
	pushdown(rt, l, r);
	int mid = (l + r) >> 1;
	if (L <= mid) update(rt << 1, l, mid, L, R, val);
	if (mid <  R) update(rt << 1 | 1, mid + 1, r, L, R, val);
	pushup(rt);
}

vector<int>bg[maxn * 10];
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		int ux, uy, vx, vy; scanf("%d%d%d%d", &ux, &uy, &vx, &vy);
		a[i].r = uy; a[i].l = vy; 
		v.pb(a[i].l); v.pb(a[i].r);
	}
	sort(a + 1, a + 1 + n);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	int mx = v.size() + 1;
	for (int i = 1; i <= n; i++)
	{
		a[i].l = getid(a[i].l);
		a[i].r = getid(a[i].r);
		bg[a[i].l].pb(i);
		update(1, 1, mx, a[i].l, a[i].r, 1);
	}
	int ans = 0;
	for (int pos = 1; pos < mx; pos++)
	{
		for (int id : bg[pos]) 
		{
			pq.push({a[id].r, id});
			update(1, 1, mx, a[id].l, a[id].r, -1);
		}
		while (pq.size())
		{
			if (pq.top().val < pos) 
			{
				int id = pq.top().id; pq.pop();
				update(1, 1, mx, a[id].l, a[id].r, 1);
			}
			else break;
		}
		//printf("%d : %d\n", pos, (int)pq.size());
		ans = max(ans, (int)pq.size() + T[1]);
	}
	printf("%d\n", ans);
	return 0;
}
