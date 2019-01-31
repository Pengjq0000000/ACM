#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;

char s[maxn];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%s",s);
        int L=strlen(s),ans=0;
        for (int head=0;head<L;head++)
        {
            int i=head+1;
            int p=2;
            while (1)
            {
                int j=i*p;
                int k=j*p;
                if (k>L) break;
                p++;
                if ((s[i-1]=='y' && s[j-1]=='r' && s[k-1]=='x') || (s[i-1]=='x' && s[j-1]=='r' && s[k-1]=='y')) ans++;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}

