#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
vector<int>s[1007];
int vis[1007];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    int cnt;scanf("%d",&cnt);
    for (int i=1;i<=cnt;i++)
    {
        int d;scanf("%d",&d);vis[d]=1;
    }
    for (int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        for (int j=1;j<=x;j++)
        {
            int d;scanf("%d",&d);s[i].pb(d);
        }
    }
    int tot=4,ans=0;
    while (tot--)
    {
        int flg=0;
        for (int i=1;i<=n;i++)
        {
            for (int x:s[i])
            {
                vis[x]^=1;
                if (vis[x]) cnt++;else cnt--;
            }
            ans++;
            if (cnt==0) {flg=1;break;}
        }
        if (flg) break;
    }
    printf("%d\n",ans==4*n?-1:ans);
    return 0;
}

