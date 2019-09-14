#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
ll inv[1000005];
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
	inv[0]=1;
	for(int i=1;i<=1000002;i++)
		inv[i]=ksm(i,mod-2);
}
ll cal(int n,int k)
{
	ll sum=0;
	for(int i=k+1;i<=n;i++)
		sum=MOD(sum+inv[i]);
	return sum;
}
int main()
{
	int T;
	scanf("%d",&T);
	ini();
	while(T--)
	{
		scanf("%d%d",&n,&m);
		if(m>=n) printf("1\n");
		else printf("%lld\n",MOD(1+mod-cal(n,m)));
		//else printf("%lld\n",MOD(cal(n,m)));
	}
	return 0;
}


