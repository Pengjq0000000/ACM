#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
    while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
    ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
    while(ch=getchar(),(ch>='0'&&ch<='9'))
        aa=aa*10+ch-48;
    return (bb?(-aa):(aa));
}
const long long Mod=998244353;
int T,n,m;
char s[3010],t[3010],ss[3010],tt[3010];
long long C[3010][3010],dp[3010][3010],sum[3010][3010];
int main()
{
    int T;
    scanf("%d",&T);
    C[0][0]=1;
    C[1][1]=1;C[1][0]=1;
    for(int i=2;i<=3000;++i){
        C[i][0]=1;
        for(int j=1;j<=i;++j){
            C[i][j]=(C[i-1][j]+C[i-1][j-1])%Mod;
        }
    }
    //for(int i=1;i<=3000;++i)C[i][0]=0;
    while(T--){
        scanf("%d%d",&n,&m);
        scanf("%s",ss+1);
        scanf("%s",tt+1);
        for(int i=1;i<=n;++i){
            s[i]=ss[n+1-i];
        }
        for(int i=1;i<=m;++i){
            t[i]=tt[m+1-i];
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                sum[i][j]=dp[i][j]=0;
            }
        long long ans=0;
        for(int i=1;i<=n;++i){
            for(int j=1;j<=m;++j){
                if(s[i]==t[j]){
                    dp[i][j]=sum[i-1][j-1];
                }
                else if(s[i]>t[j]){
                    dp[i][j]=C[i-1][j-1];
                }
                sum[i][j]=(sum[i-1][j]+dp[i][j])%Mod;
                //cout<<s[i]<<t[j]<<" ";
                //cout<<"dp "<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
            }
            //cout<<endl;
            if(s[i]!='0')
                ans=(ans+dp[i][m])%Mod;
        }
        //cout<<ans<<endl;
        for(int k=1;k<=n;++k){
            if(ss[k]=='0')continue;
            if(k+m-1>n)break;
            for(int i=k+m;i<=n;++i){
                ans=(ans+C[n-k][i-k])%Mod;
            }
        }
        printf("%lld\n",ans);
    }
}
