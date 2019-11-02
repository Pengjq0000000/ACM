#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e5+7;
struct Point
{
    double x,y;
    Point(double x,double y):x(x),y(y){}
    Point(){}
}p[maxn];
double getS(Point a,Point b,Point c)
{
    return 0.5*abs(a.x*b.y+b.x*c.y+c.x*a.y-(a.x*c.y+b.x*a.y+c.x*b.y));
}

double sum[maxn];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        double x,y;scanf("%lf%lf",&x,&y);
        p[i]=Point(x,y);
    }
    sum[0]=sum[1]=sum[2]=0;
    for (int i=3;i<=n;i++)
    {
        sum[i]=sum[i-1]+getS(p[1],p[i],p[i-1]);
    }
    double ans=0;
    while (m--)
    {
        int st,ed;scanf("%d%d",&st,&ed);
        if (st>ed) swap(st,ed);
        double tmpS;
        tmpS=sum[ed]-sum[st];
        if (st!=1) tmpS-=getS(p[1],p[st],p[ed]);
        ans=max(ans,min(tmpS,sum[n]-tmpS));
    }
    printf("%.9lf",ans);
    return 0;
}
