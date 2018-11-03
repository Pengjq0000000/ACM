#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int a[100007];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++) scanf("%d",&a[i]);
        int ans=sqrt(abs(a[1]-a[n]));
        printf("%d\n",ans);
    }
    return 0;
}
