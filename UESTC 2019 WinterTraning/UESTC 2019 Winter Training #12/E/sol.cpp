#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int INF = 1e9+7;
int a[20];
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        for (int i=0;i<n;i++) scanf("%d",&a[i]);
        int ans=INF,tot=0;
        for (int i=1;i<=1000000;i++)
        {
            sort(a,a+n);
            int mx=a[n-1],mi=a[0];
            if (mx==mi)
            {
                ans=mx;break;
            }
            a[0]=a[n-1]=mx-mi;
        }
        if (ans==INF) puts("Nooooooo!");
        else printf("%d\n",ans);
    }
    return 0;
}

