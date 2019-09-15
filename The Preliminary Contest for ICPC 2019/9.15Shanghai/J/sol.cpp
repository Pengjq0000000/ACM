#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[305];
ll dp[150002];
ll ans;
int s,sum;
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		sum=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			sum+=a[i];
		}
		for(int i=0;i<=sum;i++)
			dp[i]=0;
		dp[0]=1;
		sort(a+1,a+1+n);
		ans=0,s=0;
		for(int i=n;i>=1;i--)
		{
			for(int j=s;j>=0;j--)
			{
				dp[j+a[i]]=MOD(dp[j+a[i]]+dp[j]);
				if(j<=sum-(j+a[i])&&sum-(j+a[i])<=j+a[i]) ans=MOD(ans+dp[j]);
			}
			s+=a[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}


