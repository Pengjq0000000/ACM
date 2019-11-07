#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int maxn = 2e5 + 7;
vector<int>vec;
vector<pii>G[maxn];
pii edge[maxn];
inline int id(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
bool vis[maxn];
int f[maxn];
int fa(int x) {return x == f[x] ? x : f[x] = fa(f[x]);}
int sz[maxn];
struct node{int id, u, v;}keyp[maxn];
int cnt;
void dfs(int u, int fa)
{
    sz[u] = 1; vis[u] = 1;
    for (pii x : G[u])
    {
        int v = x.fir;
        if (v == fa) continue;
        dfs(v, u); sz[u] += sz[v];
        if (sz[v] == 1 && keyp[cnt].id == -1)
        {
            keyp[cnt] = {x.sec, u, x.fir};
        }
    }
}

int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        vec.clear();
        int n; scanf("%d", &n);
        for (int i = 1; i <= n; i++) 
        {
            scanf("%d%d", &edge[i].fir, &edge[i].sec);
            vec.push_back(edge[i].fir);
            vec.push_back(edge[i].sec);
        }
        sort(vec.begin(), vec.end());
        vec.erase(unique(vec.begin(), vec.end()), vec.end());
        int N = vec.size();
        for (int i = 1; i <= N; i++) vis[i] = 0, f[i] = i, G[i].clear();
        for (int i = 1; i <= n; i++)
        {
            edge[i].fir = id(edge[i].fir);
            edge[i].sec = id(edge[i].sec);
        }
        for (int i = 1; i <= n; i++)
        {
            int u = fa(edge[i].fir), v = fa(edge[i].sec);
            if (u != v) 
            {
                f[u] = v; 
                G[edge[i].fir].push_back({edge[i].sec, i});
                G[edge[i].sec].push_back({edge[i].fir, i});
            }
        }
        cnt = 0;
        for (int i = 1; i <= N; i++)if (!vis[i]) 
        {
            ++cnt; keyp[cnt] = {-1, -1, -1};
            dfs(i, 0);
        }
        printf("%d\n", cnt - 1);
        for (int i = 1; i < cnt; i++)
        {
            printf("%d %d %d\n", keyp[i].id, vec[keyp[i].v - 1], vec[keyp[i + 1].u - 1]);
        }
    }
    return 0;
}