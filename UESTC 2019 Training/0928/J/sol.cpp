#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n,m;
char c[1005][1005];
ll dp1[1005][1005];
ll dp2[1005][1005];
ll dp3[1005][1005];
ll dp4[1005][1005];
ll ans;
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;i++)
        for(int j=1;j<=m;j++)
            scanf(" %c",&c[i][j]);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==c[i-1][j]&&c[i][j]==c[i][j-1]) dp1[i][j]=min(dp1[i-1][j],dp1[i][j-1])+1;
            else dp1[i][j]=0;
            ans+=dp1[i][j];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=1;j<=m;j++)
        {
            if(c[i][j]==c[i+1][j]&&c[i][j]==c[i][j-1]) dp2[i][j]=min(dp2[i+1][j],dp2[i][j-1])+1;
            else dp2[i][j]=0;
            ans+=dp2[i][j];
        }
    }
    for(int i=1;i<=n;i++)
    {
        for(int j=m;j>=1;j--)
        {
            if(c[i][j]==c[i-1][j]&&c[i][j]==c[i][j+1]) dp3[i][j]=min(dp3[i-1][j],dp3[i][j+1])+1;
            else dp3[i][j]=0;
            ans+=dp3[i][j];
        }
    }
    for(int i=n;i>=1;i--)
    {
        for(int j=m;j>=1;j--)
        {
            if(c[i][j]==c[i+1][j]&&c[i][j]==c[i][j+1]) dp4[i][j]=min(dp4[i+1][j],dp4[i][j+1])+1;
            else dp4[i][j]=0;
            ans+=dp4[i][j];
        }
    }
    printf("%lld",ans);
}