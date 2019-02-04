#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxN = 1e7+17;
int vis[maxN];
int prime[maxN],tot=0;
int check[maxN];
void init(int maxl)
{
    for (int i=2;i<=maxl;i++)
    {
        if (!vis[i]) prime[++tot]=i;
        for (int j=1;j<=tot;j++)
        {
            if (i*prime[j]>maxl) break;
            vis[i*prime[j]]=1;
            if (i%prime[j]==0) break;
        }
    }
    MEM(check,0);
    for (int i=1;i<=tot;i++) check[prime[i]]=1;
    check[0]=check[6]=1;
    for (int i=1;i<=maxl;i*=2) check[i]=1;
}

const int maxn = 1e5+7;
struct node
{
    int sum,max;
}T[maxn*4];

int n,q,a[maxn];


void pushup(int rt)
{
    T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;
    T[rt].max=max(T[rt<<1].max,T[rt<<1|1].max);
}

void build(int rt,int l,int r)
{
    if (l==r)
    {
        T[rt].max=a[l];
        T[rt].sum=check[a[l]];
        return;
    }
    int mid=(l+r)/2;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].sum;
    int mid=(l+r)/2,res=0;
    if (L<=mid) res+=query(rt<<1,l,mid,L,R);
    if (mid< R) res+=query(rt<<1|1,mid+1,r,L,R);
    return res;
}

void updatep(int rt,int l,int r,int pos,int x)
{
    if (l==r && l==pos)
    {
        T[rt].max=x;
        T[rt].sum=check[x];
        return;
    }
    int mid=(l+r)/2;
    if (pos<=mid) updatep(rt<<1,l,mid,pos,x);
    else updatep(rt<<1|1,mid+1,r,pos,x);
    pushup(rt);
}

void updatemod(int rt,int l,int r,int L,int R,int mod)
{
    if (T[rt].max<mod) return;
    if (l==r)
    {
        T[rt].max%=mod;
        T[rt].sum=check[T[rt].max];
        return;
    }
    int mid=(l+r)/2;
    if (L<=mid) updatemod(rt<<1,l,mid,L,R,mod);
    if (mid <R) updatemod(rt<<1|1,mid+1,r,L,R,mod);
    pushup(rt);
}


int main()
{
    init(1e7+7);
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        scanf("%d",&q);
        while (q--)
        {
            int op,l,r,v,p;scanf("%d",&op);
            if (op==1)
            {
                scanf("%d%d",&l,&r);
                int ans=query(1,1,n,l,r);
                printf("%d\n",ans);
            }
            else if (op==2)
            {
                scanf("%d%d%d",&l,&r,&v);
                updatemod(1,1,n,l,r,v);
            }
            else if (op==3)
            {
                scanf("%d%d",&p,&v);
                updatep(1,1,n,p,v);
            }
    }
    }

    return 0;
}




