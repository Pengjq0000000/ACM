#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define inf 0x3f3f3f3f
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n;
int x[20];
int y[20];
int dis[20][20];
int step[40][40][7];
int getdis(int a,int b)
{
    if(a==b) return 0;
    int dx=abs(x[a]-x[b]);
    int dy=abs(y[a]-y[b]);
    if(dx>=2&&dy>=2) return dx+dy;
    if(dx<=4&&dy<=4) return step[20+dx][20+dy][1];
    if(dx==0)
    {
    	if(dy%4==0) return dx+dy;
    	else return dx+dy+2;
	}
	if(dy==0)
	{
		if(dx%4==0) return dx+dy;
		else return dx+dy+2;
	}
    if(dx%4==0||dy%4==0) return dx+dy;
    return dx+dy+2;
    //while(0);
    //return step[20+dx][20+dy][1];
}
int getdis2(int a,int b)
{
    int dx=abs(a);
    int dy=abs(b);
    if(dx>=2&&dy>=2) return dx+dy;
    if(dx<=4&&dy<=4) return step[20+dx][20+dy][1];
    if(dx%4==0||dy%4==0) return dx+dy;
    return dx+dy+2;
    //while(0);
    //return step[20+dx][20+dy][1];
}
struct cell
{
    int x,y;
    int s;
};
queue<cell>q;
int cx[4]={1,0,-1,0};
int cy[4]={0,1,0,-1};
int change[7][4]={	{0,0,0,0},
					{2,3,4,5},	
					{6,2,1,2},	
					{3,6,3,1},	
					{1,4,6,4},	
					{5,1,5,6},	
					{4,5,2,3},	};
void spfa()
{
	memset(step,63,sizeof(step));
	step[20][20][1]=0;
    q.push({20,20,1});
    while(!q.empty())
    {
        cell t=q.front();
        q.pop();
        for(int i=0;i<4;i++)
        {
            int nx=t.x+cx[i];
            int ny=t.y+cy[i];
            int ns=change[t.s][i];
            if(nx>30||ny>30) continue;
            if(nx<10||ny<10) continue;
            if(step[nx][ny][ns]!=inf) continue;
            step[nx][ny][ns]=step[t.x][t.y][t.s]+1;
            q.push({nx,ny,ns});
        }
    }
}
int dp[18][70000];

void ini()
{
    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
            dis[i][j]=inf;
}
int main()
{
    int T;
	scanf("%d",&T);
    spfa();
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d%d",&x[i],&y[i]);
        for(int i=0;i<=n;i++)
            for(int j=0;j<=n;j++)
                dis[i][j]=getdis(i,j); 
		memset(dp,0x3f3f3f3f,sizeof(dp));
		dp[0][1]=0;
        for(int i=1;i<=n;i++)
			dp[i][1<<(i-1)]=dis[0][i];
		for(int i=1;i<(1<<n);i++)
		{
			for(int j=1;j<=n;j++)
			{
				int tmp1=1<<(j-1);
				if((i&tmp1)==0) continue;
				int ii=i^tmp1;
				for(int k=1;k<=n;k++)
				{
					if(k==j) continue; 
					int tmp2=1<<(k-1);
					if((ii&tmp2)==0) continue;
					dp[j][i]=min(dp[j][i],dp[k][ii]+dis[k][j]);
				}
			}
		}
		int ans=1e9;
		int s=(1<<n)-1;
		for(int i=1;i<=n;i++)
			ans=min(ans,dp[i][s]);
		printf("%d\n",ans);
    }
	return 0;
}
