#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5e5 + 7;
int l[maxn], r[maxn];
LL a[maxn], sum[maxn], minl[maxn], minr[maxn];
struct node
{
	int val, pos;
	node(int val, int pos) : val(val), pos(pos) {}
	node() {}
};
stack<node>s;
int main()
{
	int n; scanf("%d", &n);
	sum[0] = 0;
	for (int i = 1; i <= n; i++) scanf("%lld", &a[i]), sum[i] = sum[i - 1] + a[i];
	for (int i = 1; i <= n; i++)
	{
		while (!s.empty() && s.top().val >= a[i]) s.pop();
		if (!s.empty()) l[i] = s.top().pos;
		else l[i] = 0;
		s.push(node(a[i], i));
	}
	while (!s.empty()) s.pop();
	for (int i = n; i >= 1; --i)
	{
		while (!s.empty() && s.top().val >= a[i]) s.pop();
		if (!s.empty()) r[i] = s.top().pos;
		else r[i] = n + 1;
		s.push(node(a[i], i));
	}
	LL ans = 0;
	for (int i = 1; i <= n; i++)
	{
		if (a[i] < 0) continue;
		LL tmp = a[i] * (sum[r[i] - 1] - sum[l[i]]);
		ans = max(ans, tmp);
	}
	for (int i = 1; i <= n; i++)
	{
		minl[i] = min((LL)0, minl[i - 1] + a[i]);
	}
	for (int i = n ; i >= 1; --i)
	{
		minr[i] = min((LL)0, minr[i + 1] + a[i]);
		if (a[i] < 0) ans = max(ans, a[i] * (LL)(minl[i - 1] + minr[i + 1] + a[i]));
	}
	printf("%lld\n", ans);
	return 0;
}
