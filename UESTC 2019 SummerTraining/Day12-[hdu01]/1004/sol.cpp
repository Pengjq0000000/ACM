#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
struct car
{
    long long l,s,v;
}c[100005];
long long sum[100005];
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        for(int i=0;i<=n;i++)
            scanf("%lld",&c[i].l);
        for(int i=0;i<=n;i++)
            scanf("%lld",&c[i].s);
        for(int i=0;i<=n;i++)
            scanf("%lld",&c[i].v);
        sum[0]=0;
        for(int i=1;i<=n;i++)
            sum[i]=sum[i-1]+c[i].l;
        double ans=(double)c[0].s/c[0].v;
        for(int i=1;i<=n;i++)
            ans=max(ans,(double)(c[i].s+sum[i])/c[i].v);
        printf("%.8lf\n",ans);
    }
    return 0;
}

