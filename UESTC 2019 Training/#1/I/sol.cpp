#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
set<int>E[maxn], notvis;
int n, m, t[maxn], dis[maxn], ans[maxn];
queue<int>q;
void dij(int s)
{
    notvis.clear();
    for (int i = 1; i <= n; i++) dis[i] = 1e9, notvis.insert(i);
    q.push(s); dis[s] = 0;
    notvis.erase(s);
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        int tot = 0;
        for (int v : notvis)
        {
            if (!E[u].count(v))
            {
                t[++tot]= v; 
                if (dis[v] < dis[u] + 1);
                {
                    dis[v] = dis[u] + 1;
                    q.push(v);
                }
            }
        }
        for (int i = 1; i <= tot; i++) notvis.erase(t[i]);
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if (i != s) ans[++cnt] = (dis[i] == 1e9 ? -1 : dis[i]);
    for (int i = 1; i <= cnt; i++)
        printf("%d%c", ans[i], i == cnt ? '\n' : ' ');
    
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d", &n, &m);
        for (int i = 1; i <= n; i++) E[i].clear();
        for (int i = 1, u, v; i <= m; i++)
        {
            scanf("%d%d", &u, &v);
            E[u].insert(v);
            E[v].insert(u);
        }
        int s; scanf("%d", &s);
        dij(s);
    }
	return 0;
}
