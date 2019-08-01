#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n,m;
int mi[30];
int e[30];
char dp[1<<26];
int ans;
int lowbit(int x){return x&(-x);}
int main()
{
    mi[0]=1;
    for(int i=1;i<=27;i++)
        mi[i]=mi[i-1]*2;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j) e[i]|=mi[j];
    for(int i=1;i<=m;i++)
    {
        int u,v;
        scanf("%d%d",&u,&v);
        e[u]^=mi[v];
        e[v]^=mi[u];
    }
    int s=1<<n;
    dp[0]=0;
	for(int i=1;i<s;i++)
    {
        int j=lowbit(i);
        j=__builtin_ctz(j);
        int k=i&e[j];
        dp[i]=max((int)(dp[k]+1),(int)dp[i^mi[j]]);
        ans=ans+dp[i];
        //printf("%d %d\n",i,dp[i]);
    }
    printf("%d\n",ans);
	return 0;
}
