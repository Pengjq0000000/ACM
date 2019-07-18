#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m,l;
long long dp[4200][3505];
int main()
{
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        l=2*(n+m);
        for(int i=0;i<=l+5;i++)
            for(int j=-n-5;j<=m+5;j++)
                dp[i][j+1100]=0;
        dp[0][1100]=1;
        for(int i=1;i<=l;i++)
        {
            for(int j=-n;j<=m;j++)
            {
                dp[i][j+1100+1]=MOD(dp[i][j+1100+1]+dp[i-1][j+1100]);
                dp[i][j+1100-1]=MOD(dp[i][j+1100-1]+dp[i-1][j+1100]);
            }
        }
        printf("%lld\n",dp[l][1100]);
    }
    return 0;
}
