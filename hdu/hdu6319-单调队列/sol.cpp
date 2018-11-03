#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e7+7;

//deque<int>q;
int q[maxn],a[maxn];
LL A,B,p,qq,r,mod;
int n,m,k;

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        //q.clear();
        scanf("%d%d%d%lld%lld%lld%lld",&n,&m,&k,&p,&qq,&r,&mod);
        for (int i=1;i<=k;i++) scanf("%lld",&a[i]);
        for (int i=k+1;i<=n;i++) a[i]=((p*a[i-1])+(qq*i+r))%mod;
        int head=0,tail=0;
        for (int i=n;i>=n-m+1;i--)
        {
            while (head<tail && q[tail-1]<=a[i]) tail--;
            q[tail++]=a[i];
        }
        A=q[head]^(n-m+1);
        B=(tail-head)^(n-m+1);
        for (int i=n-m;i>=1;i--)
        {
            if (q[head]==a[i+m]) head++;
            while (head<tail && q[tail-1]<=a[i]) tail--;
            q[tail++]=a[i];
            A+=q[head]^i;
            B+=(tail-head)^i;
        }
        printf("%lld %lld\n",A,B);
    }
    return 0;
}
