#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;

int main()
{
    int T;scanf("%d",&T);
    int ans=0;
    while (T--)
    {
        int x;scanf("%d",&x);
        if (x!=1) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

