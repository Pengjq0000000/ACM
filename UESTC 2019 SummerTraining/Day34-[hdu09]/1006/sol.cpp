#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 1e18
using namespace std;
int n,m;
int w[105];
ll dp[105][12][7][4];
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%lld",&w[i]);
        ll sum,left;
        memset(dp[0],0,sizeof dp[0]);
        for(int p=1;p<=n;p++)
        {
            memset(dp[p],63,sizeof dp[p]);
            for(int i=0;i<=11;i++)
            {
                for(int j=0;j<=6;j++)
                {
                    for(int k=0;k<=3;k++)
                    {
                        sum=i*10+j*20+k*50;
                        left=w[p]-sum;
                        if(left>=0&&left%100==0) dp[p][i][j][k]=min(dp[p][i][j][k],left/100);
                        if(i) dp[p][i][j][k]=min(dp[p][i][j][k],dp[p][i-1][j][k]);
                        if(j) dp[p][i][j][k]=min(dp[p][i][j][k],dp[p][i][j-1][k]);
                        if(k) dp[p][i][j][k]=min(dp[p][i][j][k],dp[p][i][j][k-1]);
                        dp[0][i][j][k]=max(dp[p][i][j][k],dp[0][i][j][k]);
                    }
                }
            }    
        }
        ll ans=inf;
        for(int i=0;i<=11;i++)
            for(int j=0;j<=6;j++)
                for(int k=0;k<=3;k++)
                    ans=min(ans,dp[0][i][j][k]+i+j+k);
        if(ans>1e9) printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
