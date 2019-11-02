#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
double d[maxn];

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,k;scanf("%d%d",&n,&k);
        for (int i=1;i<=n;i++) scanf("%lf",&d[i]);
        sort(d+1,d+1+n);
        double ans=0,sum=0,sqrsum=0;
        int num=n-k;
        if (num>0)
        {
            for (int i=1;i<=num;i++) sum+=d[i],sqrsum+=d[i]*d[i];
            ans=sqrsum-sum*sum/num;
            if (num>0) for (int i=num+1;i<=n;i++)
            {
                sum=sum-d[i-num]+d[i];
                sqrsum=sqrsum-d[i-num]*d[i-num]+d[i]*d[i];
                ans=min(ans,sqrsum-sum*sum/num);
            }
        }
        printf("%.9lf\n",ans);
    }    
    return 0;
}

