#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
map<LL,LL>cnt;
int main()
{
    LL A,B,C,D;scanf("%lld%lld%lld%lld",&A,&B,&C,&D);
    C=-C;D=-D;
    for (LL i=1;i<=1000;i++)
        for (LL j=1;j<=1000;j++)
        {
            LL tmp=A*i*i+B*j*j;
            cnt[tmp]+=4;
        }
    LL ans=0;
    for (LL i=1;i<=1000;i++)
        for (LL j=1;j<=1000;j++)
        {
            LL tmp=C*i*i+D*j*j;
            if (cnt.count(tmp)) ans+=cnt[tmp]*4;
        }
    printf("%lld\n",ans);
    return 0;
}

