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
	int x, y;
	node(int x, int y) : x(x), y(y){}
	node(){}
	bool operator < (const node &rhs) const
	{
		if (x == rhs.x) return y < rhs.y;
		return x < rhs.x;
	}
}seg[maxn];
int a[maxn];
priority_queue<int>q;
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		MEM(a, 0);
		int n, m; scanf("%d%d", &n, &m);
		while (!q.empty()) q.pop();
		for (int i = 1; i <= n; i++) q.push(-i);
		for (int i = 1; i <= m; i++) scanf("%d%d", &seg[i].x, &seg[i].y);
		sort(seg + 1, seg + 1 + m);
		for (int j = seg[1].x; j <= seg[1].y; j++)
		{
			int tmp = -q.top(); q.pop();
			a[j] = tmp;
		}
		int last = 1;
		for (int i = 2; i <= m; i++)
		{
			if (seg[i].x >= seg[last].x && seg[i].y <= seg[last].y) continue;
			int l = seg[last].x;
			int r = min(seg[i].x - 1, seg[last].y);
			for (int j = l; j <= r; j++) q.push(-a[j]);
			int st = max(seg[i].x - 1, seg[last].y);
			for (int j = st + 1; j <= seg[i].y; j++)
			{
				int tmp = -q.top(); q.pop();
				a[j] = tmp;
			}
			last = i;
		}
		for (int i = 1; i < n; i++) printf("%d ", a[i] == 0 ? 1 : a[i]);
		printf("%d", a[n] == 0 ? 1 : a[n]);
		puts("");
	}
	return 0;
}

