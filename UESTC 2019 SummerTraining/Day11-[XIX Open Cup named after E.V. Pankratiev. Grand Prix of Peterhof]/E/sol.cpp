#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int x,y;
double dp[2][2000010];
int main()
{
	scanf("%d%d",&x,&y);
    for(int i=x+y;i;--i){
        if(i>x){
            dp[1][i]=1;
            dp[0][i]=0;
            continue;
        }
        if(i*2>x+y){
            dp[1][i]=0;
            dp[0][i]=1;
            continue;
        }
        if(i*2==x+y){
            dp[1][i]=dp[0][i]=0.5;
            continue;
        }
        dp[1][i]=dp[1][i<<1]*dp[1][i<<1|1]*0.75;
        dp[1][i]+=dp[1][i<<1]*dp[0][i<<1|1]*0.5;
        dp[1][i]+=dp[0][i<<1]*dp[1][i<<1|1]*0.25;
        dp[0][i]=1-dp[1][i];
    }
    printf("%.8lf",dp[1][1]);
	return 0;
}
