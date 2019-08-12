#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
long long n;
long long h[250005];
long long w[250005];
long long q[250005];
long long dp[250005];
long long head,tail;
long long sumhw;
long long sumh;
long long ans;
long long maxw;
struct block
{
	long long h,w;
	bool friend operator < (block a,block b)
	{
		return a.h>b.h;
	}
}b[250005];
long long get(long long i,long long j)
{
	return h[i]*sumh-sumhw-h[j]*(h[i]-w[j])-h[i]*(h[i]-w[i]);
}
long long f(long long x)
{
	return h[x]*w[x];
}
long long g(long long x)
{
	return h[x];
}
int main()
{
	scanf("%lld",&n);
	for(long long i=1;i<=n;i++)
	{
		scanf("%lld%lld",&b[i].h,&b[i].w);
		if(b[i].h<b[i].w) swap(b[i].h,b[i].w);
		sumh+=b[i].h;
		sumhw+=b[i].h*b[i].w;
		maxw=max(maxw,b[i].w);
	}
	sort(b+1,b+1+n);
	for(int i=1;i<=n;i++)
		h[i]=b[i].h,w[i]=b[i].w;
	head=1;
	q[++tail]=1;
	for(long long i=2;i<=n;i++)
	{
		//if(h[i]<maxw) break;
		while(head<tail&&f(q[head+1])-f(q[head])>=h[i]*(g(q[head+1])-g(q[head])))
			head++;
		dp[i]=get(i,q[head]);
		//printf("%lld\n",dp[i]);
		while(head<tail&&(f(q[tail])-f(q[tail-1]))*(g(i)-g(q[tail]))>=(f(i)-f(q[tail]))*(g(q[tail])-g(q[tail-1])))tail--;
		q[++tail]=i;
		ans=max(ans,dp[i]);
	}
//	for(int i=1;i<=n;i++)
//	printf("%lld ",dp[i]);
	printf("%lld",ans); 
	return 0;
}
