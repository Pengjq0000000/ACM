#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define si(x) scanf("%d",&(x))
#define sll(x) scanf("%lld",&(x))
const int maxn=3;
const int MAXN=7368793; 
ll p;

int prim[MAXN],np[MAXN],pn;

void getp(){
	np[1]=1;
	for (int i=2;i<MAXN;i++){
		if (!np[i]){
			prim[pn++]=i;	
		}
		for (int j=0;j<pn&&i*prim[j]<MAXN;j++){
			np[i*prim[j]]=1;
			if (i%prim[j]==0){
				break;	
			}
		}
	}
}

struct matrix{
	ll a[maxn][maxn];
	int n;
	matrix(int nn){
		memset(a,0,sizeof(a));
		n=nn;
	}
	matrix& operator =(const matrix& rhs){
		n=rhs.n;
		for (int i=0;i<=n;i++){
			for (int j=0;j<=n;j++){
				a[i][j]=rhs.a[i][j];
			}
		}
		return *this;
	}
	}
};

matrix mul(matrix& a,matrix& b){
	int n=a.n;
	matrix c(n);
	memset(c.a,0,sizeof c.a);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=n;j++){
			for (int k=1;k<=n;k++){
				c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j]%p)%p;
			}
		}
	}
	return c;
}

	
matrix qpow(matrix a,ll b){
	matrix res(a.n),temp=a;
	memset(res.a,0,sizeof res.a);
	for (int i=1;i<=res.n;i++){
		res.a[i][i]=1;
	}
	
	while (b>0){
		if (b&1) res=mul(res,temp);
		temp=mul(temp,temp);
		b>>=1;
	}
	return res;
}

ll exgcd(ll a,ll b,ll& x,ll& y){
	if (b==0){
		x=1;	y=0;
		return a;
	}
	ll g=exgcd(b,a%b,y,x);
	y-=a/b*x;
	return g;
}

ll inverse(ll a,ll p)
{
	ll inv,k,g;
	g=exgcd(a,p,inv,k);
	inv=(inv%p+p)%p;
	return inv;
}
ll ksm(ll a, ll b)
int main()
{
	getp();
	ll n;
	ll m;
	
	while (scanf("")){
		p=m;
		ll inv=inverse(3,p),ans;
		if (n==1){
			ans=2*inv%p;
		}else if (n==2){
			ans=3*inv%p;
		}else{
			n=prim[n-1];
			matrix e(2),l(2),r(2);
			memset(r.a,0,sizeof r.a);
			e.a[1][1]=1;	e.a[1][2]=1;
			e.a[2][1]=1;	e.a[2][2]=0;
			
			r.a[1][1]=1;
			r.a[2][1]=1;
			e=qpow(e,n-2);
			l=mul(e,r);
			ans=l.a[1][1]*inv%p;			
		}
		ll tmp=ans,cnt=(ans==0);
		
        while (tmp>0){
			tmp/=10;
			cnt++;
		}
		for (int i=0;i<9-cnt;i++) printf("*");
		printf("%lld\n",ans);
		

	}
	
	
}
