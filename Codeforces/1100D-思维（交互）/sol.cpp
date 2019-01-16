#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1007;
int nowx,nowy;
int vis[maxn][maxn],cnt[5],x[maxn],y[maxn];
int dx[5]={0,1,1,-1,-1};
int dy[5]={0,1,-1,1,-1};
void read()
{
    printf("%d %d\n",nowx,nowy);
    fflush(stdout);
    int k,xx,yy;scanf("%d%d%d",&k,&xx,&yy);
    if (k<=0) exit(0);
    vis[x[k]][y[k]]=0;
    x[k]=xx,y[k]=yy;
    vis[x[k]][y[k]]=1;
}

int vaild(int x,int y)
{
    return (x>=1 && x<=999 && y>=1 && y<=999);
}

int getdir()
{
    for (int i=1;i<=666;i++)
    {
        if (x[i]<500 && y[i]<500) cnt[1]++;
        if (x[i]<500 && y[i]>500) cnt[2]++;
        if (x[i]>500 && y[i]<500) cnt[3]++;
        if (x[i]>500 && y[i]>500) cnt[4]++;
    }
    int tmp=777,dir;
    for (int i=1;i<=4;i++) 
    {
        if (tmp>cnt[i] && vaild(nowx+dx[i],nowy+dy[i])) {tmp=cnt[i];dir=i;}
    }
    return dir;
}

void move(int dir)
{
    int xx=nowx+dx[dir],yy=nowy+dy[dir];
    if (vis[xx][yy]) yy-=dy[dir];
    nowx=xx,nowy=yy;
    read();
}

int main()
{
    scanf("%d%d",&nowx,&nowy);
    for (int i=1;i<=666;i++) 
    {
        scanf("%d%d",&x[i],&y[i]);
        vis[x[i]][y[i]]=1;
    }
    
    while (nowx<500) {nowx++;read();}
    while (nowx>500) {nowx--;read();}
    while (nowy<500) {nowy++;read();}
    while (nowy>500) {nowy--;read();}
    int dir=getdir();
    while (1)
    {
        move(dir);
    }
    return 0;
}



