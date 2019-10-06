#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
int n, m;
char mp[30][30];
pii p[500];
int cnt = 0;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char ch[4] = {'U', 'D', 'R', 'L'};
int vis[30][30];
int d[25][25][25][25];
int nowx, nowy;
bool check(int x, int y)
{
    if (x < 1 || x > n || y < 1 || y > m || mp[x][y] == '0') return false;
    return true;
}
void dfs(int x, int y, int dir)
{
    if (x < 1 || x > n || y < 1 || y > m || mp[x][y] == '0' || vis[x][y]) return;
    vis[x][y] = 1;
    d[nowx][nowy][x][y] = dir;
    for (int i = 0; i < 4; i++)
        dfs(x + dx[i], y + dy[i], dir);
}

vector<int>path;
int Now_x, Now_y;
void move(int u, int v)
{
    for (int dir : path)
    {
        if (check(u + dx[dir], v + dy[dir])) u += dx[dir], v += dy[dir]; 
    }
    //printf("[u, v] = [%d %d]\n", u, v);
    while (Now_x != u || Now_y != v)
    {
        int dir = d[Now_x][Now_y][u][v];
        path.push_back(dir);
        Now_x += dx[dir]; Now_y += dy[dir];
        if (check(u + dx[dir], v + dy[dir])) u += dx[dir], v += dy[dir]; 
    }
}
void test()
{
    while (1)
    {
        int x, y, u, v;
        scanf("%d%d%d%d", &x, &y, &u, &v);
        while (x != u || y != v)
        {
            int dir = d[x][y][u][v];
            printf("%c->", ch[dir]);
            x += dx[dir]; y += dy[dir];
            printf("%d %d\n", x, y);
        }
    }
}
int main()
{
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            scanf(" %c", &mp[i][j]);
            if (mp[i][j] == '1') p[++cnt] = {i, j};
        }
    for (int i = 1; i <= cnt; i++)
    {
        memset(vis, 0, sizeof(vis));
        for (int j = 0; j < 4; j++) 
        {
            nowx = p[i].fir; nowy = p[i].sec;
            vis[nowx][nowy] = 1;
            dfs(p[i].fir + dx[j], p[i].sec + dy[j], j);
        }
    }
    //test();
    Now_x = p[1].fir; Now_y = p[1].sec;
    for (int i = 2; i <= cnt; i++)
    {
        move(p[i].fir, p[i].sec);
    }
    if (path.size() > 50000) assert(false); 
    for (int dir : path) printf("%c", ch[dir]); puts("");
    return 0;
}