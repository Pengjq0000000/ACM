#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
int n, p[MAXN], val[MAXN], cnt[MAXN];
pii e;
bool vis[MAXN];
vector<int>G[MAXN];
int getmex(int u)
{
    int res = 0;
    for (int v : G[u]) if (val[v] != -1) cnt[val[v]]++;
    for (int x = 0; x <= n; x++) if (cnt[x] == 0)
    {
        res = x;
        break;
    }
    for (int v : G[u]) if (val[v] != -1) cnt[val[v]]--;
    return res;
}
void dfs(int u)
{
    vis[u] = 1;
    for (int v : G[u])
    {
        if (vis[v]) 
        {
            if (val[v] == -1) e = {u, v};
            continue; 
        }
        dfs(v);
    }
    val[u] = getmex(u);
}
int main() 
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &p[i]);
        G[p[i]].push_back(i);
    }
    memset(val, -1, sizeof(val));
    for (int i = 1; i <= n; i++) if (val[i] == -1) dfs(i);
    val[e.fir] = getmex(e.fir);
    int u = p[e.fir];
    while (u != e.fir)
    {
        val[u] = getmex(u);
        u = p[u];
    } 
    if (getmex(e.fir) == val[e.fir]) puts("POSSIBLE");
    else puts("IMPOSSIBLE");
    return 0;
}