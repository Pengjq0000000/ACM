#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 50000+7;
struct node {LL sum,max;}T[maxn<<2];
int a[maxn];

void pushup(int rt) 
{
    T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;
    T[rt].max=max(T[rt<<1].max,T[rt<<1|1].max);
}
void build(int rt,int l,int r)
{
    if (l==r) {T[rt].sum=T[rt].max=a[l];return;}
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,int L,int R)
{
    if (T[rt].max<=1) return;
    if (l==r) {T[rt].max=sqrt(T[rt].max);T[rt].sum=T[rt].max;return;}
    int mid=(l+r)>>1;
    if (L<=mid) update(rt<<1,l,mid,L,R);
    if (mid <R) update(rt<<1|1,mid+1,r,L,R);
    pushup(rt);
}
LL query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].sum;
    int mid=(l+r)>>1;
    LL res=0;
    if (L<=mid) res+=query(rt<<1,l,mid,L,R);
    if (mid <R) res+=query(rt<<1|1,mid+1,r,L,R);
    return res; 
}
int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    build(1,1,n);
    int m=n;
    while (m--)
    {
        int op,x,y,c;scanf("%d%d%d%d",&op,&x,&y,&c);
        if (op==0) update(1,1,n,x,y);
        else printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}

