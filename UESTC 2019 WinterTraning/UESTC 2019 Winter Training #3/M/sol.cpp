#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

int main()
{
    double n,m,k;
    scanf("%lf%lf%lf",&n,&m,&k);
    double tmp=min(m,(k-1));
    double ans=1.0/k*(tmp+(m-tmp)/(m-tmp+n));
    printf("%.9lf\n",ans);
    return 0;
}
