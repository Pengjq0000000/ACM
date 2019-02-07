#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e4+7;
char s[maxn],t[maxn];
int main()
{
    scanf("%s",s);int ls=strlen(s);
    scanf("%s",t);int lt=strlen(t);
    int ans=0;
    for (int i=0;i<ls-lt+1;i++)
    {
        int flg=1;
        for (int j=0;j<lt;j++) 
            if (s[i+j]==t[j]) {flg=0;break;}
        if (flg) ans++;
    }
    printf("%d\n",ans);
    return 0;
}

