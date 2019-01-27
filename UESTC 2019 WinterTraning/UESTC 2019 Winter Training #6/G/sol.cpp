#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
int n;
LL a[maxn],sum[maxn],c[maxn*2];
vector<LL>v;
int lowbit(int x) {return x&(-x);}


void add(int now,LL val)
{
    while (now<=n+1) c[now]+=val,now+=lowbit(now);
}

LL getsum(int now)
{
    LL sum=0;
    while (now>0)
    {
        sum+=c[now];
        now-=lowbit(now);
    }
    return sum;
}

LL get(int l,int r)
{
    return getsum(r)-getsum(l-1);
}

int getid(LL x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

int main()
{
    LL k;scanf("%d%lld",&n,&k);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]),a[i]-=k;
    sum[0]=0;for (int i=1;i<=n;i++) sum[i]=sum[i-1]+a[i],v.pb(sum[i]);
    v.pb(0);
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());


    LL ans=0;
    for (int i=n;i>=0;i--)
    {
        int id=getid(sum[i]);
        ans+=get(id,n+1);
        add(id,1);
    }
    printf("%lld\n",ans);
    return 0;
}

