#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6+7;
const LL INF = 1e17;
struct node{LL max,min,sum;}T[maxn<<2];

void pushup(int rt)
{
    T[rt].sum=T[rt<<1].sum+T[rt<<1|1].sum;
    T[rt].max=max(T[rt<<1].max,T[rt<<1|1].max);
    T[rt].min=min(T[rt<<1].min,T[rt<<1|1].min);
}
void update(int rt,int l,int r,int pos,LL val)
{
    if (l==r) {T[rt].sum=T[rt].max=T[rt].min=val;return;}
    int mid=(l+r)>>1;
    if (pos<=mid) update(rt<<1,l,mid,pos,val);
    else update(rt<<1|1,mid+1,r,pos,val);
    pushup(rt);
}
LL query_max(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].max;
    int mid=(l+r)>>1;
    LL res=-INF;
    if (L<=mid) res=max(res,query_max(rt<<1,l,mid,L,R));
    if (mid <R) res=max(res,query_max(rt<<1|1,mid+1,r,L,R));
    return res;
}
LL query_min(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].min;
    int mid=(l+r)>>1;
    LL res=INF;
    if (L<=mid) res=min(res,query_min(rt<<1,l,mid,L,R));
    if (mid <R) res=min(res,query_min(rt<<1|1,mid+1,r,L,R));
    return res;
}
LL query_sum(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt].sum;
    int mid=(l+r)>>1;
    LL res=0;
    if (L<=mid) res+=query_sum(rt<<1,l,mid,L,R);
    if (mid <R) res+=query_sum(rt<<1|1,mid+1,r,L,R);
    return res; 
}

int main()
{
    int n,m;scanf("%d%d",&n,&m);
    while (m--)
    {
        int op,x,y;scanf("%d%d%d",&op,&x,&y);
        if (op==0) update(1,1,n,x,y);
        else if (op==1) 
        {
            LL s=query_sum(1,1,n,x,y);
            LL mx=query_max(1,1,n,x,y),mi=query_min(1,1,n,x,y);
            printf("%lld\n",s-mx-mi);
        }
        
    }
    return 0;
}







