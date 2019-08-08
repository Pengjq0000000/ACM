#include<bits/stdc++.h>
#define mod 998244353
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,T;
int a,b,c;
long long dp[100010];
int main()
{
    scanf("%d",&T);
    dp[1]=1;
    for(int i=1;i<=100005;i++)
    {
        dp[i+1]=MOD(dp[i]+dp[i+1]);
        dp[i+3]=MOD(dp[i]+dp[i+3]);
    }
    while(T--)
    {
        scanf("%d",&n);
        scanf("%d%d",&a,&b);
        c=b-a+1;
        if(a!=1&&a!=n) c--;
        if(b!=1&&b!=n) c--;
        printf("%lld\n",dp[c]);
    }
    return 0;
}
