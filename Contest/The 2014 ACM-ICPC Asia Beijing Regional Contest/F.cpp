#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int n,m;
int ma[60][60];
LL dp[60][20];
LL ans;
void deal(int x,int y,int z)
{
    int s;
    memset(dp,0,sizeof dp);
    dp[0][0]=1;
    for(int i=1;i<=m;i++)
    {
        s=0;
        if(ma[i][x]) s+=1; 
        if(ma[i][y]) s+=2; 
        if(ma[i][z]) s+=4; 
        for(int j=0;j<8;j++)
        {
            dp[i][j^s]=MOD(dp[i][j^s]+dp[i-1][j]);
            dp[i][j]=MOD(dp[i][j]+dp[i-1][j]);
        }
    }
    ans+=dp[m][7];
}
int main()
{
    int T,cas=0;scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        memset(ma,0,sizeof ma);
        for(int i=1;i<=m;i++)
        {
            int tmp;
            scanf("%d",&tmp);
            ma[i][tmp]=1;
        }
        ans=0;
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                for(int k=1;k<=n;k++)
                    deal(i,j,k);
        printf("Case #%d: %lld\n",++cas,ans);
    }
    return 0;
}
