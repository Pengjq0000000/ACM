#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node
{
	int ad, nxt, val;
	node(int ad, int val, int nxt) : ad(ad), val(val), nxt(nxt) {}
	node() {}
}a[maxn];
int head;
set<int>vis;
vector<node>ans, del;
int main()
{
	int n;
	scanf("%d%d", &head, &n);
	for (int i = 1; i <= n; i++)
	{
		int ad; scanf("%d", &ad); a[ad].ad = ad;
		scanf("%d%d", &a[ad].val, &a[ad].nxt);
	}
	while (head != -1)
	{
		if (vis.count(abs(a[head].val))) 
		{
			del.pb(node(a[head].ad, a[head].val, -1)); 
			if (del.size() > 1) del[del.size() - 2].nxt = a[head].ad;
			head = a[head].nxt; 
			continue;
		}
		vis.insert(abs(a[head].val));
		ans.pb(node(a[head].ad, a[head].val, -1)); 
		if (ans.size() > 1) ans[ans.size() - 2].nxt = a[head].ad;
		head = a[head].nxt; 
	}
	
	for (node x : ans) 
	{
		printf("%05d %d ", x.ad, x.val);
		if (x.nxt == -1) printf("-1\n"); else printf("%05d\n", x.nxt);
	}
	for (node x : del) 
	{
		printf("%05d %d ", x.ad, x.val);
		if (x.nxt == -1) printf("-1\n"); else printf("%05d\n", x.nxt);
	}
	return 0;
}
