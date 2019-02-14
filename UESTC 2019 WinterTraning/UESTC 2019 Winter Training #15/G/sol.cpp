#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;

int a[maxn];
LL lc[maxn],rc[maxn],num[maxn];

int lowbit(int x) {return x&(-x);}
void add(int x,LL val)
{
    for (x;x<maxn;x+=lowbit(x)) lc[x]+=val;
}
LL get(int x)
{
    LL res=0;
    for (x;x>0;x-=lowbit(x)) res+=lc[x];
    return res;
}

int main()
{
    int n;scanf("%d",&n);
    LL tmp=0;
    for (int i=1;i<=n;i++) 
    {
        scanf("%d",&a[i]);
        add(a[i],1);
        num[i]=i-get(a[i]);
    }
    MEM(lc,0);
    int cnt=0;
    for (int i=n;i>=1;i--)
    {
        cnt++;
        add(a[i],1);
        num[i]=min(num[i],cnt-get(a[i]));
    }
    LL ans=0;
    for (int i=1;i<=n;i++) ans+=num[i];
    printf("%lld\n",ans);
    return 0;
}

