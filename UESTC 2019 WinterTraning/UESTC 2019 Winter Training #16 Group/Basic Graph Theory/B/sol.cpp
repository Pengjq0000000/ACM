#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 107;
double dp[maxn][maxn], w[maxn][maxn];
map<string, int>id;
int main()
{
    int n, cas = 0;
    while (scanf("%d",&n) != EOF)
    {
        if (n == 0) break;
        id.clear(); MEM(w, 0);
        for (int i = 1; i <= n; i++)
        {
            string s; cin >> s;
            id[s] = i;
        }
        int m; scanf("%d", &m);
        while (m--)
        {
            string s, ss;
            double x;
            cin >> s >> x >> ss;
            int u = id[s], v = id[ss];
            w[u][v] = max(w[u][v], x); 
        }
        for (int k = 1; k <= n; k++)
            for (int i = 1; i <= n; i++)
                for (int j = 1; j <= n; j++)
                    w[i][j] = max(w[i][j], w[i][k] * w[k][j]);
        int flg = 0;
        for (int i = 1; i <= n; i++) 
            if (w[i][i] > 1) flg = 1;
        printf("Case %d: %s\n", ++cas, flg ? "Yes" : "No");
    }
    return 0;
}

