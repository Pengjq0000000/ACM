#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n;
int a[60];
int s,v=50;
int dp[2600][60];
void dfs(int s,int v)
{
    bool sign=1;
    if(v*n<s){
        if(dp[s-1][v]==-1) dfs(s-1,v);
        if(dp[s-1][v]==0){
            dp[s][v]=1;
            return;
        }
    }
    if(v>0){
        if(dp[s-1][v-1]==-1) dfs(s-1,v-1);
        if(dp[s-1][v-1]==0){
            dp[s][v]=1;
            return;
        }
    }
    if(v>0){
        if(dp[s-n][v-1]==-1) dfs(s-n,v-1);
        if(dp[s-n][v-1]==0){
            dp[s][v]=1;
            return;
        }
    }
    dp[s][v]=0;
    return ;
}
int main()
{
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]),s+=a[i],v=min(v,a[i]);
    memset(dp,-1,sizeof dp);
    dp[1][0]=1; dp[0][0]=0;
    dfs(s,v);
    if(dp[s][v]==0) printf("Yayoi\n");
    else printf("Iori\n");
	return 0;
}
