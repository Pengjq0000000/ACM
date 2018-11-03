#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int k,num[10],tmp[10],L,p[20],vis[10];
LL n,mx,mi;

int check()
{
    MEM(vis,0);
    int cnt =0;
    for(int i=0;i<L;++i)
    {
        if(vis[i]) continue;
        int tmp=0;
        while(!vis[i])
        {
            tmp++;
            vis[i]=1;
            i = p[i];
        }
        cnt += tmp-1;
        if(cnt>k) return 0;
    }
    return cnt;
}
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        L=0;
        scanf("%lld%d",&n,&k);
        mx=mi=n;
        while (n)
        {
            num[++L]=n%10;
            n/=10;
        }
        for (int i=1;i<=L/2;i++) swap(num[i],num[L-i+1]);
        {
            for (int i=0;i<L;i++) p[i]=i;
            do
            {
                if (num[p[0]+1]==0 || !check()) continue;
                LL res=0;
                for (int i=0;i<L;i++)
                {
                    res=res*10+num[p[i]+1];
                }
                mi=min(mi,res);
                mx=max(mx,res);
            }while (next_permutation(p,p+L));
            printf("%lld %lld\n",mi,mx);
        }
    }
    return 0;
}

