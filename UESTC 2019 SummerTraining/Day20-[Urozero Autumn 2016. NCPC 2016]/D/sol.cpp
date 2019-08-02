#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
long long dp[2][100005];
long long p[400];
int now,last;
int main()
{
	scanf("%d",&n);
	dp[now][0]=100;
	for(int i=1;i<=100000;i++)
		dp[now][i]=-1e16;
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&p[i]);
		last=now;
		now=!last;
		for(int j=0;j<=100000;j++)
			dp[now][j]=dp[last][j];
		for(long long j=0;j<=100000;j++)
		{
			dp[now][0]=max(dp[now][0],dp[last][j]+p[i]*j);
			if(dp[last][j]<0) continue;
			long long k=j+dp[last][j]/p[i];
			if(k<100000)
				dp[now][k]=max(dp[now][k],dp[last][j]-p[i]*(k-j));
			else
				dp[now][100000]=max(dp[now][100000],dp[last][j]-p[i]*(100000-j));
		}
	}
	long long ans=100;
	for(int i=0;i<=100000;i++)
		ans=max(ans,dp[now][i]);
	printf("%lld",ans);
	return 0;
}


