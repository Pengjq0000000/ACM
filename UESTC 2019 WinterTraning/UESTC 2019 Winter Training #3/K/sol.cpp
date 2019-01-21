#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 5e5+7;
double a[maxn];

int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        double x,p;scanf("%lf%lf",&x,&p);
        a[i]=x*p;
    }
    sort(a+1,a+1+n);
    double ans=0,tmp=0;
    for (int i=1;i<=n;i++)
    {
        tmp+=a[i];
        ans+=tmp;
    }
    printf("%.9lf",ans/n);
    return 0;
}
