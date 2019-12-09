#include<bits/stdc++.h>
using namespace std;
int n,m,k,r,c;
int x[10005],y[10005];
int num[30005];
int dis(int a,int b)
{
    return abs(a-r)+abs(b-c);
}
int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    scanf("%d%d%d%d%d",&n,&m,&k,&r,&c);
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=m;j++)
        {
            int a;
            scanf("%d",&a);
            if(a)
            {
                x[a]=i;
                y[a]=j;
            }
        }
    }
    for(int i=1;i<=k;i++)
        num[i+dis(x[i],y[i])]++;
    int cnt=0;
    for(int i=1;i<=30000;i++)
        if(num[i]) cnt++;
    printf("%d\n",cnt);
    for(int i=1;i<=30000;i++)
        if(num[i]) printf("%d %d\n",i,num[i]);
}