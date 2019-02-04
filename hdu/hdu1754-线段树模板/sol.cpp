#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
const int INF = 1e9;
int T[maxn<<2],a[maxn];

void pushup(int rt){T[rt]=max(T[rt<<1],T[rt<<1|1]);}
void build(int rt,int l,int r)
{
    if (l==r) {T[rt]=a[l];return;}
    int mid=(l+r)>>1;
    build(rt<<1,l,mid);
    build(rt<<1|1,mid+1,r);
    pushup(rt);
}
void update(int rt,int l,int r,int pos,int val)
{
    if (l==r) {T[rt]=val;return;}
    int mid=(l+r)>>1;
    if (pos<=mid) update(rt<<1,l,mid,pos,val);
    else update(rt<<1|1,mid+1,r,pos,val);
    pushup(rt);
}
int query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt];
    int mid=(l+r)>>1,res=-INF;
    if (L<=mid) res=max(res,query(rt<<1,l,mid,L,R));
    if (mid< R) res=max(res,query(rt<<1|1,mid+1,r,L,R));
    return res;
}


int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n);
        while (m--)
        {
            char c;int x,y;scanf(" %c %d %d",&c,&x,&y);
            if (c=='Q') printf("%d\n",query(1,1,n,x,y));
            else if (c=='U') update(1,1,n,x,y);
        }
    }
    return 0;
}

