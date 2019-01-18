#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e5+7;

double wall[maxn],length[maxn];

int main()
{
    int n;double h;scanf("%d%lf",&n,&h);
    for (int i=1;i<=n;i++) scanf("%lf",&wall[i]);
    for (int i=1;i<=n;i++) scanf("%lf",&length[i]);
    
    int ans=0;
    
    for (int i=1;i<=n;i++)
    {
        double tmp=ceil(wall[i]-length[i]/4.0)-h;
        ans=max(ans,(int)tmp);
    }
    printf("%d\n",ans);
    return 0;
}
