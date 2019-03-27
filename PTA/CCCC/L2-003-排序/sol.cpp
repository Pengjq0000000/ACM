#include<bits/stdc++.h>
#define LL long long
#define eps 1e-9
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
struct node
{
	double x, y, v;
	bool operator < (const node &rhs) const
	{
		return v > rhs.v;
	}
}p[maxn];
int main()
{
	int n; double T; scanf("%d%lf", &n, &T);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i].x);
	for (int i = 1; i <= n; i++) scanf("%lf", &p[i].y), p[i].v = p[i].y / p[i].x;
	sort(p + 1, p + 1 + n);
	double ans = 0;
	for (int i = 1; i <= n; i++)
	{
		double tmp = min(T, p[i].x);
		if (tmp == p[i].x) ans += p[i].y;
		else ans += p[i].v * tmp;
		T -= tmp; if (T == 0) break;
	}
	printf("%.2lf\n", ans);
	return 0;
}
