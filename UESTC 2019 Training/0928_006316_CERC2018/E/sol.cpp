#include<bits/stdc++.h>
#define pii pair<int, int>
#define LL long long
using namespace std;
struct Point{int x, y, id;}p[1007];
vector<int>G[1007];
bool cmp1(Point u, Point v) {return (LL)u.y * v.x == (LL)v.y * u.x ? (u.x == 0 && u.y == 0) : (LL)u.y * v.x < (LL)v.y * u.x;}
bool cmp2(Point u, Point v) {return u.x == v.x ? u.y < v.y : u.x < v.x;}
int sz[1007];
void dfs(int u, int fa)
{
    sz[u] = 1;
    for (int v : G[u])
    {
        if (v == fa) continue;
        dfs(v, u); sz[u] += sz[v];
    }
}
int col[1007];
void build(int u, int fa, vector<Point>&vec)
{
    sort(vec.begin(), vec.end(), cmp2);
    Point root = vec[0]; col[u] = root.id;
    for (Point &pt : vec) pt.x -= root.x, pt.y -= root.y; 
    sort(vec.begin(), vec.end(), cmp1);
    assert(vec[0].id == root.id);
    int now = 1;
    vector<Point>table;
    for (int v : G[u])
    {
        if (v == fa) continue;
        int cnt = 0; table.clear();
        while (cnt < sz[v]) cnt++, table.push_back(vec[now++]);
        build(v, u, table); 
    }
}
pii edge[1007];
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i < n; i++)
    {
        scanf("%d %d", &edge[i].first, &edge[i].second);
        G[edge[i].first].push_back(edge[i].second);
        G[edge[i].second].push_back(edge[i].first);
    }
    dfs(0, -1);
    for (int i = 1; i <= n; i++) scanf("%d %d", &p[i].x, &p[i].y), p[i].id = i - 1;
    vector<Point>vec; for (int i = 1; i <= n; i++) vec.push_back(p[i]);
    build(0, -1, vec);
    for (int i = 1; i < n; i++)
    {
        printf("%d %d\n", col[edge[i].first], col[edge[i].second]);
    }
    return 0;
}