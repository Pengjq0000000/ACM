#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
map<int,int>vis;
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        vis.clear();
        int n;scanf("%d",&n);
        int ans=0;
        for (int i=1;i<=n;i++)
        {
            int c;scanf("%d",&c);
            if (vis[c]>0)
            {
                ans++;vis.clear();
            }
            vis[c]=1;
        }
        printf("%d\n",ans+1);
    }
    return 0;
}
