#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
struct node
{
    LL pos,p;
    node(LL pos,LL p):pos(pos),p(){}
    node(){}
    bool operator < (const node &rhs) const
    {
        return pos<rhs.pos;
    }
}city[maxn];

vector<LL>v,vv;
int n,m;
LL lazy[maxn],sum[maxn];
int cloud[maxn],range[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&city[i].p);
    for (int i=1;i<=n;i++) scanf("%lld",&city[i].pos),v.pb(city[i].pos);
    
    sort(city+1,city+1+n);
    sort(v.begin(), v.end());
    
    scanf("%d",&m);
    for (int i=1;i<=m;i++) scanf("%d",&cloud[i]);
    for (int i=1;i<=m;i++) scanf("%d",&range[i]);
    
    for (int i=1;i<=m;i++)
    {
        int l=lower_bound(v.begin(),v.end(),cloud[i]-range[i])-v.begin()+1;
        int r=upper_bound(v.begin(),v.end(),cloud[i]+range[i])-v.begin()+1;
        if (cloud[i]+range[i]>=v[v.size()-1]) r=n+1;
        
        if (l<=r) {lazy[l]++;lazy[r]--;}
    }
    
    
    LL ans=0;
    int tot=0;
    for (int i=1;i<=n;i++) 
    {
        lazy[i]+=lazy[i-1];
        if (lazy[i]==0) ans+=city[i].p;
        else if (lazy[i]==1)
        {
            vv.pb(city[i].pos);
            tot++;sum[tot]=sum[tot-1]+city[i].p;
        }
    }
    
    
    LL tmp=0;
    
    if (vv.size()!=0)
    {
        for (int i=1;i<=m;i++)
        {
            int l=lower_bound(vv.begin(),vv.end(),cloud[i]-range[i])-vv.begin()+1;
            int r=upper_bound(vv.begin(),vv.end(),cloud[i]+range[i])-vv.begin();
            if (cloud[i]+range[i]>=vv[vv.size()-1]) r=vv.size();
            if (l<=r) tmp=max(tmp,sum[r]-sum[l-1]);
        }
    }
    printf("%lld\n",ans+tmp);
    return 0;
}

