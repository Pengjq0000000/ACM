#include <bits/stdc++.h>
#define MAXN 17000005
using namespace std;
 
char a[MAXN*2];
int n,k;long long dp[MAXN*2],ans;
 
int main()
{
    k=300;
    scanf("%s",a);
    n=strlen(a);
    dp[(a[0]-'0')%k]=1;
    for (int i=1;i<n;i++)
    {
        ++dp[i*k+(a[i]-'0')%k];
        for (int j=0;j<k;j++) dp[i*k+(j*10+a[i]-'0')%k]+=dp[(i-1)*k+j];
    }
    for (int i=0;i<n;i++) ans+=dp[i*k];
    printf("%lld\n",ans);
    return 0;
}
