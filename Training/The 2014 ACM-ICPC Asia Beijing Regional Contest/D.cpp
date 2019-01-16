#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int n,m;
int a[300];
int b[300];
int dp[300][300];
int main()
{
    int t;
    int Case=0;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        a[n+1]=0;
        b[n+1]=0;
        memset(dp,63,sizeof(dp));
        for(int i=1;i<=n;i++)
            for(int j=0;j<i;j++)
                dp[i][j]=0;
        memset(dp[n+1],0,sizeof(dp[n+1]));
        for(int len=1;len<=n;len++)
        {
            for(int i=1;i+len-1<=n;i++)
            {
                int j=i+len-1;
                for(int k=i;k<=j;k++)
                {
                    dp[i][j]=min(dp[i][j],dp[i][k-1]+dp[k+1][j]+a[k]+b[i-1]+b[j+1]);
                }
            }
        }
        printf("Case #%d: %d\n",++Case,dp[1][n]);
    }
    
    return 0;
}
