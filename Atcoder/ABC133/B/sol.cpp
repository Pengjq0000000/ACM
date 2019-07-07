#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int p[20][20];
int main()
{
	int n, d; scanf("%d%d", &n, &d);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= d; j++)
        {
            scanf("%d", &p[i][j]);
        }
    }
    int ans = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int tmp = 0;
            for (int k = 1; k <= d; k++) tmp += (p[i][k] - p[j][k]) * (p[i][k] - p[j][k]);
            int sq = sqrt(tmp);
            if (sq * sq == tmp) ans++;
        }
    printf("%d\n", ans);
	return 0;
}
