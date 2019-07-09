#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int T,n;
long long a[100010],sum,ans;
int main()
{
	scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        sum=0;
        for(int i=1;i<=n;++i)
        {
            scanf("%lld",&a[i]);
            sum+=a[i];
        }
        ans=sum%n;
        sum/=n;
        for(int i=1;i<=n;++i)
        {
            if(a[i]<sum)
                ans+=sum-a[i];
        }
        cout<<ans<<endl;
    }
	return 0;
}
