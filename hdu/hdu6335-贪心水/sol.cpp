#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
LL a[1000];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,m;scanf("%d%d",&n,&m);
        for (int i=0;i<n;i++)
        {
            LL x,y;scanf("%lld%lld",&x,&y);
            a[i]=x+y;
        }
        sort(a,a+n);
        LL tmp=1;
        int ans=0;
        for (int i=0;i<n;i++)
        {
            tmp*=a[i];
            if (tmp>m) break;
            ans++;
        }
        printf("%d\n",ans);
    }
    return 0;
}
