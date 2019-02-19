#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 107;
int n;
int can[maxn][maxn], pt[maxn], E[maxn][maxn], val[maxn], cnt[maxn];

void flyod()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                can[i][j] = max(can[i][j], (int)(can[i][k] && can[k][j]));
}

queue<int>q;
int spfa(int s, int t)
{
    if (!can[s][t]) return 0;
    MEM(cnt, 0); MEM(pt, 0);
    while (!q.empty()) q.pop();
    q.push(s); pt[s] += 100;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        cnt[u]++; if (cnt[u] >= n) return can[u][t];
        for (int v = 1; v <= n; v++)
        {
            if (E[u][v] && pt[u] + val[v] > 0 && pt[v] < pt[u] + val[v])
            {
                pt[v] = pt[u] + val[v];
                q.push(v);
            }
        }
    }
    return pt[t] > 0;
} 

int main()
{
    while (scanf("%d", &n) != EOF)
    {
        if (n == -1) break;
        MEM(E, 0); MEM(can, 0);
        for (int i = 1; i <= n; i++)
        {
            int x;
            scanf("%d%d", &val[i], &x);
            while (x--) {int v; scanf("%d", &v); E[i][v] = can[i][v] = 1;}
        }
        flyod();
        if (spfa(1, n)) puts("winnable");
        else puts("hopeless");
        
    }
    return 0;
}

