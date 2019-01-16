#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const double pi = acos(-1);

int main()
{
    int n;double d;
    while (scanf("%d%lf",&n,&d)!=EOF)
    {
        d=d*d;
        double ang,ans=0;
        for (int i=0;i<n;i++)
        {
            scanf("%lf",&ang);
            ans+=0.5*sin(ang/360*2*pi);
        }
        printf("%.3lf\n",ans);
    }
    return 0;
}
