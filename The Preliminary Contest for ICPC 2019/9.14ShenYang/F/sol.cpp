#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
ll n,k;
ll a[500005];
ll b[500005];
ll sum,Left,num;
ll pos;
ll now;
ll c,d;
void out(int l,int r)
{
	for(int i=l;i<=r;i++)
		a[i]=now;
	ll t=k-c;
	ll m=r-l+1;
	ll rem=t%m;
	for(int i=l,cnt=1;i<=r;i++,cnt++)
	{
		a[i]-=t/m;
		if(cnt<=rem) a[i]--;
	}
}
void in(int l,int r)
{
	for(int i=l;i<=r;i++)
		a[i]=now;
	ll t=k-d;
	ll m=r-l+1;
	ll rem=t%m;
	for(int i=r,cnt=1;i>=l;i--,cnt++)
	{
		a[i]+=t/m;
		if(cnt<=rem) a[i]++;
	}
}
void ini()
{
	sum=0;
	num=0;
	pos=0;
	c=d=0;
}
int main()
{
	while(~scanf("%lld%lld",&n,&k))
	{
		ini();
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			sum+=a[i];
		}
		Left=sum%n;
		sort(a+1,a+1+n);
		for(int i=1;i<=n;i++)
		{
			b[i]=sum/n;
			if(n-i+1<=Left) b[i]++;
			num+=max(0ll,a[i]-b[i]);
			if(a[i]<b[i]) pos=i;
		}
		if(k>=num) printf("%lld\n",b[n]-b[1]);
		else
		{
			now=a[n];
			for(int i=n;i>pos;i--)
			{
				if(c+(a[i]-a[i-1])*(n-i+1)>=k) {out(i,n); break;};
				c+=(a[i]-a[i-1])*(n-i+1);
				now=a[i-1];
			}
			now=a[1];
			for(int i=1;i<=pos;i++)
			{
				if(d+(a[i+1]-a[i])*i>=k) {in(1,i); break;};
				d+=(a[i+1]-a[i])*i;
				now=a[i+1];
			}
			ll mina=a[1],maxa=a[1];
			for(int i=1;i<=n;i++)
				mina=min(mina,a[i]),
				maxa=max(maxa,a[i]);
			printf("%lld\n",maxa-mina);
		}	
	}
	return 0;
}


