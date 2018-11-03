#include<bits/stdc++.h>
#define LL long long
#define Uint unsigned int
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r

using namespace std;
const int maxn = 1e5+7;
struct node
{
    Uint max,min,lazy;
}T[maxn<<2];
Uint X,Y,Z,f[4];

Uint RNG()
{
    X=X^(X<<11);
    X=X^(X>>4);
    X=X^(X<<5);
    X=X^(X>>14);
    Uint W=X^(Y^Z);
    X=Y;Y=Z;Z=W;
    return Z;
}
void pushup(int rt)
{
    T[rt].max=max(T[rt<<1].max,T[rt<<1|1].max);
    T[rt].min=min(T[rt<<1].min,T[rt<<1|1].min);
    return;
}
void pushdown(int rt)
{
    if (T[rt].lazy)
    {
        T[rt<<1].lazy=T[rt<<1|1].lazy=T[rt].lazy;
        T[rt<<1].max=T[rt<<1|1].max=T[rt].lazy;
        T[rt<<1].min=T[rt<<1|1].min=T[rt].lazy;
        
        T[rt].lazy=0;
    }
    return;
}
void update(int rt,int l,int r,int L,int R,int x)
{
    if (T[rt].min>=x) return;
    if (L<=l && r<=R && T[rt].max<x) {T[rt].lazy=T[rt].max=T[rt].min=x;return;}
    int mid=(l+r)>>1;
    pushdown(rt);
    if (mid>=L) update(lson,L,R,x);
    if (mid< R) update(rson,L,R,x);
    pushup(rt);
}
int query(int rt,int l,int r,int pos)
{
    if (l==r && l==pos) return T[rt].min;
    int mid=(l+r)>>1;
    pushdown(rt);
    if (mid>=pos) return query(lson,pos);
    else return query(rson,pos);
}
void build(int rt,int l,int r)
{
    if (l==r){T[rt].max=T[rt].min=T[rt].lazy=0;return;}
    int mid=(l+r)>>1;
    build(lson);
    build(rson);
    pushup(rt);
}

int main()
{
    int t,m,n;scanf("%d",&t);
    int base=(1<<30);
    while (t--)
    {
        scanf("%d%d%u%u%u",&n,&m,&X,&Y,&Z);
        for (int i=1;i<=n*4;i++) T[i].max=T[i].min=T[i].lazy=0;
        //build(1,1,n);
        int l,r,v;
        while (m--)
        {
            for (int i=1;i<=3;i++) f[i]=RNG();
            int tmp1=f[1]%n+1;int tmp2=f[2]%n+1;
            l=min(tmp1,tmp2);
            r=max(tmp1,tmp2);
            v=f[3]%base;
            update(1,1,n,l,r,v);
        }
        LL ans=0;
        for (int i=1;i<=n;i++)
        {
            ans^=(LL)query(1,1,n,i)*i;
        }
        printf("%lld\n",ans);
    }
    return 0;
}


