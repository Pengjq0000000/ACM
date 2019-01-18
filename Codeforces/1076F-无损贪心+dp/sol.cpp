#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define pb push_back

using namespace std;
const int maxn = 3e5+7;

LL x[maxn],y[maxn],k,dp[maxn][2];

LL cal(LL preT,LL preF,LL T,LL F)
{
    LL res=1e18,cnt;
    if (preT<=k)
    {
        cnt=(preT+T-1)/k;
        if (F==cnt) res=min(res,preT+T-cnt*k);
        else if (F>cnt && F<=T*k) res=1;
    }
    if (preF<=k)
    {
        cnt=(T-1)/k;
        if (F==cnt) res=min(res,T-cnt*k);
        else if (F>cnt && F+preF<=T*k) res=1;
    }   
    return res;
}

int main()
{
    int n;scanf("%d%lld",&n,&k);
    for (int i=1;i<=n;i++) scanf("%lld",&x[i]);
    for (int i=1;i<=n;i++) scanf("%lld",&y[i]);
    for (int i=1;i<=n;i++)
    {
        dp[i][0]=cal(dp[i-1][0],dp[i-1][1],x[i],y[i]); // end with T
        dp[i][1]=cal(dp[i-1][1],dp[i-1][0],y[i],x[i]); // end with F
        //printf("T:%lld F:%lld\n",dp[i][0],dp[i][1]);
        if (dp[i][0]>k && dp[i][1]>k)
        {
            return puts("NO"),0;
        }
    }
    puts("YES");
    return 0;
}
