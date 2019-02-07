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
int main()
{
    int cas=0,n;
    while (scanf("%d",&n)!=EOF)
    {
        
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int gcd=a[1];for (int i=1;i<=n;i++) gcd=__gcd(gcd,a[i]);
        int tot=-1;if (gcd==1) tot=2*(n-1);
        printf("Case %d: %d\n",++cas,tot);
        if (tot>0)
        {
            for (int i=2;i<=n;i++) printf("1 %d\n",i);
            for (int i=2;i<=n;i++) printf("1 %d\n",i);
        }
        printf("\n");
    }
    return 0;
}

