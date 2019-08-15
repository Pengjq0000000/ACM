#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define LL long long
using namespace std;
int n,m;
LL a[1000006];
LL b[1000006];
struct cls
{
    LL a,b;
    bool friend operator < (cls x,cls y)
    {
        if(x.a+x.b==y.a+y.b) return x.b<y.b;
        return x.a+x.b>y.a+y.b;
    }
}c[1000006];
LL S;
LL ot[1000006];
LL flex,fix;
LL ans;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        S=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&a[i],&b[i]);
            c[i].a=a[i];
            c[i].b=b[i];
            S+=b[i];
        }
        for(int i=1;i<=n;i++)
        {
            a[i]=c[i].a;
            b[i]=c[i].b;
        }
        ans=0;
        flex=0;
        fix=0;
        for(int i=1;i<=n;i++)
        {
            //LL tmp=fix;
            //LL x=min(flex,b[i]);
            //fix+=x;
            //flex-=x;
            //LL y=min(a[i],S-b[i]-flex-fix);
            //flex+=y;
            LL left=S-b[i]-flex-fix;
            if(a[i]<=left) flex+=a[i];
            else
            {
                LL x=min(flex,min(b[i],a[i]-left));
                fix+=x;
                flex-=x;
                flex+=min(left+x,a[i]);
            }
            
        }
        ans=flex+fix;
        printf("%lld\n",ans);
    }
    
    return 0;
}
