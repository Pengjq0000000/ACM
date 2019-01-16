#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e6+7;

LL sum[maxn],tot;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for (int i=0;i<=n+1;i++) sum[i]=0;
        tot=0;
        while (m--)
        {
            LL x,y,w,h;scanf("%lld%lld%lld%lld",&x,&y,&w,&h);
            sum[x+1]+=h;sum[min(x+w+1,(LL)n)]-=h;
            tot+=(LL)w*h;
        }
        for (int i=1;i<=n;i++) sum[i]+=sum[i-1];
        for (int i=1;i<=n;i++) sum[i]+=sum[i-1]; 
        LL flg=0;
        for (int i=1;i<=n;i++) 
        {
            if (sum[i]*2>=tot)
            {
                flg=sum[i]*2;break;
            }
        }
        int ans;
        for (int i=n;i>=1;i--)
        {
            if (sum[i]*2==flg)
            {
                ans=i;break;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
