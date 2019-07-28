#include<bits/stdc++.h>
#define mod 998244353
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
int n,m;
LL fac[5007];
LL inv[5007];
long long mi[5007];
long long dp[5007];
long long ans[5007];
long long ave[5007];
LL ksm(LL a, LL b)
{
    LL res = 1, base = a;
    while (b)
    {
        if (b & 1) res = MOD(res * base);
        base = MOD(base * base);
        b /= 2;
    }
    return res;
}
inline long long C(int n,int m)
{
    if(n<m) return 0;
    return MOD(MOD(fac[n]*inv[m])*inv[n-m]);
}
void deal(int x)
{
    long long tmp=MOD(mi[x]*dp[x]);
    for(int i=0;i<x;i++)
        tmp=MOD(tmp+MOD(C(x,i)*ans[i]));
    ans[x]=MOD(tmp*ksm(mi[x]-1,mod-2));
    ave[x]=MOD(MOD(ave[x-1]*(x-1)+ans[x])*ksm(x,mod-2));
}
void cal()
{
    mi[0]=1;
    for(int i=1;i<=5005;i++)
        mi[i]=MOD(mi[i-1]*2);
    fac[0]=1;
    for(int i=1;i<=5005;i++)
        fac[i]=MOD(fac[i-1]*i);
    inv[5005]=ksm(fac[5005],mod-2);
    for(int i=5005;i>=1;i--)
        inv[i-1]=MOD(inv[i]*i);
    for(long long i=1;i<=5005;i++)
        dp[i]=MOD(MOD(dp[i-1]*i)+MOD(MOD(i*(i-1)/2)*fac[i-1]));
    for(int i=1;i<=5005;i++)
        dp[i]=MOD(dp[i]*inv[i]);
    //for(int i=0;i<=10;i++)
    //    printf("%lld ",dp[i]);
    for(int i=2;i<=5000;i++)
        deal(i);
    
}
int main()
{
    cal();
    while(scanf("%d",&n)!=EOF)
        printf("%lld\n",ave[n]);
    return 0;
}
