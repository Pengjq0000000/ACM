#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
using namespace std;
int n;
struct monster
{
	ll atk,hp;
	ll tim;
	bool friend operator < (monster a,monster b)
	{
		return a.tim*(a.atk+b.atk)+b.tim*b.atk<b.tim*(b.atk+a.atk)+a.tim*a.atk;
	}
}m[100005];
ll sum[100005];
ll cal(ll y)
{
	ll l=1,r=1000;
	ll res=1000;
	while(l<=r)
	{
		ll m=(l+r)/2;
		if(m*(m+1)/2>=y) res=m,r=m-1;
		else l=m+1;
	}
	return res;
}
int main()
{
	int T;
	scanf("%d",&T);
	int cas=0;
	while(T--)
	{
		cas++;
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
		{
			scanf("%lld%lld",&m[i].hp,&m[i].atk);
			m[i].tim=cal(m[i].hp);
		}
		sort(m+1,m+1+n);
		sum[n+1]=0;
		for(int i=n;i>=1;i--)
			sum[i]=sum[i+1]+m[i].atk;
		ll ans=0;
		for(int i=1;i<=n;i++)
			ans+=sum[i]*m[i].tim;
		printf("Case #%d: %lld\n",cas,ans);
	}
	return 0;
}


