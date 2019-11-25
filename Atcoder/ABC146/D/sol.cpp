#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
vector<pair<int, int> >G[MAXN];
int col[MAXN], ans = 0;
void dfs(int u, int fa, int c)
{
    int cnt = 1;
    for (auto x : G[u])
    {
        if (x.fir == fa) continue;
        if (cnt == c) ++ cnt;
        col[x.sec] = cnt++;
        ans = max(ans, col[x.sec]);
        dfs(x.fir, u, col[x.sec]);
    }
}
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, u, v; i < n; i++)
    {
        scanf("%d%d", &u, &v);
        G[u].emplace_back(v, i); G[v].emplace_back(u, i);
    } 
    dfs(1, 0, 0); 
    printf("%d\n", ans);
    for (int i = 1; i < n; i++) printf("%d\n", col[i]);
    return 0;
}