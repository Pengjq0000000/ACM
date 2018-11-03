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
        int n;scanf("%d",&n);
        LL res=0,tmp;
        for (int i=1;i<=n;i++)
        {
            scanf("%lld",&tmp);
            res=res^tmp;
        }
        for (int i=1;i<n;i++)
        {
            int u,v;scanf("%d%d",&u,&v);
        }
        if (res==0) puts("D");else puts("Q");
    }
    return 0;
}
