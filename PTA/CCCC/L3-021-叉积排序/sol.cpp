#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 5007;
struct node
{
	LL x, y;
}p[maxn], t[maxn];
bool cmp(node a, node b)
{
	return a.y * b.x < a.x * b.y;
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%lld%lld", &p[i].x, &p[i].y);
	LL ans = 1e18;
	for (int i = 1; i <= n; i++)
	{
		int tot = 0;
		for (int j = 1; j <= n; j++)
		{
			if (i == j) continue;
			t[tot].x = p[i].x - p[j].x;
			t[tot].y = p[i].y - p[j].y;
			tot++;
		}
		sort(t, t + tot, cmp);
		for (int j = 0; j < tot; j++)
		{
			//printf("%lf %lf\n", t[j].x, t[j].y);
			ans = min(ans, abs(t[j].x * t[(j + 1) % tot].y - t[j].y * t[(j + 1) % tot].x));
		}
	}
	double res = ans * 1.000;
	res *= 0.500;
	printf("%.3lf\n", res);
	return 0;
}
