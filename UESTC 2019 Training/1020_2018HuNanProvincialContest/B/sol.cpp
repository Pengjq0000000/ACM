#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
ll fac[10000];
ll inv[10000];
ll C(int n,int m)
{
	if(n<m) return 0;
	return MOD(MOD(fac[n]*inv[m])*inv[n-m]);
}
ll ksm(ll x,ll a)
{
	ll b=1;
	while(a)
	{
		if(a&1) b=MOD(b*x);
		x=MOD(x*x);
		a>>=1;
	}
	return b;
}
void ini()
{
	fac[0]=1;
	for(int i=1;i<=9000;i++)
		fac[i]=MOD(fac[i-1]*i);
	inv[9000]=ksm(fac[9000],mod-2);
	for(int i=9000;i>=1;i--)
		inv[i-1]=MOD(inv[i]*i);
}
ll cal(int n,int m)
{
	ll ans=MOD(C(n+m,n)+mod-1ll);
	ans=MOD(ans*ans);
	return ans;
}
int main()
{
	ini();
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		printf("%lld\n",cal(n,m));
	}
	return 0;
}