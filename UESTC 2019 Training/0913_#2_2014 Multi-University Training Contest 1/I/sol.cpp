#include<bits/stdc++.h>
#define mod 1000000009
#define MOD(x) ((x)%mod)
#define pii pair<ll,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
using namespace std;
int n,m;
int a,b,c,d;
ll fac[100005],inv[100005];
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
	for(int i=1;i<=100002;i++)
		fac[i]=MOD(fac[i-1]*i);
	inv[100002]=ksm(fac[100002],mod-2);
	for(int i=100002;i>=1;i--)
		inv[i-1]=MOD(inv[i]*i);
}
ll C(int n,int m)
{
	if(n<m) return 0;
	return MOD(fac[n]*MOD(inv[m]*inv[n-m]));
}
int main()
{
    ini();
    while(scanf("%d%d",&n,&m)!=EOF)
    {
        a=m,b=0,c=m,d=0;
        for(int i=1;i<=n;i++)
        {
            int t,x=m,y=0;
            scanf("%d",&t);
            x=min(x,abs(a-t)); y=max(y,abs(a-t));
            x=min(x,m-abs(b-t)); y=max(y,m-abs(b-t));
            x=min(x,abs(c-t)); y=max(y,abs(c-t));
            x=min(x,m-abs(d-t)); y=max(y,m-abs(d-t));
            if(a<=t&&t<=c) x=(a+t)%2;
            if(d<=t&&t<=b) y=m-(b+t)%2;
            a=x,b=m-a,c=y,d=m-c;
        }
        //printf("a=%d b=%d c=%d d=%d\n",a,b,c,d);
    	ll ans=0;
    	//printf("%d %d\n",a,c);
		for(int i=a;i<=c;i+=2)
    		ans=MOD(ans+C(m,i));
    	printf("%lld\n",ans);
    }
    return 0;
}