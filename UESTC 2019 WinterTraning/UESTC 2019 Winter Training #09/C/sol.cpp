#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6+7;

int n,m;
int t[maxn],a[maxn],color[maxn];
set<int>pos[maxn];


int lowbit(int x) {return x&(-x);}
void update(int x,int val)
{
    for (x;x<=n;x+=lowbit(x)) t[x]+=val;
}
int getsum(int x)
{
    int res=0;
    for (x;x>0;x-=lowbit(x)) res+=t[x];
    return res;
}

void unite(int small,int big)
{
    if (pos[small].size()==0) return;
    for (int p:pos[small])
    {
        if (a[p+1]==big) update(p+1,-1);
        if (a[p-1]==big) update(p,-1);
    }
    for (int p:pos[small]) 
    {
        pos[big].insert(p);
        a[p]=big;
    }
    pos[small].clear();
}


int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d",&n,&m);
        MEM(t,0);a[0]=-1;
        for (int i=1;i<maxn;i++) 
        {
            pos[i].clear();color[i]=i;
        }
        for (int i=1;i<=n;i++) 
        {
            scanf("%d",&a[i]);
            if (a[i]!=a[i-1]) update(i,1);
            pos[a[i]].insert(i);
        }
        while (m--)
        {
            int op,x,y;scanf("%d%d%d",&op,&x,&y);
            if (op==1)
            {
                if (x==y) continue;
                if (pos[color[x]].size()>pos[color[y]].size()) swap(color[x],color[y]);
                unite(color[x],color[y]);
            }
            else if (op==2)
            {
                int ans=getsum(y)-getsum(x-1);
                if (a[x]==a[x-1]) ans++;
                printf("%d\n",ans);
            }
        }
    }
    return 0;
}

