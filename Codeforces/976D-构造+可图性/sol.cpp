#include<bits/stdc++.h>
#define pii pair<int, int>
using namespace std;
vector<pii>vec;
int d[301], deg[1001];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &d[i]);
    int x = 1, y = n;
    for (int u = 1; u <= d[n] && x <= y; u++)
    {
        for (int v = u + 1; v <= d[y] + 1; v++)
        {
            vec.push_back({u, v});
            deg[u]++; deg[v]++;
        }
        if (u == d[x]) x++, y--;
    }
    printf("%d\n", (int)vec.size());
    for (pii e : vec) printf("%d %d\n", e.first, e.second);
    // for (int i = 1; i <= d[n] + 1; i++) printf("%d%c", deg[i], " \n"[i == d[n] + 1]);
    return 0;
}