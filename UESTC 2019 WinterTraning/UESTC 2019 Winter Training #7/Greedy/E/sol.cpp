#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5+7;
struct node
{
    int t,level;
    bool operator < (const node &rhs) const
    {
        if (t==rhs.t) return level>rhs.level;
        return t>rhs.t;   
    }
}machine[maxn],task[maxn];

int vis[maxn];
int main()
{
    int n,m;
    while (scanf("%d%d",&n,&m)!=EOF)
    {
        for (int i=1;i<=n;i++) scanf("%d%d",&machine[i].t,&machine[i].level);
        for (int i=1;i<=m;i++) scanf("%d%d",&task[i].t,&task[i].level);
        sort(machine+1,machine+1+n);
        sort(task+1,task+1+m);
        MEM(vis,0);
        LL tot=0,ans=0;
        int now=1;
        for (int i=1;i<=m;i++)
        {
            while (now<=n && machine[now].t>=task[i].t) vis[machine[now].level]++,now++;
            for (int lv=task[i].level;lv<=100;lv++)
                if (vis[lv])
                {
                    vis[lv]--;tot++;
                    ans+=500*task[i].t+2*task[i].level;
                    break;
                }
        }
        printf("%lld %lld\n",tot,ans);
    }
    return 0;
}

