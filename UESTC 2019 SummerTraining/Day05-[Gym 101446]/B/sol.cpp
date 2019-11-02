#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000033
#define pb push_back
using namespace std;

int n,k,m;
int c[102][10];
int b[10];
int last,now;
long long dp[2][256][300];
int main()
{
    b[0]=1;
    for(int i=1;i<=9;i++)
        b[i]=b[i-1]*2;
	scanf("%d%d%d",&n,&k,&m);
    for(int i=1;i<=m;i++)
    {
        int x,y;
        scanf("%d%d",&x,&y);
        c[x][y]=-1;
    }
    dp[now][b[8]-1][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=7;j++)
        {
            last=now;
            now=!last;
            memset(dp[now],0,sizeof dp[now]);
            for(int s=0;s<b[8];s++)
            {
                int left=-1,lup=-1,up=-1,rup=1;
                int leftb=0,lupb=0,upb=0,rupb=0;
                int ss,sss;
                int ss1,ss2,ss3,ss4;
                if(j==1) up=s&b[0],ss=(s<<1)%b[8]+1,sss=(s<<1)%b[8];
                    else up=s&b[j],ss=s|b[j-1],sss=ss^b[j-1];
                if(j>1) left=s&b[j-2],lup=s&b[j-1];
                if(j<7)
                {
                    if(j==1) rup=s&b[j];
                    else rup=s&b[j+1];
                }
                if(j>1) leftb=b[j-2];
                lupb=b[j-1];
                upb=b[j];
                rupb=b[j+1];
                ss1=ss|leftb|upb;
                ss2=ss|leftb|lupb;
                ss3=ss|lupb|upb;
                ss4=ss|upb|rupb;
                int sign=0;
                if((j==1&&((s&b[7])==0))||(j>1&&((s&b[j-1])==0))) sign=1;
                if(j==1&&((s&b[7])==0)) continue;
                    else if(j>1&&((s&b[j-1])==0)&&((s&b[j-2])!=0)&&((s&b[j])!=0)) continue;
                for(int kk=0;kk<k;kk++)
                {
                    if(dp[last][s][kk]==0) continue;
                    //printf("%lld %d %d %d %d %d %d %d ",dp[last][s][kk],left,lup,up,rup,i,j,kk);
                    //printf("%d %d %d %d %d %d %d\n",ss,ss1,ss2,ss3,ss4,sss,sign);
                    if(left==0&&up==0&&sign==0)
                        dp[now][ss1][kk+1]=MOD(dp[now][ss1][kk+1]+dp[last][s][kk]);
                    if(left==0&&lup==0)
                        dp[now][ss2][kk+1]=MOD(dp[now][ss2][kk+1]+dp[last][s][kk]);
                    if(lup==0&&up==0)
                        dp[now][ss3][kk+1]=MOD(dp[now][ss3][kk+1]+dp[last][s][kk]);
                    if(up==0&&rup==0&&sign==0)
                        dp[now][ss4][kk+1]=MOD(dp[now][ss4][kk+1]+dp[last][s][kk]);
                    if(c[i][j]!=-1&&sign==0) dp[now][ss][kk]=MOD(dp[now][ss][kk]+dp[last][s][kk]);
                    if(sign==0) dp[now][sss][kk]=MOD(dp[now][sss][kk]+dp[last][s][kk]);
                    //printf("%lld %d\n",dp[now][ss][kk+1],ss);
                    //printf("%lld %d\n",dp[now][ss][kk],ss);
                    //printf("%d %d\n",i,j);
                }
                if(c[i][j]!=-1&&sign==0) dp[now][ss][k]=MOD(dp[now][ss][k]+dp[last][s][k]);
                    if(sign==0) dp[now][sss][k]=MOD(dp[now][sss][k]+dp[last][s][k]);
            }
        }
    }
    printf("%lld\n",dp[now][b[8]-1][k]);
	return 0;
}
