#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int a[50005];
int b[50005];
int head;
int nxt[50005];
int pre[50005];
int ans[50005];
int del[50005];
int pos[50005];
set<int>v;
int p[50005];
int dp[50005];
int t;
int s[50005];
void ini()
{
    for(int i=1;i<=n;i++)
        del[i]=0;
    head=1;
    for(int i=1;i<=n;i++)
        pre[i]=i-1,nxt[i]=i+1;
}
void deal()
{
    t=0;
    for(int i=head;i<=n;i=nxt[i])
    {
        assert(del[i] == 0);
        if(del[i]) continue;
        int l=0,r=t,k;
        while(l<=r)
        {
            int m=(l+r)/2;
            if(s[m]<a[i]) k=m,l=m+1;
            else r=m-1;
        }
        dp[i]=k+1;
        p[i]=pos[s[k]];
        if(dp[i]>t)
        {
            s[++t]=a[i];
            v.clear();
            int x=i;
            do
            {
                v.insert(a[x]);
                x=p[x];
            }while(x);
        }
        else s[dp[i]]=min(s[dp[i]],a[i]);
    }
    //for(int i=0;i<v.size();i++)
    //    printf("%d ",v[i]);
    //printf("\n");
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            pos[a[i]]=i;
        }
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        deal();
        for(int i=n;i>=1;i--)
        {
            ans[i]=t;
            del[b[i]]=1;
            nxt[pre[b[i]]]=nxt[b[i]];
            pre[nxt[b[i]]]=pre[b[i]];
            while(del[head]) head=nxt[head];
            if(v.count(a[b[i]])) deal();
        }
        for(int i=1;i<n;i++)
            printf("%d ",ans[i]);
        printf("%d\n",ans[n]);
    }
    return 0;
}
