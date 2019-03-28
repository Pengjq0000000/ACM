#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 10007;
int fa[maxn], cnt[maxn], num[maxn], sum[maxn], vis[maxn], have[maxn];
struct node
{
	int id, cnt; double s, num;
	node(int id, double s, double num, int cnt) : id(id), s(s), num(num), cnt(cnt) {}
	node() {}
	bool operator < (const node &rhs) const
	{
		if (s == rhs.s) return id < rhs.id;
		return s > rhs.s;
	}
};
vector<node>ans;
int find(int x)
{
	if (x == fa[x]) return fa[x];
	return fa[x] = find(fa[x]);
}
vector<int>v;
int main()
{
	for (int i = 0; i <= 10000; i++) fa[i] = i;
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		v.clear();
		int now, y, z; scanf("%d%d%d", &now, &y, &z);
		v.pb(y); v.pb(z);
		int k; scanf("%d", &k);
		while (k--) {int x; scanf("%d", &x); v.pb(x);}
		int a, b; scanf("%d%d", &a, &b);
		int t = find(now);
		num[t] += a; sum[t] += b; 
		if (!have[now]) {have[now] = 1; cnt[t]++;} 
		for (int x : v)
		{
			if (x == -1) continue;
			int xx = find(now), yy = find(x);
			if (!have[x]) {have[x] = 1; cnt[yy]++;}
			if (xx == yy) continue;
			if (xx > yy) swap(xx, yy);
			fa[yy] = xx; num[xx] += num[yy]; sum[xx] += sum[yy]; cnt[xx] += cnt[yy];
		}
	}
	for (int i = 0; i <= 10000; i++)
	{
		int x = find(i);
		if (cnt[x] && !vis[x]) 
		{
			vis[x] = 1;
			double tmp = cnt[i];
			ans.pb(node(i, (double)sum[i] / tmp, (double)num[i] / tmp, cnt[i]));
		} 
	}
		
	sort(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (node tmp : ans) printf("%04d %d %.3lf %.3lf\n", tmp.id, tmp.cnt, tmp.num, tmp.s); 
	return 0;
}
