#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6+7;
struct node{LL sum,lazy;}T[maxn<<2];

void pushup(int rt) {T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;}
void pushdown(int rt,int l,int r)
{
    if (T[rt].lazy==0) return;
    int mid=(l+r)>>1;
    T[rt<<1].lazy+=T[rt].lazy;
    T[rt<<1|1].lazy+=T[rt].lazy;
    T[rt<<1].sum+=T[rt].lazy*(LL)(mid-l+1);
    T[rt<<1|1].sum+=T[rt].lazy*(LL)(r-mid);
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
LL query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].sum;
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    LL res=0;
    if (L<=mid) res+=query(rt<<1,l,mid,L,R);
    if (mid <R) res+=query(rt<<1|1,mid+1,r,L,R);
    return res;
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    while (m--)
    {
        int op,x,y;LL v;scanf("%d%d%d%lld",&op,&x,&y,&v);
        if (op==0) update(1,1,n,x,y,v);
        else printf("%lld\n",query(1,1,n,x,y));
    }
    return 0;
}





