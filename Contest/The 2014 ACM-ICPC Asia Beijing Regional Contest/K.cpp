#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e6+7;
int a[maxn];
int main()
{
    int T,cas=0;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        int mi=1e9,ans=0;
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        for (int i=n;i>=1;i--) 
        {
            mi=min(mi,a[i]);
            if (a[i]>mi) ans++;
        }
        printf("Case #%d: %d\n",++cas,ans);
    }
    return 0;
}
