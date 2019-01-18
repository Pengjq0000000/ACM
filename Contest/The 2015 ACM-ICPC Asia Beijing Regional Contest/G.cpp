#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int w[10],h[10],vis[10],flg;

void dfs(int noww,int nowh,int cnt)
{
    if (flg) return;
    if (cnt==3)
    {
        flg=1;return;
    }
    for (int i=1;i<=4;i++)
    {
        if (!vis[i])
        {
            if (nowh==h[i])
            {
                vis[i]=1;
                dfs(nowh,noww+w[i],cnt+1);
                vis[i]=0;
            }
            if (nowh==w[i])
            {
                vis[i]=1;
                dfs(nowh,noww+h[i],cnt+1);
                vis[i]=0;
            }
            if (noww==w[i])
            {
                vis[i]=1;
                dfs(nowh+h[i],noww,cnt+1);
                vis[i]=0;
            }
            if (noww==h[i])
            {
                vis[i]=1;
                dfs(nowh+w[i],noww,cnt+1);
            }
        }
    }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=4;i++)
            scanf("%d %d",&w[i],&h[i]);
        flg=0;
        for (int i=1;i<=4;i++)
            {
                MEM(vis,0);vis[i]=1;
                dfs(w[i],h[i],1);
            }
        if (flg) puts("Yes");else puts("No");
    }
    return 0;
}
