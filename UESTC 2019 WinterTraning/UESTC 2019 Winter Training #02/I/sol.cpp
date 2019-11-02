#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1007;
int s[maxn],T;
int main()
{
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++) scanf("%d",&s[i]);
    scanf("%d",&T);
    int mx=1e9,ans;
    for (int i=1;i<=n;i++)
    {
        if (T%s[i]<mx)
        {
            mx=T%s[i];
            ans=s[i];
        }
    }
    printf("%d",ans);
    return 0;
}
