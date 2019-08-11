#include<bits/stdc++.h>
#define mod 998244353
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
LL L,d,m;
LL S[10000007];
LL sum[10000007];
LL fac[10000007];
LL inv[10000007];
LL _ans[3005];
inline LL ksm(LL x,LL a)
{
    LL b=1;
    while(a)
    {
        if(a&1) b=MOD(b*x);
        x=MOD(x*x);
        a>>=1;
    }
    return b;
}
inline void ini()
{
    fac[0]=1;
    for(LL i=1;i<=10000005;i++)
        fac[i]=MOD(fac[i-1]*i);
    inv[10000005]=ksm(fac[10000005],mod-2);
    for(LL i=10000005;i>=1;i--)
        inv[i-1]=MOD(inv[i]*i);
    S[0]=1;
    sum[0]=1;
    for(LL i=1;i<=10000005;i++)
    {
        if(i>=d) S[i]=sum[i-d];
        sum[i]=sum[i-1]+S[i];
        if (sum[i]>=mod) sum[i] -= mod;
    }
    for(int i=0;i<=3002;i++)
        _ans[i]=-1;
}
inline LL C(LL n,LL m)
{
    if(n<m) return 0;
    return MOD(fac[n]*MOD(inv[m]*inv[n-m]));
}
inline LL F(LL i,LL j)
{
    if(i<=0||j<=0) return 0;
    return C(i-j*(d-1)-1,j-1);
}
struct attack
{
    LL t,p;
    bool friend operator < (attack a,attack b)
    {
        return a.p<b.p;
    }
}atk[3005];
LL p[3005],t[3005];
LL ans(LL x)
{
    if(_ans[x]!=-1) return _ans[x];
    LL sum=0;
    for(LL i=1;i<x;i++)
        sum=MOD(sum+ans(i)*F(p[x]-p[i],t[x]-t[i]));
    return _ans[x]=MOD(F(p[x],t[x])-sum+mod);
}
inline LL ANS()
{
    LL sum=0;
    for(LL i=1;i<=m;i++)
        sum=MOD(sum+ans(i)*S[L-p[i]]);
    return MOD(S[L]-sum+mod);
}
int main()
{
    scanf("%lld%lld%lld",&L,&d,&m);
    //L=10000000,d=1,m=3000;
    ini();
    for(LL i=1;i<=m;i++)
        scanf("%lld%lld",&atk[i].t,&atk[i].p);
    sort(atk+1,atk+1+m);
    for(LL i=1;i<=m;i++)
        p[i]=atk[i].p,t[i]=atk[i].t;
    printf("%lld",ANS());
    return 0;
}
