#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
long long n,k;
long long F[25][250];
long long f[250];
long long d[20];
void calc(long long n)
{
	for(int i=1;i<20;i++) d[i]=n%10,n/=10;
	for(int i=0;i<200;i++) f[i]=0;
	long long s=0; 
	for(int i=19;i>0;i--)
	{
		for(int x=0;x<d[i];x++)
			for(int j=0;x+j+s<200;j++)
				f[x+j+s]+=F[i-1][j];
		s+=d[i];
	}
}
long long getrank(long long n,long long k)
{
	long long s=0;
	long long m=k;
	long long rank=0;
	for(int i=1;i<20;i++)
		s+=m%10,m/=10;
	calc(n+1);
	for(int i=1;i<s;i++)
		rank+=f[i];
	calc(k+1);
	rank+=f[s];
	return rank;
}
int main()
{
	scanf("%lld%lld",&n,&k);
	F[0][0]=1;
	for(int i=1;i<=20;i++)
		for(int j=0;j<200;j++)
			for(int x=0;x<10;x++)
				F[i][j+x]+=F[i-1][j];
	long long ans1=getrank(n,k);
	long long cnt=0;
	long long s=0;
	calc(n+1);
	for(int i=1;i<200;i++)
	{
		if(cnt+f[i]>=k)
		{
			s=i;
			break;
		}
		cnt+=f[i];
	}
	long long ans2,l=1,r=n;
	while(l<r)
	{
		long long mid=(l+r)/2;
		calc(mid+1);
		if(cnt+f[s]<k) l=mid+1; 
		else r=mid;
	}
	ans2=l;
	printf("%lld %lld",ans1,ans2);
	return 0;
}
