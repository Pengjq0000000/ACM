#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 4e5+7;
struct node
{
    int u,v;
    bool operator < (const node&rhs) const
    {
        return u<rhs.u;
    }
}h[maxn],v[maxn];
vector<int>vv;
int getid(int x)
{
    return lower_bound(vv.begin(),vv.end(),x)-vv.begin()+1;
}

int c[maxn],n;

int lowbit(int x) {return x&(-x);}
void update(int x,int val)
{
    for (x;x<=n;x+=lowbit(x)) c[x]+=val;
}
LL get(int x)
{
    int res=0;for(x;x>0;x-=lowbit(x)) res+=c[x];
    return res;
}


int main()
{
    int X,Y;scanf("%d%d",&X,&Y);
    LL H,V;scanf("%lld%lld",&H,&V);
    for (int i=1;i<=H;i++) 
    {
        scanf("%d%d",&h[i].u,&h[i].v);
        vv.pb(h[i].u);vv.pb(h[i].v);
    }
    for (int i=1;i<=V;i++) 
    {
        scanf("%d%d",&v[i].u,&v[i].v);
        vv.pb(v[i].u);vv.pb(v[i].v);
    }
    sort(h+1,h+1+H);sort(v+1,v+1+V);
    sort(vv.begin(),vv.end());
    vv.erase(unique(vv.begin(),vv.end()),vv.end());
    n=vv.size();
    MEM(c,0);LL Hp=0;
    for (int i=1;i<=H;i++)
    {
        int id=getid(h[i].v);
        update(id,1);
        Hp+=(LL)i-get(id);
    }
    MEM(c,0);LL Vp=0;
    for (int i=1;i<=V;i++)
    {
        int id=getid(v[i].v);
        update(id,1);
        Vp+=(LL)i-get(id);
    }
    LL ans=H*V+Hp+Vp+H+V+(LL)1;
    printf("%lld\n",ans);
    return 0;
}










