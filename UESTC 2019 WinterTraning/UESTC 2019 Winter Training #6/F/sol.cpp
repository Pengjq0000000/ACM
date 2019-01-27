#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 2e5+7;
LL A,B,hp[maxn];
int n;
int check(LL x)
{
    LL cnt=0;
    for (int i=1;i<=n;i++)
    {
        LL tmp=hp[i]-B*x;
        if (tmp>0)
        {
            cnt+=tmp/(A-B);
            if (tmp%(A-B)!=0) cnt++;
        }
    }
    return cnt<=x;
}

int main()
{
    scanf("%d%lld%lld",&n,&A,&B);
    for (int i=1;i<=n;i++) scanf("%lld",&hp[i]);

    LL l=1,r=1e10;
    while (l<r)
    {
        LL mid=(l+r)/2;
        if (check(mid)) r=mid;
        else l=mid+1;
    }
    printf("%lld\n",l);
    return 0;
}

