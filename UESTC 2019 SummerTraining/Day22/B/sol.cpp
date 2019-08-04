#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
long long x;
long long mi[32];
long long a[50005];
long long b[50005];
long long c[50005];
long long r[50005];
int cnt;
long long fac[20];
long long e[50005][20];
bool d[80000];
bool vis[80000];
long long dp[80000];
bool noprime[2000005];
long long prime[2000005];
int p;
void euler()
{
	long long n=2000003;
	noprime[0]=noprime[1]=1;
	for(long long i=2;i<n;i++){
	    if(!noprime[i])prime[++p]=i;
	    for(long long j=1;j<=p,i*prime[j]<n;j++){
	        noprime[i*prime[j]]=1;
	        if(!(i%prime[j]))break;
	    }
	}
}
int num;
long long res[50005];
map<long long,bool>occ;
void deal()
{
	cnt=0;
	long long y=x;
	for(int i=1;i<=p;i++)
	{
		long long t=prime[i];
		if(y%t==0)
		{
			fac[++cnt]=t; e[0][cnt]=0;
			while(y%t==0) e[0][cnt]++,y/=t;
		}
	}
	occ.clear(); num=0;
	for(int i=1;i<=m;i++)
	{
		r[i]=b[i];
		for(int j=1;j<=cnt;j++)
			while(r[i]%fac[j]==0) r[i]/=fac[j];
		if(r[i]==1) continue;
		if(occ[r[i]]==0) occ[r[i]]=1,res[++num]=r[i];
	}
	if(y>1)
	{
		long long z=sqrt(y);
		if(z*z==y) fac[++cnt]=z,e[0][cnt]=2;
		else
		{
			sort(res+1,res+1+num);
			if(num==0) fac[++cnt]=y,e[0][cnt]=1;
			else if(num==1&&y==res[1]) fac[++cnt]=res[1],e[0][cnt]=1;
			else
			{
				fac[++cnt]=res[1],e[0][cnt]=1;
				fac[++cnt]=y/res[1],e[0][cnt]=1;
			}
		}		
	}
	for(int i=1;i<=m;i++)
	{
		r[i]=b[i];
		for(int j=1;j<=cnt;j++)
		{
			e[i][j]=0;
			while(r[i]%fac[j]==0) r[i]/=fac[j],e[i][j]++;
		}
	}
	return;
}
void gao(long long x)
{
	vis[x]=1;
	for(int i=0;i<cnt;i++)
	{
		if((x&mi[i])==0) continue;
		int y=x^mi[i];
		if(!d[y]) continue;
		if(vis[y]) continue;
		gao(y);
	}
}
void ini()
{
	
}
int main()
{
	mi[0]=1;
	for(int i=1;i<=20;i++)
		mi[i]=mi[i-1]*2;
	euler();
	int T;
	scanf("%d",&T);
	for(int cas=1;cas<=T;cas++)
	{
		ini();
		scanf("%d%lld",&n,&x);
		m=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%lld",&a[i]);
			if(x%a[i]==0) b[++m]=a[i];
		}
		if(x==1ll)
		{
			int sign=-1;
			for(int i=1;i<=m;i++)
				if(b[i]==1ll) sign=1;
			printf("Case %d: %d\n",cas,sign);
			continue;
		}
		deal();
		for(int j=1;j<=m;j++) c[j]=0;
		for(int j=0;j<mi[cnt];j++)
		{
			d[j]=vis[j]=0;
			dp[j]=30;
		}
		dp[0]=0;
		for(int i=1;i<=m;i++)
			for(int j=1;j<=cnt;j++)
				if(e[i][j]==e[0][j])
					c[i]|=mi[j-1];
		for(int i=1;i<=m;i++)
			d[c[i]]=1;
		for(int i=mi[cnt]-1;i>=1;i--)
		{
			if(!d[i]) continue;
			if(vis[i]) continue;
			gao(i);
			for(int j=0;j<mi[cnt];j++)
				dp[j|i]=min(dp[j|i],dp[j]+1);
		}
		long long ans;
		if(dp[mi[cnt]-1]>20) ans=-1;
		else ans=dp[mi[cnt]-1];
		printf("Case %d: %lld\n",cas,ans);
	}
	return 0;
}

