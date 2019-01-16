#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

LL n,q;

LL lowbit(LL x) {return x&(-x);}

LL sum(LL x)
{
    LL ans=0,base=1;
    while (x)
    {
        ans+=(x+1)/2*base;
        base*=2;
        x/=2;
    }
    return ans;
}

int cal(LL x)
{
    int ans=0;
    for (x;x<=n;x+=lowbit(x)) ans++;
    return ans;
}

int main()
{
    while (scanf("%lld%lld",&n,&q)!=EOF)
    {
        while (q--)
        {
            LL ans;
            int opt;scanf("%d",&opt);
            if (opt==1)
            {
                LL l,r;scanf("%lld%lld",&l,&r);
                ans=sum(r)-sum(l-1);
            }
            else
            {
                LL x;scanf("%lld",&x);
                ans=cal(x);
            }
            printf("%lld\n",ans);
        }
    }
    return 0;
}
