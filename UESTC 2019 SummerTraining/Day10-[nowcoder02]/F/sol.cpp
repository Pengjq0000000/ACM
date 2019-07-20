#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
long long a[30][30];
long long s1[30],s2[30];
long long ans,ans1,ans2;
void dfs(int x,int cnt1,int cnt2)
{
    if(x==m+1)
    {
        ans=max(ans,ans1+ans2);
        return;
    }
        if(cnt1<n)
        {
            long long tmp=0;
            s1[cnt1+1]=x;
            for(int j=1;j<=cnt2;j++)
                tmp+=a[x][s2[j]];
            ans1+=tmp;
            dfs(x+1,cnt1+1,cnt2);
            ans1-=tmp;
        }
        if(cnt2<n)
        {
            long long tmp=0;
            s2[cnt2+1]=x;
            for(int j=1;j<=cnt1;j++)
                tmp+=a[x][s1[j]];
            ans2+=tmp;
            dfs(x+1,cnt1,cnt2+1);
            ans2-=tmp;
        }
}
int main()
{
    scanf("%d",&n);
    m=n*2;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            scanf("%lld",&a[i][j]);
    dfs(1,0,0);
    printf("%lld",ans);
    return 0;
}
