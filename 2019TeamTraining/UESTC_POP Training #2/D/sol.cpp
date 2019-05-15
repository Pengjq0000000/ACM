#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL n,m;
long long b[100005];
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%lld%lld",&n,&m);
		for(int i=1;i<=n;i++)
		{
			LL a;
			scanf("%lld%lld",&a,&b[i]);
			b[i]++;
		}
		sort(b+1,b+1+n);
		long long t=1;
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			if(t*b[i]>m)break;
			ans++;
			t*=b[i];
		}
		printf("%lld\n",ans);
	}
	return 0;
}
