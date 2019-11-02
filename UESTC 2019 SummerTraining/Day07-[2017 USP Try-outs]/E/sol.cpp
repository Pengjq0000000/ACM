#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n;
long long t[100006];
long long dp[100006];
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%lld",&t[i]);
    if(n==1)
    {
        printf("%lld",t[1]);
        return 0;
    }
    sort(t+1,t+1+n);
    memset(dp,124,sizeof dp);
    dp[n]=0;
    for(int i=n;i>=3;i--)
    {
        dp[i-1]=min(dp[i-1],dp[i]+t[1]+t[i]);
        dp[i-2]=min(dp[i-2],dp[i]+t[1]+t[2]*2+t[i]);
    }
    long long ans=dp[2]+t[2];
    printf("%lld",ans);
	return 0;
}
