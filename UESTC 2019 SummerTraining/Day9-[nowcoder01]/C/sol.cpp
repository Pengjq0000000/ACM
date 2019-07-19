#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define int long long
using namespace std;
int n,m,k;
int a[10005];
int cnt;
int b[10005];
int c[10005];
int now;
long long son,mom;
bool cmp(int a,int b)
{
    return a>b;
}
void ini()
{
     
}
signed main()
{
    while(scanf("%lld%lld",&n,&m)!=EOF)
    {
        ini();
        for(int i=1;i<=n;i++)
            scanf("%lld",&a[i]);
        sort(a+1,a+1+n,cmp);
        a[0]=1005; cnt=0;
        for(int i=1;i<=n;i++)
        {
            if(a[i]==a[i-1]) c[cnt]++;
            else b[++cnt]=a[i],c[cnt]=1;
        }
        k=m; now=1;
        son=0,mom=1;
        for(int i=1;i<cnt;i++)
        {
            int cost=c[i]*(b[i]-b[i+1]);
            if(cost<=k) now=i+1,k-=cost,c[i+1]+=c[i];
            else break;
        }
        son=((long long)b[now]*c[now]-k)*((long long)b[now]*c[now]-k);
        mom=(long long)c[now];
        for(int i=now+1;i<=cnt;i++)
            son+=mom*c[i]*b[i]*b[i];
        mom=mom*m*m;
        if(son==0) printf("0\n");
        else
        {
            long long g=__gcd(son,mom);
            son/=g; mom/=g;
            if(mom==1) printf("%lld\n",son);
            else printf("%lld/%lld\n",son,mom);
        }
    }
    return 0;
}
