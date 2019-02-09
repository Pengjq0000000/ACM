#include<algorithm>
#include<iostream>
#include<cstdio>
#include<cmath>
#include<string.h>
#include<vector>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
int T[maxn*4+7],lazy[maxn*4+7];

void pushdown(int rt,int l,int r)
{
    if (lazy[rt]==0) return;
    lazy[rt<<1]=lazy[rt<<1|1]=lazy[rt];
    T[rt<<1]=T[rt<<1|1]=lazy[rt];
    lazy[rt]=0;
}

void update(int rt,int l,int r,int L,int R,int clr)
{
    if (L<=l && r<=R)
    {
        lazy[rt]=clr;
        T[rt]=clr;
        return;
    }
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if (L<=mid) update(rt<<1,l,mid,L,R,clr);
    if (mid <R) update(rt<<1|1,mid+1,r,L,R,clr);
}

int query(int rt,int l,int r,int pos)
{
    if (l==r) return T[rt];
    pushdown(rt,l,r);
    int mid=(l+r)>>1;
    if (pos<=mid) query(rt<<1,l,mid,pos);
    else query(rt<<1|1,mid+1,r,pos);
}

vector<int>v;

int getid(int x)
{
    return lower_bound(v.begin(),v.end(),x)-v.begin()+1;
}

int vis[maxn],l[maxn],r[maxn];
int main()
{
    int t;scanf("%d",&t);
    while (t--)
    {
        int n;scanf("%d",&n);MEM(T,0);MEM(lazy,0);
        v.clear();
        for (int i=1;i<=n;i++)
        {
            scanf("%d%d",&l[i],&r[i]);
            v.pb(l[i]);v.pb(r[i]);
        }
        sort(v.begin(),v.end());
        v.erase(unique(v.begin(),v.end()),v.end());
        int tot=v.size();
        for (int i=1;i<=n;i++)
        {
            int L=getid(l[i]),R=getid(r[i]);
            update(1,1,tot,L,R,i);
        }
        int ans=0;
        MEM(vis,0);
        for (int i=1;i<=tot;i++)
        {
            int tmp=query(1,1,tot,i);
            if (tmp>0 && !vis[tmp]) vis[tmp]=1,ans++;
        }
        printf("%d\n",ans);
    }

    return 0;
}

