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
    LL mul,mullazy,sta,stalazy;
}T[maxn<<2];
int a[maxn];
LL inv[100],state[400];

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
void pushup(int rt)
{
    T[rt].mul=MOD(T[rt<<1].mul*T[rt<<1|1].mul);
    T[rt].sta=T[rt<<1].sta|T[rt<<1|1].sta;
}
void build(int rt,int l,int r)
{
    T[rt].mullazy=1;T[rt].stalazy=0;
    if (l==r)
    {
        T[rt].mul=a[l];
        T[rt].sta=state[a[l]];
        return;
    }
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void pushdown(int rt,int l,int r)
{
    int mid=(l+r)>>1;
    if (T[rt].mullazy>1)
    {
        T[rt<<1].mullazy=MOD(T[rt<<1].mullazy*T[rt].mullazy);
        T[rt<<1|1].mullazy=MOD(T[rt<<1|1].mullazy*T[rt].mullazy);
        T[rt<<1].mul=MOD(T[rt<<1].mul*quick(T[rt].mullazy,mid-l+1));
        T[rt<<1|1].mul=MOD(T[rt<<1|1].mul*quick(T[rt].mullazy,r-mid));
        T[rt].mullazy=1;
    }
    if (T[rt].stalazy>0)
    {
        T[rt<<1].stalazy=T[rt<<1].stalazy|T[rt].stalazy;
        T[rt<<1|1].stalazy=T[rt<<1|1].stalazy|T[rt].stalazy;
        T[rt<<1].sta=T[rt<<1].sta|T[rt].stalazy;
        T[rt<<1|1].sta=T[rt<<1|1].sta|T[rt].stalazy;
        T[rt].stalazy=0;
    }
}
void updatemul(int rt,int l,int r,int L,int R,int val,LL st)
{
    if (L<=l && r<=R)
    {
        T[rt].mul=MOD(T[rt].mul*quick(val,r-l+1));
        T[rt].mullazy=MOD(T[rt].mullazy*val);
        T[rt].sta=T[rt].sta|st;
        T[rt].stalazy=T[rt].stalazy|st;
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) updatemul(rt<<1,l,mid,L,R,val,st);
    if (mid <R) updatemul(rt<<1|1,mid+1,r,L,R,val,st);
    pushup(rt);
}

node query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R)
    {
        node r;
        r.mul=T[rt].mul;r.sta=T[rt].sta;
        return r;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    node res,tmp;res.mul=1;res.sta=0;
    if (L<=mid)
    {
        tmp=query(rt<<1,l,mid,L,R);
        res.mul=MOD(res.mul*tmp.mul);
        res.sta=res.sta|tmp.sta;
    }
    if (mid<R)
    {
        tmp=query(rt<<1|1,mid+1,r,L,R);
        res.mul=MOD(res.mul*tmp.mul);
        res.sta=res.sta|tmp.sta;
    }
    return res;
}

int vis[maxn];
int prime[maxn],tot=0;
void init()
{
    int maxl=300;
    for (int i=2;i<=maxl;i++)
    {
        if (!vis[i]) prime[tot++]=i;
        for (int j=0;j<tot;j++)
        {
            if (i*prime[j]>maxl) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
    for (int i=0;i<tot;i++) inv[i]=quick(prime[i],mod-2);
    for (int i=1;i<=300;i++)
    {
        int tmp=i;LL st=0;
        for (int j=0;j<tot;j++)
        {
            if (tmp%prime[j]==0)
            {
                while (tmp%prime[j]==0) tmp/=prime[j];
                st=st|(1LL<<j);
            }
        }
        state[i]=st;
    }
}
char s[20];
int main()
{
    init();
    int n,q;scanf("%d%d",&n,&q);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    while (q--)
    {
        scanf("%s",s);
        int l,r,x;
        if (s[0]=='T')
        {
            scanf("%d%d",&l,&r);
            node res=query(1,1,n,l,r);
            LL tmp=1;
            for (int i=0;i<62;i++) 
            {
                if (res.sta&(1LL<<i)) res.mul=MOD(res.mul*MOD(1-inv[i]+mod));
            }
            printf("%lld\n",res.mul);
        }
        if (s[0]=='M')
        {
            scanf("%d%d%d",&l,&r,&x);
            if (x==1) continue;
            updatemul(1,1,n,l,r,x,state[x]);
        }
    }
    return 0;
}

