#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
struct node
{
	int num, c, l, r;
	bool operator < (const node &rhs) const
	{
		return c < rhs.c;
	}
}a[maxn];
int main()
{
	int n, s, sum = 0; scanf("%d%d", &n, &s);
	for (int i = 1; i <= n; i++) 
	{
		scanf("%d%d%d%d", &a[i].num, &a[i].c, &a[i].l, &a[i].r);
		sum += a[i].num;
	}
	sort(a + 1, a + 1 + n);
	int ans = 0, det = -1;
	if (sum <= s) det = 1;
	for (int i = 1; i <= n; i++)
	{
		while (a[i].num + det >= a[i].l && a[i].num + det <= a[i].r && abs(sum - s) > 0)
		{
			a[i].num += det;
			sum += det;
			ans += a[i].c;
		}
	}
	if (sum != s) puts("impossible");
	else printf("%d\n", ans);
	return 0;
}
