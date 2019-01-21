#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
int val[10],cnt[10];
int main()
{
    int n;scanf("%d",&n);
    int ans=0;
    for (int i=1;i<=n;i++)
    {
        string s;cin>>s;
        if (s=="red") cnt[1]++;
        else if (s=="yellow") cnt[2]++,ans+=2;
        else if (s=="green") cnt[3]++,ans+=3;
        else if (s=="brown") cnt[4]++,ans+=4;
        else if (s=="blue") cnt[5]++,ans+=5;
        else if (s=="pink") cnt[6]++,ans+=6;
        else if (s=="black") cnt[7]++,ans+=7;
    }
    int mx=0;
    for (int i=7;i>=2;i--)
    {
        if (cnt[i]>0)
        {
            mx=i;break;
        }
    }
    while (cnt[1])
    {
        ans++;cnt[1]--;
        if (mx) ans+=mx;
        else break;
    }
    printf("%d\n",ans);
    return 0;
}
