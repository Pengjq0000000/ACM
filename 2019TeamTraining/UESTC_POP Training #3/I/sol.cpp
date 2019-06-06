#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long p,q,n,m,x,y,a[200];
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%lld%lld",&n,&m);
		memset(a,-1,sizeof a);
		for(int i=1;i<=m;++i)
		{
			scanf("%lld%lld",&x,&y);
			a[x]=y;
		}
		if(a[1]==-1) a[1]=100;
		if(a[2]==-1) a[2]=a[1];
		a[n+1]=0;
		for(int i=n;i>2;--i)
			if(a[i]==-1)
				a[i]=a[i+1];
		q=0;
		for(int i=n;i>0;--i)
			q+=a[i];
		p=a[2]+a[1];
		LL gcd = __gcd(p, q);
		p /= gcd; q /= gcd;
		printf("%lld/%lld\n", p, q);
	}
	return 0;
}
