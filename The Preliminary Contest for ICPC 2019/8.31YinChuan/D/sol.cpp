#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n, m; scanf("%d%d", &n, &m);
        printf("Case #%d: ", ++cas);
        if (n == 1) printf("%lf %lf\n", 1.0, (double)(m + 1) / (2 * m));
        else printf("%lf %lf\n", 0.5, (double)(m + 1) / (2 * m));
    }
	return 0;
}
