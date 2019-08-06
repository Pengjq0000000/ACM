#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
long long a[1000005];
long long b[1000005];
long long c[1000005];
long long dp[1000005][5];
long long ans;
int main()
{
	freopen("g.in","r",stdin);
	scanf("%d",&n);
	dp[0][0]=-1e12;
	dp[0][1]=-1e12;
	dp[0][2]=-1e12;
	dp[0][3]=-1e12;
	dp[0][4]=0;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld%lld%lld",&a[i],&b[i],&c[i]);
		dp[i][0]=max(dp[i-1][0],dp[i-1][2])+c[i];
		dp[i][1]=max(dp[i-1][0],dp[i-1][2])+b[i];
		dp[i][2]=dp[i-1][4]+b[i];
		dp[i][3]=dp[i-1][4]+a[i];
		dp[i][4]=max(dp[i-1][1],dp[i-1][3]);
		ans=max(ans,dp[i][1]);
		ans=max(ans,dp[i][3]);
	}
	printf("%lld",ans);
	return 0;
}


