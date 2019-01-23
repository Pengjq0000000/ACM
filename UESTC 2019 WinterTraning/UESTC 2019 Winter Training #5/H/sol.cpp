#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
LL a[1007];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        LL sum=0;
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%lld",&a[i]),sum+=a[i];
        if (sum%3==0) puts("Yes");
        else puts("No");
    }
    return 0;
}
