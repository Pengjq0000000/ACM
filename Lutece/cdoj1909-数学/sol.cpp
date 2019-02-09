#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
LL n,k;

LL cal(LL t)
{
    LL low=k/(t+1)+1;
    LL up=k/t;
    if (low>n) return 0;
    up=min(up,n);
    LL res=((k%low)+(k%up))*(up-low+1)/2;
    return res;
}

int main()
{
    scanf("%lld%lld",&n,&k);
    LL ans=k*max((LL)0,n-k);
    n=min(n,k);
    for (LL t=1;t*t<=k;t++)
    {
        ans+=cal(t);
        if (t!=k/t) ans+=cal(k/t);
    }
    printf("%lld\n",ans);
    return 0;
}

