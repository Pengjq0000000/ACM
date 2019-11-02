#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const LL INF = 1e10;
LL p,c[10],ans;
int val[10]={1,5,10,20,50,100,200,500,1000,2000};


void dfs(int now,LL p,LL cnt)
{
    if (p<0) return;
    if (now<0)
    {
        if (p==0) ans=min(ans,cnt);
        return;
    }
    LL num=min(c[now],p/val[now]);
    dfs(now-1,p-num*val[now],cnt+num);
    if (num>0) {num--;dfs(now-1,p-num*val[now],cnt+num);}
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%lld",&p);
        LL tot=0,all=0;
        for (int i=0;i<10;i++)
        {
            scanf("%lld",&c[i]);
            tot+=c[i]*val[i];
            all+=c[i];
        }
        ans=INF;
        dfs(9,tot-p,0);
        printf("%lld\n",ans==INF?-1:all-ans);
    }
    return 0;
}

