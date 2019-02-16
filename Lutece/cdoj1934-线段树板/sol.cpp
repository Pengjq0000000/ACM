#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 500007;
struct node {LL lazy,sum;}T[maxn<<2];
LL a[maxn];
void pushup(int rt){T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;}
void build(int rt,int l,int r)
{
    if (l==r) {T[rt].sum=a[l];return;}
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void pushdown(int rt,int l,int r)
{
    if (T[rt].lazy==0) return;
    int mid=(l+r)>>1;
    T[rt<<1].lazy+=T[rt].lazy;
    T[rt<<1|1].lazy+=T[rt].lazy;
    T[rt<<1].sum+=T[rt].lazy*(mid-l+1);
    T[rt<<1|1].sum+=T[rt].lazy*(r-mid);
    T[rt].lazy=0;
}
void update(int rt,int l,int r,int L,int R,LL val)
{
    if (L<=l && r<=R)
    {
        T[rt].sum+=val*(r-l+1);
        T[rt].lazy+=val;
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) update(rt<<1,l,mid,L,R,val);
    if (mid <R) update(rt<<1|1,mid+1,r,L,R,val);
    pushup(rt);
}
LL query(int rt,int l,int r,int pos)
{
    if (l==r) return T[rt].sum;
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if (pos<=mid) return query(rt<<1,l,mid,pos);
    else return query(rt<<1|1,mid+1,r,pos);
}
int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%lld",&a[i]);
    build(1,1,n);
    int m=n;
    while (m--)
    {
        int op,l,r;LL val;scanf("%d%d%d%lld",&op,&l,&r,&val);
        if (op==0) update(1,1,n,l,r,val);
        else if (op==1) printf("%lld\n",query(1,1,n,r));
    }
    return 0;
}






