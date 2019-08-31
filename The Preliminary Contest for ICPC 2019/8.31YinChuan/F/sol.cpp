#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 207;
LL dis[maxn][maxn][maxn];
int e[maxn][maxn];
int id[maxn], r[maxn];
bool cmp(int x, int y) {return r[x] < r[y];}
int main()
{
	int T, cas = 0; scanf("%d", &T);
    while (T--)
    {
        int n, q; scanf("%d%d", &n, &q);
        for (int i = 1; i <= n; i++) scanf("%d", &r[i]), id[i] = i;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                for (int k = 1; k <= n; k++)
                    dis[i][j][k] = 1e16;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                {
                    scanf("%lld", &dis[0][i][j]);
                }
        sort(id + 1, id + 1 + n, cmp);
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    dis[k][i][j] = min(dis[k - 1][i][j], dis[k - 1][i][id[k]] + dis[k - 1][id[k]][j]);
        printf("Case #%d:\n", ++cas);
        while (q--)
        {
            int u, v, w; scanf("%d%d%d", &u, &v, &w);
            int kk = 0;
            for (int i = 1; i <= n; i++)
                if (r[id[i]] <= w) kk = i;
            printf("%lld\n", dis[kk][u][v]);
        }
    }
	return 0;
}
