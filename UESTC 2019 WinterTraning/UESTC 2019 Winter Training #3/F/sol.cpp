#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

const int maxn = 2e5+7;
struct node {int v,flow,nxt;}e[maxn];
int tot=1,head[maxn],dep[maxn];
// tot starting from 1
void add(int u,int v,int w)
{
    ++tot;
    e[tot].v=v;e[tot].flow=w;e[tot].nxt=head[u];
    head[u]=tot;
}

bool bfs(int S,int T)
{
    MEM(dep,0);
    dep[S]=1;
    queue<int>q;
    q.push(S);
    while (!q.empty())
    {
        int u=q.front();q.pop();
        for (int i=head[u];i;i=e[i].nxt)
        {
            int v=e[i].v;
            if (e[i].flow && !dep[v])
            {
                dep[v]=dep[u]+1;
                q.push(e[i].v);
            }
        }
    }
    return dep[T];
}

int aim;
int dfs(int now,int flow)
{
    if (now==aim) return flow;
    int f=0;
    for (int i=head[now];i;i=e[i].nxt)
    {
        int v=e[i].v;
        if (e[i].flow && dep[v]==dep[now]+1)
        {
            int x=dfs(v,min(flow,e[i].flow));
            e[i].flow-=x;e[i^1].flow+=x;flow-=x;f+=x;
        }
    }
    if (!f) dep[now]=-2;
    return f;
}

int maxflow(int S,int T)
{
    aim=T;int res=0;
    while (bfs(S,T)) res+=dfs(S,1<<30);
    return res;
}
int cnt[30];
int main()
{
    int n;scanf("%d",&n);

    int S=10000,T=10001;
    for (int i=1;i<=n;i++)
    {
        MEM(cnt,0);
        for (int j=1;j<=3;j++)
        {
            string s; cin>>s;
            int L=s.size();
            for(int j=0; j<L; j++) cnt[s[j]-'A']++;
        }
        int mx=0;
        for(int j=0; j<26; j++) mx=max(mx,cnt[j]);
        for(int j=0; j<26; j++)
            if(cnt[j]==mx)
            {
                //printf("%d ",j);
                add(j+2*n,i,1);
                add(i,j+2*n,0);
            }
        add(i,T,1);
        add(T,i,0);
        //printf("\n");
    }
    int k;scanf("%d",&k);

    for (int i=0;i<26;i++)
    {
        add(S,i+2*n,k);
        add(i+2*n,S,0);
    }

    printf("%d\n",maxflow(S,T));

    return 0;
}
