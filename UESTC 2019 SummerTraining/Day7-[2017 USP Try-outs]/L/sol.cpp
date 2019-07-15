#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n,m,k;
char a[1000001];
char b[101];
int dp[101][1000001];
bool ff;
int main()
{
	scanf("%d%d%d",&m,&n,&k);
    scanf(" %s",b+1);
    scanf(" %s",a+1);
    memset(dp,63,sizeof dp);
    for(int i=0;i<=n;i++) dp[0][i]=0;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(a[i]==b[j]) dp[j][i]=min(dp[j][i],dp[j-1][i-1]);
            dp[j][i]=min(dp[j][i],dp[j-1][i-1]+1);
            dp[j][i]=min(dp[j][i],dp[j][i-1]+1);
            dp[j][i]=min(dp[j][i],dp[j-1][i]+1);
            if(j==m&&dp[j][i]<=k)
            {
                ff=1;
                goto line1;
            }
        }
    }
    line1:
        if(ff) printf("S");
            else printf("N");
	return 0;
}