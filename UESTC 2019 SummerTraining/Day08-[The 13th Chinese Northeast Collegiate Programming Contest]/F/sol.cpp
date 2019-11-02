#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define mp(a, b) make_pair(a, b)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
vector<int>E[maxn];
int dp[maxn][7], deg[maxn][7];
char belong[10], actor[10];
queue<pii>q;
int main()
{
	int T; scanf("%d", &T);
    while (T--) 
    {
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) E[i].clear();
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= 6; j++)
                deg[i][j] = dp[i][j] = 0;
        while (m--)
        {
            int u, v; scanf("%d%d", &u, &v);
            E[v].pb(u);
            for (int j = 1; j <= 6; j++) deg[u][j]++;
        }
        scanf(" %s", belong + 1);
        scanf(" %s", actor + 1);
        for (int i = 1; i <= n; i++)
            if (!deg[i][1])
                for (int j = 1; j <= 6; j++) 
                {
                    dp[i][j] = (actor[j] == '1' ? 1 : -1);
                    q.push(mp(i, j));
                }
        
        for (int j = 1; j <= 6; j++) 
            if (actor[j] == '1')
                belong[j] = (!(belong[j] - 'A')) + 'A';
        while (!q.empty())
        {
            pii u = q.front(); q.pop();
            for (int v : E[u.fir])
            {
                int pre = u.sec - 1; if (!pre) pre = 6;
                int tmp = dp[v][pre];
                if (belong[pre] == belong[u.sec]) dp[v][pre] = max(dp[v][pre], dp[u.fir][u.sec]);
                else if (dp[u.fir][u.sec] == -1) dp[v][pre] = 1;
                deg[v][pre]--;
                if (!deg[v][pre] && !dp[v][pre]) dp[v][pre] = -1;
                if (!tmp && dp[v][pre]) q.push(mp(v, pre)); // sta settled
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (!dp[i][1]) printf("D");
            else 
            {
                if (dp[i][1] == 1) printf("%c", belong[1]);
                else printf("%c", belong[1] == 'A' ? 'B' : 'A');
            }
        }
        puts("");
    }
	return 0;
}
