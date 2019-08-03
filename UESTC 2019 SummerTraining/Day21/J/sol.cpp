#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
long long c[1005][1005];
long long dp1[1005][1005];
long long dp2[1005][1005];
long long d[1005];
long long sum1[1005][1005];
long long sum2[1005];
int main()
{
    int T;
    scanf("%d",&T);
    for(int cas=1;cas<=T;cas++)
    {
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;i++)
            for(int j=1;j<=m;j++)
            {
                scanf("%lld",&c[i][j]);
                c[i][j]*=-1;
                sum1[i][j]=c[i][j]+sum1[i-1][j]+sum1[i][j-1]-sum1[i-1][j-1];
            }
        for(int j=1;j<=m;j++)
            scanf("%lld",&d[j]),sum2[j]=sum2[j-1]+d[j];
        for(int i=1;i<=n;i++) dp1[i][m+1]=0,dp2[i][m+1]=0;
        for(int i=1;i<=n;i++)
            for(int j=m;j>=1;j--)
                dp1[i][j]=max(c[i][j],c[i][j]+dp1[i][j+1]),
                dp2[i][j]=max(0ll,dp1[i][j]);
        long long ans=0;
        for(int j=0;j<=m;j++)
        {
            long long tmp=sum1[n][j]+sum2[j];
            long long minn=1e15;
            for(int i=1;i<=n;i++)
                tmp+=dp2[i][j+1],minn=min(minn,dp2[i][j+1]);
            ans=max(ans,tmp-minn);
        }
        printf("Case #%d: %lld\n",cas,ans);
    }
    return 0;
}
