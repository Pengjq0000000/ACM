#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n,ans=0;scanf("%d",&n);
        for (int i=0;i<n;i++)
        {
            int a,b;scanf("%d%d",&a,&b);
            ans+=a*b;
        }
        printf("%d\n",ans);
    }
    return 0;
}
