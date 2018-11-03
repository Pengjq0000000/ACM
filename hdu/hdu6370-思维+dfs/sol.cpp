#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 1e5+7;

vector<int>G[maxn];
int wolf[maxn],sta[maxn],deg[maxn],nex[maxn];
int cnt,last,ans,n;
char s[20];
queue<int>q;

void dfs(int rt,int now,int last)
{
    deg[now]--;
    if (sta[now]==0) {cnt++;last=nex[now];}
    if (rt==now)
    {
        if (cnt==1) {ans++;wolf[last]=1;}
        return;
    }
    dfs(rt,nex[now],last);
}


void DFS(int u)
{
    for (int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if (u==v) continue;
        ans++;
        DFS(v);
    }
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%d",&n);
        MEM(wolf,0);MEM(deg,0);
        ans=0;
        for (int i=1;i<=n;i++) G[i].clear();
        for (int i=1;i<=n;i++)
        {   
            int v;
            scanf("%d %s",&nex[i],s);
            deg[nex[i]]++;
            if (s[0]=='v') {sta[i]=1;G[nex[i]].push_back(i);}
            else sta[i]=0;
        }
        for (int i=1;i<=n;i++)
            if (deg[i]==0) q.push(i);
        while (!q.empty())
        {
            int u=q.front();q.pop();
            deg[nex[u]]--;
            if (deg[nex[u]]==0 && nex[u]!=u) q.push(nex[u]);
        }
        for (int i=1;i<=n;i++)
        {
            if (deg[i]>0 && i!=nex[i]) 
            {
                cnt=0;last=-1;
                dfs(i,nex[i],last);
            }
        }
        for (int i=1;i<=n;i++)
        {
            if (wolf[i]) DFS(i);
        }
        printf("0 %d\n",ans);
    }   
    return 0;
}





