#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%100000073)
#define mod 100000073

using namespace std;

int a,b,n;
int A[5000005];
int dp[5000005];
int num[5000005];
int s[6505];
int t[6505];
int sum[6505][6505];
void solve()
{
    n=5000000;
    dp[0]=0;
    num[0]=1;
    dp[1]=1;
    num[1]=1;
    dp[2]=2;
    num[2]=2;
    dp[3]=2;
    num[3]=1;
    s[1]=1;
    t[1]=1;
    s[2]=2;
    t[2]=3;
    for(int k=3;k;k++)
    {
        bool sign=0;
        s[k]=(k-1)*k/2+1;
        t[k]=k*(k+1)/2;
        for(int i=s[k];i<=t[k];i++)
        {
            if(i>n)
            {
                sign=1;
                break;
            }
            dp[i]=k;
        }
        int cnt=0;
        for(int i=s[k-1]-1;i<=t[k-1];i++)
        {
            cnt++;
            sum[k][cnt]=MOD(sum[k][cnt-1]+num[i]);
        }
        for(int i=s[k];i<=t[k];i++)
        {
            if(i>n)
            {
                sign=1;
                break;
            }
            num[i]=MOD(sum[dp[i]][dp[i]]-sum[dp[i]][i-s[dp[i]]]+mod);
        }
        if(sign) break;
    }
    //for(int i=1;i<=100;i++)
    //printf("%d %d %d\n",i,dp[i],num[i]);
}
int main()
{
    solve();
    while(scanf("%d%d",&a,&b)!=EOF)
    {
        n=b-a+1;
        printf("%d %d\n",dp[n],num[n]);
    }
    return 0;
}
