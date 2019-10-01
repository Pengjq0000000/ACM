#include<bits/stdc++.h>
using namespace std;
const int maxn = 1007;
char mp[4 * maxn + 3][6 * maxn + 3];
bool connect[maxn * maxn][6];
int r, c; 
int S, T;
vector<int>G[maxn * maxn];
inline int id(int x, int y) {return (x - 1) * c + y;}
void add(int u, int v) 
{
    G[u].push_back(v); G[v].push_back(u);
    //printf("%d %d\n", u, v);
}
void deal(int a, int b)
{
    int x, y = 6 * b - 1;
    if (b % 2 == 1) x = 3 + 4 * (a - 1);
    else x = 5 + 4 * (a - 1);
    if (mp[x - 2][y] == ' ') add(id(a, b), id(a - 1, b));
    if (mp[x + 2][y] == ' ') add(id(a, b), id(a + 1, b));
    if (mp[x - 1][y - 3] == ' ') 
    {
        if (b & 1) add(id(a, b), id(a - 1, b - 1));
        else add(id(a, b), id(a, b - 1));
    }
    if (mp[x - 1][y + 3] == ' ') 
    {
        if (b & 1) add(id(a, b), id(a - 1, b + 1));
        else add(id(a, b), id(a, b + 1));
    }
    if (mp[x + 1][y - 3] == ' ')
    {
        if (b & 1) add(id(a, b), id(a, b - 1));
        else add(id(a, b), id(a + 1, b - 1));
    }
    if (mp[x + 1][y + 3] == ' ')
    {
        if (b & 1) add(id(a, b), id(a, b + 1));
        else add(id(a, b), id(a + 1, b + 1));
    }
    if (mp[x][y] == 'S') S = id(a, b);//printf("S %d %d\n", a, b);
    if (mp[x][y] == 'T') T = id(a, b);//printf("T %d %d\n", a, b); 
}
int dis[maxn * maxn], vis[maxn * maxn];
queue<int>q;
void BFS(int S, int T)
{
    //printf("%d -> %d\n", S, T);
    for (int i = 1; i <= r * c; i++) dis[i] = 1e9, vis[i] = 0;
    q.push(S); vis[S] = 1; dis[S] = 1;
    while (!q.empty())
    {
        int u = q.front(); q.pop();
        for (int v : G[u])
        {
            if (vis[v]) continue;
            dis[v] = dis[u] + 1;
            q.push(v); vis[v] = 1;
        }
    }
    printf("%d\n", dis[T] == 1e9 ? -1 : dis[T]);
}
int main()
{
    int tt; scanf("%d", &tt);
    while (tt--)
    {
        scanf("%d%d", &r, &c);
        for (int i = 1; i <= r * c; i++) G[i].clear();
        getchar();
        for (int i = 1; i <= 4 * r + 3; i++)
        {
            char ch; int now = 0;
            while (ch=getchar(),ch!='\n') mp[i][++now] = ch;
            mp[i][++now] = 0;
            //printf("%s\n", mp[i] + 1);
        }
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                deal(i, j);
        BFS(S, T);
    }
    return 0;
}