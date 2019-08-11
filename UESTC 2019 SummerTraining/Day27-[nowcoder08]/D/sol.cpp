#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, m, h, dis[maxn];
struct node{int x, y, z;};
inline int getid(int x, int y, int z) {return (x - 1) * m * h + (y - 1) * h + z;}
inline int getdis(node p, node q) {return abs(p.x - q.x) + abs(p.y - q.y) + abs(p.z - q.z);}
inline bool check(int x, int y, int z) { return (1 <= x && x <= n && 1 <= y && y <= m && 1 <= z && z <= h);}
vector<node>ls;
queue<node>q;
int dx[] = {0, 0, 1, -1, 0, 0};
int dy[] = {0, 0, 0, 0, 1, -1};
int dz[] = {1, -1, 0, 0, 0, 0};
int main()
{
    MEM(dis, 0x3f3f3f3f);
    int tt;
	scanf("%d%d%d%d", &n, &m, &h, &tt);
    int up = sqrt(n * m * h);
    while (tt--)
    {
        int op, x, y, z; scanf("%d%d%d%d", &op, &x, &y, &z);
        if (op == 1) 
        {
            ls.pb({x, y, z});
            if (ls.size() < up) continue;
            for (node x : ls) 
            {
                q.push(x); 
                dis[getid(x.x, x.y, x.z)] = 0;
            }
            ls.clear();
            while (!q.empty())
            {
                node p = q.front(); q.pop();
                int u = getid(p.x, p.y, p.z);
                for (int k = 0; k < 6; k++)
                {
                    int nx = p.x + dx[k], ny = p.y + dy[k], nz = p.z + dz[k];
                    if (!check(nx, ny, nz)) continue;
                    int v = getid(nx, ny, nz);
                    if (dis[u] + 1 < dis[v])
                    {
                        dis[v] = dis[u] + 1;
                        q.push({nx, ny, nz});
                    }
                }
            }
        }
        else 
        {
            node u = {x, y, z};
            int ans = dis[getid(x, y, z)];
            for (node v : ls) ans = min(ans, getdis(u, v));
            printf("%d\n", ans);
        }
    }
	return 0;
}
