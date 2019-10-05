#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define ll long long
using namespace std;
int n;
ll ans1;
ll ans2;
ll ans3;
ll tmp;
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
ll inv(ll x)
{
    return ksm(x,mod-2);
}
ll fac[105];
int main()
{
    freopen("harary.in", "r", stdin);
    freopen("harary.out", "w", stdout);
    scanf("%d",&n);
    fac[0]=1;
    for(int i=1;i<=n;i++)
        fac[i]=MOD(fac[i-1]*i);
    for(int i=1;i<n;i++)
        ans1=ans1+n-i-1;
    ans1=ksm(2,ans1); ans1=MOD(ans1*fac[n]);
    for(int i=1;i<n-1;i++)
        tmp=tmp+n-i-2;
    tmp=ksm(2,tmp); tmp=MOD(tmp*fac[n-1]);
    for(int i=0;i<=n-2;i++)
    {
        int j=n-2-i;
        int t=0;
        for(int k=1;k<=i;k++)
        {
            if(k==i) t+=n-2-k;
            else t+=n-1-k;
        }
        if(j>=1) t+=2*(j-1);
        for(int k=1;k<j;k++)
            t+=j-1-k;
        ans2=MOD(ans2+ksm(2,t));
    }
    ans2=MOD(ans2*fac[n]);
    
    ans2=MOD(ans2*inv(2));
    //printf("%lld\n",ans2);
    //tmp=MOD(tmp*(n-1));
    //tmp=MOD(tmp*n);
    //tmp=MOD(tmp*inv(2));
    //ans2=MOD(ans2-tmp+mod);
    for(int i=0;i<=n-3;i++)
    {
        int j=n-3-i;
        int t=0;
        for(int k=1;k<=i;k++)
        {
            if(k==i) t+=n-2-k;
            else t+=n-1-k;
        }
        if(j>=1) t+=3*j-2;
        for(int k=1;k<j;k++)
            t+=j-1-k;
        //cout<<t<<endl;
        ans3=MOD(ans3+ksm(2,t));
    }
    //printf("%lld\n",ans3);
    ans3=MOD(ans3*fac[n]);
    printf("%lld\n",ans1);
    printf("%lld\n",ans2);
    printf("%lld\n",ans3);
    return 0;
}