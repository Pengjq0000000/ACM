#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pdd pair<double, double>
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 57;
const double PI = acos(-1);
double dis[maxn];
pdd p[maxn], Q;
double getdis(pdd x, pdd y)
{
    return sqrt((x.first - y.first) * (x.first - y.first) + (x.second - y.second) * (x.second - y.second));
}
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lf%lf", &p[i].first, &p[i].second);
        }
        scanf("%lf%lf", &Q.first, &Q.second);
        for (int i = 1; i <= n; i++) dis[i] = getdis(p[i], Q);
        p[0] = p[n]; p[n + 1] = p[1];
        double ans = 0;
        for (int i = 1; i <= n; i++)
        {
            double a = getdis(p[i - 1], p[i]);
            double b = getdis(p[i], p[i + 1]);
            double c = getdis(p[i - 1], p[i + 1]);
            double tmp = (a * a + b * b - c * c) / (2 * a * b);
            ans += dis[i] * (PI - acos(tmp));
        }
        printf("Case #%d: %.3lf\n", ++cas, ans);
    }
	return 0;
}
