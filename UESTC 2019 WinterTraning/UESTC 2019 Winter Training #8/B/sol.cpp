#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
int a[maxn],sum[507][507];
int main()
{
    int n,T;scanf("%d%d",&n,&T);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    int up=min(350,n);
    for (int q=0;q<=up;q++)
    {
        for (int p=1;p<=up;p++)
        {
            int now=q,tmp=0;
            while (now<n)
            {
                tmp+=a[now];
                now+=p;
            }
            sum[p][q]=tmp;
        }
    }
    while (T--)
    {
        int p,q;scanf("%d%d",&q,&p);
        if (p<=up) printf("%d\n",sum[p][q]);
        else
        {
            int ans=0;
            int now=q;
            while (now<n) {ans+=a[now];now+=p;}
            printf("%d\n",ans);
        }
    }
    return 0;
}

