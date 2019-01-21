#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 2050;

char mp[maxn][maxn];
int id[maxn][maxn],type[maxn][maxn];
struct point
{
    int x,y;
    point(int x,int y):x(x),y(y){}
    point(){}
    bool operator < (const point &rhs) const
    {
        return y<rhs.y;
    }
};
vector<point>v[maxn];
int n;
int cnt=0,tot=0;
void print()
{
    //printf("%d:\n",++tot);
    for (int i=1;i<=n;i++)
    {
        //for (int j=1;j<=n;j++) printf("%3d",id[i][j]);
        //printf("\n\n");
        for (int j=1;j<=n;j++) printf("%c",mp[i][j]);
        printf("\n");
    }
}
void deal(point st,point ed,point dot,int sz)
{
    if (sz==1) return;
    point judge=point((st.x+ed.x)/2,(st.y+ed.y)/2);
    if (dot.x<=judge.x && dot.y<=judge.y) // left & up
    {
        id[judge.x+1][judge.y]=id[judge.x][judge.y+1]=id[judge.x+1][judge.y+1]=++cnt;
        type[judge.x+1][judge.y]=type[judge.x][judge.y+1]=type[judge.x+1][judge.y+1]=1;
        v[judge.x].pb(point(judge.x+1,judge.y+1));
        //v[judge.x+1].pb(judge.y+1);
        //print();
        deal(st,point(ed.x-sz/2,ed.y-sz/2),dot,sz/2);
        deal(point(st.x,st.y+sz/2),point(ed.x-sz/2,ed.y),point(judge.x,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y+sz/2),ed,point(judge.x+1,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y),point(ed.x,ed.y-sz/2),point(judge.x+1,judge.y),sz/2);
    }
    else if (dot.x>judge.x && dot.y<=judge.y) // left & down
    {
        id[judge.x][judge.y+1]=id[judge.x][judge.y]=id[judge.x+1][judge.y+1]=++cnt;
        type[judge.x][judge.y+1]=type[judge.x][judge.y]=type[judge.x+1][judge.y+1]=2;
        v[judge.x].pb(point(judge.x,judge.y+1));
        //v[judge.x].pb(judge.y+1);
        //print();
        deal(st,point(ed.x-sz/2,ed.y-sz/2),point(judge.x,judge.y),sz/2);
        deal(point(st.x,st.y+sz/2),point(ed.x-sz/2,ed.y),point(judge.x,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y+sz/2),ed,point(judge.x+1,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y),point(ed.x,ed.y-sz/2),dot,sz/2);
    }
    else if (dot.x<=judge.x && dot.y>judge.y) // right & up
    {
        id[judge.x+1][judge.y]=id[judge.x][judge.y]=id[judge.x+1][judge.y+1]=++cnt;
        type[judge.x+1][judge.y]=type[judge.x][judge.y]=type[judge.x+1][judge.y+1]=3;
        v[judge.x].pb(point(judge.x+1,judge.y));
        //v[judge.x+1].pb(judge.y);
        //print();
        deal(st,point(ed.x-sz/2,ed.y-sz/2),point(judge.x,judge.y),sz/2);
        deal(point(st.x,st.y+sz/2),point(ed.x-sz/2,ed.y),dot,sz/2);
        deal(point(st.x+sz/2,st.y+sz/2),ed,point(judge.x+1,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y),point(ed.x,ed.y-sz/2),point(judge.x+1,judge.y),sz/2);
    }
    else if (dot.x>judge.x && dot.y>judge.y) // right & down
    {
        id[judge.x][judge.y]=id[judge.x+1][judge.y]=id[judge.x][judge.y+1]=++cnt;
        type[judge.x][judge.y]=type[judge.x+1][judge.y]=type[judge.x][judge.y+1]=4;
        v[judge.x].pb(point(judge.x,judge.y));
        //v[judge.x].pb(judge.y);
        //print();
        deal(st,point(ed.x-sz/2,ed.y-sz/2),point(judge.x,judge.y),sz/2);
        deal(point(st.x,st.y+sz/2),point(ed.x-sz/2,ed.y),point(judge.x,judge.y+1),sz/2);
        deal(point(st.x+sz/2,st.y+sz/2),ed,dot,sz/2);
        deal(point(st.x+sz/2,st.y),point(ed.x,ed.y-sz/2),point(judge.x+1,judge.y),sz/2);
    }
}


void setcolor(point p,int type,int color)
{
    char tmp=color+'A';
    if (type==1) mp[p.x][p.y]=mp[p.x-1][p.y]=mp[p.x][p.y-1]=tmp;
    else if (type==2) mp[p.x][p.y]=mp[p.x+1][p.y]=mp[p.x][p.y-1]=tmp;
    else if (type==3) mp[p.x][p.y]=mp[p.x-1][p.y]=mp[p.x][p.y+1]=tmp;
    else if (type==4) mp[p.x][p.y]=mp[p.x+1][p.y]=mp[p.x][p.y+1]=tmp;
}

void paint()
{
    //for (int i=1;i<=n;i++)
        //for (int j=1;j<=n;j++)
            //mp[i][j]='X';
    for (int i=1;i<=n;i++)
    {
        int color=0;
        point now;
        sort(v[i].begin(),v[i].end());
        if (i&1)
        {
            color=((i+1)/2)%2;
            for (int j=0;j<v[i].size();j++)
            {
                now=v[i][j];
                color=(color+1)%2;
                setcolor(now,type[now.x][now.y],color);
                //print();
            }
        }
        else
        {
            color=2;
            for (int j=0;j<v[i].size();j++)
            {
                now=v[i][j];
                setcolor(now,type[now.x][now.y],color);
                //print();
            }
        }
    }


}

int main()
{
    int x,y;scanf("%d%d%d",&n,&x,&y);
    mp[x][y]='.';id[x][y]=-1;
    deal(point(1,1),point(n,n),point(x,y),n);
    paint();
    print();
    return 0;
}






