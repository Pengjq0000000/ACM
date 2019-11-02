#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 30;
int day[maxn],R[maxn],T[maxn];
int main()
{
    int n;scanf("%d",&n);
    int L=0;
    
    for (int i=1;i<=n;i++) 
    {
        scanf("%d%d%d",&day[i],&R[i],&T[i]);
        L=max(day[i],L);
        //if (R[i]>T[i]) swap(R[i],T[i]);
    }
    int ans=-1;
    for (int now=0;now<1825*L;now++)
    {
        int cnt=0;
        for (int i=1;i<=n;i++)
        {
            int tmp=now%day[i];
            if (R[i]<T[i])
            {
                if (tmp<=R[i] || tmp>=T[i]) cnt++;
            }
            else
            {
                if (tmp>=T[i] && tmp<=R[i]) cnt++;
            }
        }
        if (cnt==n)
        {
            ans=now;break;
        }
    }
    if (ans<0) printf("impossible");
    else printf("%d",ans);
    return 0;
}
