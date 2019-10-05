#include<bits/stdc++.h>
#define inf 0x3f3f3f3f
using namespace std;
int n;
int a[5005];
int f[5005];
int g[5005];
int cnt[5005];
int del[5005];
int pre[5005];
int minv[5005];
int ans;
void ini()
{
    ans=0;
    for(int i=1;i<=n;i++)
        cnt[i]=0,pre[i]=0;
    for(int i=1;i<=n;i++)
        minv[i]=inf;
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        ini();
        for(int i=1;i<=n;i++)
            scanf("%d",&a[i]);
        for(int k=1;k<=n;k++)
        {
            long long ans=0;
            for(int i=1;i<=n;i++)
            {
                if(i==k) continue;
                f[i]=1;
                for(int j=1;j<i;j++)
                {
                    if(j==k) continue;
                    f[i]=max(f[i],f[j]+1);
                }
                ans^=f[i]+f[i];
            }
            if(k==n) printf("%d\n",ans);
            else printf("%d ",ans);
        }
    }
}

/*
5
2 5 3 1 4
5
2 5 3 1 4
5
2 5 3 1 4
8
5 23 8 6 1 5 5 2
*/