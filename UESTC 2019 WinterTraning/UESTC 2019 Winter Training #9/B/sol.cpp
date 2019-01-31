#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
int dep[maxn],f[maxn],a[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        dep[0]=0;
        int n;scanf("%d",&n);
        for (int i=1;i<n;i++) 
        {
            scanf("%d",&f[i]);
            dep[i]=dep[f[i]]+1;
        }
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int res=0;
        for (int i=0;i<n;i++) 
            if (dep[i]&1) res^=a[i];
        if (res) puts("win");
        else puts("lose"); 
    }
    return 0;
}

