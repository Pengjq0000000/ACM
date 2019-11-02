#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 207;
int dis[maxn][maxn][4];
int n;
char mp[maxn][maxn];

struct node
{
    int x,y,dir,dis;
    node(int x,int y,int dir,int dis):x(x),y(y),dir(dir),dis(dis){}
    node(){}
};
queue<node>q;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        scanf(" %s",mp[i]+1);
        for (int j=1;j<=n;j++)
            for (int k=0;k<4;k++) dis[i][j][k]=1e9;
    }
    q.push(node(1,1,0,0));
    dis[1][1][0]=0;
    while (!q.empty())
    {
        node now=q.front();q.pop();
        if (now.x==n && now.y==n && now.dir==0) break;
        int nx=now.x+dx[now.dir],ny=now.y+dy[now.dir];
        if (nx>=1 && nx<=n && ny>=1 && ny<=n && mp[nx][ny]=='.' && dis[nx][ny][now.dir]>now.dis+1)
        {
            q.push(node(nx,ny,now.dir,now.dis+1));
            dis[nx][ny][now.dir]=now.dis+1;
        }
        int nd=(now.dir+1)%4;
        if (dis[now.x][now.y][nd]>now.dis+1)
        {
            q.push(node(now.x,now.y,nd,now.dis+1));
            dis[now.x][now.y][nd]=now.dis+1;
        }
    }

    printf("%d\n",dis[n][n][0]);
    return 0;
}
