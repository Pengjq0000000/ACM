#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 407;
double dp[maxn][maxn];
int main()
{
    int n,k;scanf("%d%d",&n,&k);
    dp[0][0]=1;
    for (int i=0;i<k;i++)
    {
        for (int j=0;j<=n;j++) // now have j coins up
        {
            if (j<n)
            {
                dp[i+1][j]+=dp[i][j]*0.5;
                dp[i+1][j+1]+=dp[i][j]*0.5;
            }
            if (j==n) // all coins up
            {
                dp[i+1][n]+=dp[i][j]*0.5;
                dp[i+1][n-1]+=dp[i][j]*0.5;
            }
        }
    }
    double ans=0;
    for (int i=1;i<=n;i++) ans+=dp[k][i]*(double)i;
    printf("%lf",ans);
    return 0;
}
