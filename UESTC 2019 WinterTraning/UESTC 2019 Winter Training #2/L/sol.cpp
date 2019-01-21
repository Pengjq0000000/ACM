#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define eps 1e-8

using namespace std;

const int maxn = 1e6+7;
struct P
{
    double k,dis;
    int h,dir;
    bool operator < (const P &rhs) const
    {
        if (dir==rhs.dir && k==rhs.k) return dis<rhs.dis;
        if (dir==rhs.dir) return k<rhs.k;
        return dir<rhs.dir;
    }
}point[maxn];
double ox,oy;
double getdis(double x,double y)
{
    return sqrt((x-ox)*(x-ox)+(y-oy)*(y-oy));
}
double getk(double x,double y)
{
    if (y==oy) return 0;
    if (x==ox) return 1e8;
    return (oy-y)/(ox-x);
}
int dp[maxn],a[maxn];
int getlis(int n)
{
    for (int i=1;i<=n;i++) dp[i]=1e9;
    dp[1]=a[1];
    int len=1;
    for(int i=2;i<=n;i++)
    {
        if(a[i]>dp[len]) dp[++len]=a[i];
        else
        {
            int pos=lower_bound(dp+1,dp+len+1,a[i])-dp;
            dp[pos]=a[i];
        }
    }
    return len;
}

int main()
{
    scanf("%lf%lf",&ox,&oy);
    int n,tot=0;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        double xx,yy;
        scanf("%lf%lf%d",&xx,&yy,&point[i].h);
        point[i].dis=getdis(xx,yy);
        point[i].k=getk(xx,yy);
        if (ox!=xx)
        {
            point[i].dir=(ox<xx?1:-1);
        }
        else 
        {
            point[i].dir=(oy<yy?1:-1);
        }
    }
    sort(point+1,point+1+n);
    //for (int i=1;i<=n;i++) 
        //printf("%d %lf %lf %d\n",point[i].dir,point[i].k,point[i].dis,point[i].h);

    int cnt=0,ans=0;
    a[++cnt]=point[1].h;
    for (int i=2;i<=n;i++)
    {
        if (point[i].dir==point[i-1].dir && point[i].k==point[i-1].k)
        {
            a[++cnt]=point[i].h;
        }
        else
        {
            ans+=getlis(cnt);
            cnt=0;
            a[++cnt]=point[i].h;
        }
    }
    ans+=getlis(cnt);
    printf("%d\n",ans);
    return 0;
}



