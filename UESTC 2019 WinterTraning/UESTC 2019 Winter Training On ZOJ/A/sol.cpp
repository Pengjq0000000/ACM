#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        LL k;scanf("%lld",&k);k--;
        int cnt=0;LL ans=1;
        for (int i=1;i<=70;i++)
        {
            if (k&1) ans*=2;
            k/=2;
        }
        printf("%lld\n",ans);
    }
    return 0;
}
