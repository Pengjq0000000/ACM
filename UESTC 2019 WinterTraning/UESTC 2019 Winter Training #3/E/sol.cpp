#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
struct Point
{
    int x,y;
    Point(int x,int y):x(x),y(y){}
    Point(){}
};

int check(Point a,Point b)
{
    int dx=abs(a.x-b.x),dy=abs(a.y-b.y);
    if (dx==0) return dy>1;
    if (dy==0) return dx>1;
    return __gcd(dx,dy)>1;
}

vector<Point>p;
int main()
{
    int n;scanf("%d",&n);
    n++;
    for (int i=1;i<=n;i++)
        for (int j=i;j<=n;j++)
            p.pb(Point(i,j));
            
    int sz=p.size(),ans=0;
    for (int i=0;i<sz-1;i++)
        for (int j=i+1;j<sz;j++) 
            ans+=check(p[i],p[j]);
    printf("%d\n",ans);
    return 0;
}
