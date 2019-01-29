#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
LL a;
double h(int k)
{
    if (k==a) return 1;
    return 1+(a-k)/(1+k)*h(1+k);
}

LL quick(LL a,LL b)
{
    LL res=1,base=a;
    while (b)
    {
        if (b&1) res=MOD(res*base);
        base=MOD(base*base);
        b>>=1;
    }
    return res;
}

int main()
{
    scanf("%lld",&a);
    if (a<0) puts("Nobody got time for that");
    else
    {
        LL ans=quick(2,a);
        printf("%lld\n",ans);
    }
    return 0;
}

