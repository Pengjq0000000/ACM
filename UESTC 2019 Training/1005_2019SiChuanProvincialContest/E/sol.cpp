#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[5005];
int f[5005];
int g[5005];
int minv[5005];
int ans;
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ans=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]); f[i]=1;
            for(int j=1;j<i;j++)
            {
                if(a[j]>=a[i]) continue;
                f[i]=max(f[i],f[j]+1);
            }
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++) minv[j]=inf;
            ans=0;
            for(int j=1;j<i;j++) ans^=f[j]*f[j],minv[f[j]]=min(minv[f[j]],a[j]);
            for(int j=i+1;j<=n;j++)
            {
                if(minv[f[j]-1]<a[j]) g[j]=f[j];
                else g[j]=f[j]-1;
                minv[g[j]]=min(minv[g[j]],a[j]);
                ans^=g[j]*g[j];
            }
            if(i==n) printf("%d\n",ans);
            else printf("%d ",ans);
        }
    }
}

/*
5
2 5 3 1 4
10
4 2 5 2 4 1 1 2 3 3
5
2 5 3 1 4
8
5 23 8 6 1 5 5 2
5
2 5 3 1 4
*/