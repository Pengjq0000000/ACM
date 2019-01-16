#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF)
    {
        int ans=0;
        for (int i=0;i<n;i++)
        {
            LL tmp;scanf("%lld",&tmp);
            while (tmp)
            {
                if (tmp%256==97) ans++;
                tmp/=256;
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
