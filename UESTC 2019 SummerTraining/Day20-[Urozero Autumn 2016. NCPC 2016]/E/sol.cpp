#include<bits/stdc++.h>
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long 
using namespace std;
ll n,m;
ll euler_phi(ll n) {
    ll k = (ll)sqrt(n + 0.5);
    ll ans = n;
    for(ll i = 2; i <= k; i++) {
        if(n % i == 0) {
            ans = ans / i * (i - 1);
            while(n % i == 0)   n /= i;
        }
    }
    if(n > 1)   ans = ans / n * (n - 1);
    return ans;
}

ll ksm(ll x,ll a,ll mod)
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
ll ex[20];
bool check(ll x,ll phi)//if ex>phi
{
	if(x>=5) return 1;
	if(ex[x]>phi) return 1;
	else return 0;
}
ll fac(ll x)
{
	for(ll i=x-1;i>=1;i--) x*=i;
	return x;
}
ll calc(ll n,ll m)
{
	if(m==1) return 0;
	ll phi=euler_phi(m);
	if(check(n-1,phi)) return ksm(n,calc(n-1,phi)+phi,m);
	return ksm(n,ex[n-1],m);
}
int main()
{
	ex[1]=1;
	ex[2]=2;
	ex[3]=9;
	ex[4]=262144;
	scanf("%lld%lld",&n,&m);
	printf("%lld",calc(n,m));
	return 0;
}


