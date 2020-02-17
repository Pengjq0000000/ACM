#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int MAXN = 1e5 + 7;
set<int>ans;
vector<pii>G[MAXN];
vector<int>vec;
pii A[MAXN];
bool B[MAXN], vis[MAXN];
void dfs(int u)
{
    vis[u] = 1;
    for (pii v : G[u]) if (!vis[v.fir])
    {
        dfs(v.fir);
        if (B[v.fir]) 
        {
            B[u] ^= 1; B[v.fir] ^= 1;
            ans.insert(v.sec);
        }
    }
}
int main()
{
    int n, m; scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &A[i].fir, &A[i].sec); 
        vec.push_back(A[i].fir);
    }
    sort(A + 1, A + 1 + n);
    sort(vec.begin(), vec.end());
    B[1] = A[1].sec;
    for (int i = 1; i < n; i++) B[i + 1] = A[i].sec ^ A[i + 1].sec;
    B[n + 1] = A[n].sec;
    for (int i = 1, l, r; i <= m; i++)
    {
        scanf("%d%d", &l, &r);
        l = lower_bound(vec.begin(), vec.end(), l) - vec.begin() + 1;
        r = upper_bound(vec.begin(), vec.end(), r) - vec.begin() + 1;
        G[l].emplace_back(r, i);
        G[r].emplace_back(l, i);
    }
    for (int i = 1; i <= n + 1; i++) if (!vis[i])
    {
        dfs(i);
        if (B[i]) {puts("-1"); return 0;}
    }
    printf("%d\n", (int)ans.size());
    for (int x : ans) printf("%d ", x);
    return 0;
}