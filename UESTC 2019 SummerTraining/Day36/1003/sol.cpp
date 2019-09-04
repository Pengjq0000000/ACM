#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 10000 + 7;
double p[maxn];
double ans, Q;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = 0; i < n; i++) 
        {
            scanf("%lf", &p[i]);
            p[i] = 1 - p[i];
        }
        sort(p, p + n);
        ans = 0; Q = 1;
        for (int i = 0; i < n; i++)
        {
            double tmp = ans * p[i] + Q * (1 - p[i]);
            if (tmp < ans) break;
            else 
            {
                Q *= p[i];
                ans = tmp;
            }
        }
        printf("%.10lf\n", ans);
    }
	return 0;
}
