#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long t,a,n,cnt1,cnt2;
int main()
{
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n);
		cnt1=0;cnt2=0;
		for(int i=1;i<=n;++i){
			scanf("%lld",&a);
			if(a&1)++cnt1;
			cnt2+=a/2;
		}
		if(cnt1==0)
			printf("%lld\n",cnt2*2);
		else
			printf("%lld\n",cnt2/cnt1*2+1);
	}
	return 0;
}
