#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n;
long long k;
long long w[20];
long long m[205][205];
long long s[205][205];
long long a,b,c,d;
int vis[20];
void ini()
{
	memset(w,0,sizeof w);
	memset(vis,0,sizeof vis);

}
long long count(long long x,long long y)
{
	if(x==0||y==0) return 0;
	long long cnt=0;
	cnt+=(x/k)*(y/k)*s[k][k];
	cnt+=(y/k)*s[x-x/k*k][k];
	cnt+=(x/k)*s[k][y-y/k*k];
	cnt+=s[x-x/k*k][y-y/k*k];
	return cnt;
}
int main()
{

	int T;
	scanf("%d",&T);
	while(T--)
	{
		ini();
		scanf("%d",&n);
		for(int i=1;i<=n;i++)
			scanf("%lld",&w[i]);
		int cursor=1;
		bool sign=0;
		for (int i=1;i<=203;++i)
		{
			if(sign==0&&cursor==1&&vis[i%n]==1) sign=1,k=i-1;
			if(cursor==1) vis[i%n]++;
			for (int j=1;j<i;++j)
			{ 
				m[j][i-j]=w[cursor];
				s[j][i-j]=s[j-1][i-j]+s[j][i-j-1]-s[j-1][i-j-1]+m[j][i-j];
				cursor=cursor%n+1;
			}
		}
		int q;
		scanf("%d",&q);
		for(int i=1;i<=q;i++)
		{
			//scanf("%lld%lld",&xx,&yy);
			//printf("%lld\n",count(xx,yy));
			scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
			a++; b++; c++; d++;
			printf("%lld\n",count(c,d)-count(a-1,d)-count(c,b-1)+count(a-1,b-1));
		}
	}
	return 0;
}
