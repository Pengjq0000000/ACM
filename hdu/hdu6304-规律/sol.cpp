#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
LL n,f[100];


LL cal(LL n)
{
    LL res=0;int cnt=0;
    while (n>0)
    {
        cnt++;
        if (n&1) res+=f[cnt];
        n/=2;
    }
    return res;
}

LL get(LL n)
{
    LL l=n/2,r=n/2+50;
    while (l<r)
    {
        LL mid=(l+r)/2;
        LL tmp=cal(mid);
        if (tmp<n-1) l=mid+1;
        else r=mid;
    }
    return l;
}

int main()
{
    f[1]=1;for (int i=2;i<=63;i++) f[i]=f[i-1]*2+1;
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%lld",&n);
        LL an=get(n);
        LL base=1,ans=0,cnt=0;
        while (++cnt)
        {
            if (base>an) break;
            LL tmp=an/base;if (tmp%2==0) tmp--;
            if (tmp<0) break;
            ans=MOD(ans+MOD(cnt*MOD(MOD(base)*MOD(MOD((tmp+1)/2)*MOD((tmp+1)/2)))));
            //base=MOD(base*2);
            base*=2;
        }
        LL off=MOD(MOD((cal(an)+1-n))*MOD(an));
        //printf("off:%lld\n",off/an);
        ans=MOD(ans-off+1000000007);
        printf("%lld\n",MOD(ans+1));
    }
    return 0;
}
