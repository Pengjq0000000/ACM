#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
int n,T[maxn<<2],a[maxn];

void pushup(int rt)
{
    T[rt]=T[rt<<1]+T[rt<<1|1];
}

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
    if (l==r) {T[rt]+=val;return;}
    int mid=(l+r)>>1;
    if (pos<=mid) update(rt<<1,l,mid,pos,val);
    else update(rt<<1|1,mid+1,r,pos,val);
    pushup(rt);
}

int query(int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return T[rt];
    int mid=(l+r)>>1,res=0;
    if (L<=mid) res+=query(rt<<1,l,mid,L,R);
    if (mid< R) res+=query(rt<<1|1,mid+1,r,L,R);
    return res;
}


char s[20];

int main()
{
    int t,cas=0;scanf("%d",&t);
    while (t--)
    {
        printf("Case %d:\n",++cas);
        scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        build(1,1,n); 
        while (scanf(" %s",s))
        {
            if (s[0]=='E') break;
            int x,y;scanf("%d%d",&x,&y);
            if (s[0]=='Q') printf("%d\n",query(1,1,n,x,y));
            else if (s[0]=='A') update(1,1,n,x,y);
            else if (s[0]=='S') update(1,1,n,x,-y);
        }
    }
    return 0;
}

