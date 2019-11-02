#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 60;
int bits[maxn],n,m,ans[maxn];
int main()
{
    scanf("%d%d",&n,&m);
    while(m--)
    {
        MEM(bits,0);MEM(ans,0);
        LL num,k;
        scanf("%lld%lld",&num,&k);
        k=k%n;
        for (int i=n;i>=1;i--)
        {
            bits[i]=num%2;
            num/=2;
        }
        LL res=0,base=1;
        for (int i=1;i<=n;i++)
        {
            int tmp=(i+k-1)%n+1;
            ans[i]=bits[tmp];
        }
        for (int i=n;i>=1;i--)
        {
            res+=base*ans[i];
            base*=2;
        }
        printf("%lld\n",res);
        //printf("\n");
    }
    return 0;
}
