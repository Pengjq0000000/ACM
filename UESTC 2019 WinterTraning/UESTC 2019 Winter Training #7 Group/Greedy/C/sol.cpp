#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
struct node
{
    int w,s;
    bool operator < (const node &rhs) const
    {
        return w+s<rhs.w+rhs.s;
    }
}a[maxn];
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d%d",&a[i].w,&a[i].s);
        sort(a+1,a+1+n);
        LL ans=0,sum=0;
        for (int i=2;i<=n;i++)
        {
            sum+=a[i-1].w;
            ans=max(ans,sum-a[i].s);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

