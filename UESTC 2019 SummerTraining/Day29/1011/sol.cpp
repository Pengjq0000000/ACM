#include<bits/stdc++.h>
#define mod (long long)1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
#define int long long
using namespace std;
int n,q;
int s[500005];
int r[500005];
int x[500005];
int a[500005];
int dp[500005];
int sum[500005];
int ksm(int x,int a)
{
    int b=1;
    while(a)
    {
        if(a&1) b=MOD(b*x);
        x=MOD(x*x);
        a>>=1;
    }
    return b;
}
int inv(int x)
{
    return ksm(x,mod-2);
}
signed main()
{
    int T;
    scanf("%lld",&T);
    while(T--)
    {
        scanf("%lld%lld",&n,&q);
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld%lld%lld",&r[i],&s[i],&x[i],&a[i]);
            dp[i]=MOD(MOD(r[i]*a[i]+(s[i]-r[i])*(sum[i-1]-sum[x[i]-1]+mod+a[i]))*inv(r[i]));
            sum[i]=MOD(sum[i-1]+dp[i]);
        }
        for(int i=1;i<=q;i++)
        {
            int a,b;
            scanf("%lld%lld",&a,&b);
            printf("%lld\n",MOD(sum[b-1]-sum[a-1]+mod));
        }
    }
    return 0;
}


