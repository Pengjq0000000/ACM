#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
ll p[30005];
int c[30005];
ll dp[30005];
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=1;i<=n;i++)
			scanf("%d%d",&p[i],&c[i]);
		for(int i=1;i<=3*m+2;i++) dp[i]=inf;
		dp[0]=0;
		for(int j=1;j<=n;j++)
			for(int i=c[j];i<=3*m+2;i++)
				if(i-c[j]>=0) dp[i]=min(dp[i],dp[i-c[j]]+p[j]);
		ll cost=inf;
		int w=0;
		for(int i=m;i<=3*m;i++)
			if(dp[i]<=cost) cost=dp[i],w=i;
		for(int i=1;i<=n;i++)
			if(c[i]>=m)
			{
				if(p[i]<cost) cost=p[i],w=c[i];
				else if(p[i]==cost) w=max(w,c[i]);
			}
		printf("%lld %d\n",cost,w);
	}
	return 0;
}


