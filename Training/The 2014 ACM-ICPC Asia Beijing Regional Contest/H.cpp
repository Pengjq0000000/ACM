#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int n,m,a;
long long dp[2][2048000];
long long ans;
int last=0,now;
int main()
{
    int t;
    scanf("%d",&t);
    int Case=0;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        int maxsum=0;
        dp[last][0]=1;
        now=last?0:1;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a);
            int tmp=maxsum;
            for(int j=0;j<=tmp;j++)
            {
                dp[now][j^a]+=dp[last][j];
                dp[now][j]+=dp[last][j];
                maxsum=max(maxsum,j^a);
                dp[last][j]=0;
            }
            last=now;
            now=last?0:1;
        }
        ans=0;
        for(int i=0;i<=maxsum;i++)
        {
            if(i>=m)
                ans+=dp[last][i];
            dp[last][i]=0;
        }
        printf("Case #%d: %lld\n",++Case,ans);
    }
    return 0;
}
