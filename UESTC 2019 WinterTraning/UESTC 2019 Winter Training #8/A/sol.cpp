#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;

const int maxn = 400005;

int n,m,a[10][maxn],b[maxn],f[10][maxn][2],lazy[10][maxn];

void pushup(int k,int rt)
{
    f[k][rt][0]=f[k][rt<<1][0]+f[k][rt<<1|1][0];
    f[k][rt][1]=f[k][rt<<1][1]+f[k][rt<<1|1][1];
}

void build(int k,int rt,int l,int r)
{
    if (l==r)
    {
        f[k][rt][a[k][l]]=1;
        return ;
    }
    int mid=(l+r)/2;
    build(k,rt<<1,l,mid);
    build(k,rt<<1|1,mid+1,r);
    pushup(k,rt);
}

void pushdown(int k,int rt)
{
    int lch=(rt<<1),rch=(rt<<1|1);
    if (lazy[k][rt])
    {
        lazy[k][lch]^=1; swap(f[k][lch][0],f[k][lch][1]);
        lazy[k][rch]^=1; swap(f[k][rch][0],f[k][rch][1]);
        lazy[k][rt]=0;
    }
}

void update(int k,int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R)
    {
        lazy[k][rt]^=1;
        swap(f[k][rt][0],f[k][rt][1]);
        return ;
    }
    pushdown(k,rt);
    int mid=(l+r)/2;
    if (L<=mid) update(k,rt<<1,l,mid,L,R);
    if (mid<R) update(k,rt<<1|1,mid+1,r,L,R);
    pushup(k,rt);
}

int query(int k,int rt,int l,int r,int L,int R)
{
    if (L<=l && r<=R) return f[k][rt][1];
    pushdown(k,rt);
    int mid=(l+r)/2;
    int res=0;
    if (L<=mid) res+=query(k,rt<<1,l,mid,L,R);
    if (mid<R) res+=query(k,rt<<1|1,mid+1,r,L,R);
    return res;
}

int main()
{
    scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        scanf("%d",&b[i]);
        for (int j=0;j<10;j++) a[j][i]=(b[i]&(1<<j))?1:0;
    }
    for (int k=0;k<10;k++)
    {
        for (int i=1;i<=n;i++) a[k][i]^=a[k][i-1];
    }
    for (int k=0;k<10;k++) build(k,1,0,n);
    while (m--)
    {
        int op,l,r;scanf("%d%d%d",&op,&l,&r);
        if (op==1)
        {
            for (int k=0;k<10;k++)
            {
                if ((r&(1<<k)) != (b[l]&(1<<k))) update(k,1,0,n,l,n);
            }
            b[l]=r;
        }
        if (op==2)
        {
            LL ans=0,tmp=0;
            for (int k=0;k<10;k++)
            {
                tmp=query(k,1,0,n,l-1,r); // number of 1
                tmp=(r-l+1-tmp+1)*tmp%4001;
                ans=(ans+(1LL<<k)*tmp%4001)%4001;
            }
            printf("%lld\n",ans);
        }

    }
    return 0;
}


/*

4
8
1 2 3 4
2 1 2
1 1 2
2 1 3
2 1 4
1 3 7
2 1 3
1 4 5
2 1 4

*/








