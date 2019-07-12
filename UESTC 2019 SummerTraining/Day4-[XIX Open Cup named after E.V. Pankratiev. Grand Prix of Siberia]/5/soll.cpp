#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2007;
char mp[maxn][maxn];
int n, k;
struct edge
{
    int to,next;
}e[maxn * maxn*2];
int cnt;
int head[2007];
void ins(int u,int v)
{
    cnt++;
    e[cnt].to=v;
    e[cnt].next=head[u];
    head[u]=cnt;
}
int fa[2007];
int find(int x)
{
    return x==fa[x]?x:fa[x]=find(fa[x]);
}
int num;//并查集数量
int f[2007];//代表元
int done[2007];//代表元为i的并查集是否被遍历
bool vis[2007];
queue<int>q;
void BFS(int x,int dep)
{
    if(dep==19) return;
    int u;
    memset(vis,0,sizeof vis);
    vis[x]=1;
    q.push(x);
    while (!q.empty())
    {
        u=q.front();
        q.pop();
        for(int i=head[u];i;i=e[i].next)
        {
            int v=e[i].to;
            if(vis[v]) continue;
            vis[v]=1;
            q.push(v);
        }
    }
    f[num]=u;
    BFS(u,dep+1);
}
int kk;
vector<int>s[2005];
void gz(int x)
{
    memset(vis,0,sizeof vis);
    s[++kk].push_back(x);
    vis[x]=1;
    int sign=1;
    while(sign)
    {
        int kkk=kk;
        int siz=s[kkk].size();
        sign=0;
        for(int i=0;i<siz;i++)
        {
            int u=s[kkk][i];
            for(int j=head[u];j;j=e[j].next)
            {
                int v=e[j].to;
                if(vis[v]) continue;
                if(!sign) sign=1,kk++;
                vis[v]=1;
                s[kk].push_back(v);
            }
        }
    }
}
int main()
{
	scanf("%d%d", &n, &k);
    for(int i=1;i<=n;i++)
        fa[i]=i;
    for (int i = 1; i <= n; i++) 
        for (int j = 1; j <= n; j++)
        {
            scanf(" %c", &mp[i][j]);
            if(mp[i][j]=='1')
            {
                ins(i,j),ins(j,i);
                int u = find(i), v = find(j);
                if (u > v) swap(u, v);
                fa[v] = u;
            }
        }
    for(int i=1;i<=n;i++)
    {
       if (done[find(i)]) continue;
       done[fa[i]] = 1;
       num++;
       BFS(fa[i],1);
    }
    for(int i=1;i<=num;i++) gz(f[i]);
    if(kk<k)
    {
        printf("Nope\n");
        return 0;
    }
    else printf("Yep\n");
    for(int i=1;i<=kk;i++)
    {
        int siz=s[i].size();
        if(i<k) printf("%d",siz);
        else if(i==k) 
        {
            int tmp=siz;
            for(int j=k+1;j<=kk;j++)
                tmp+=s[j].size();
            printf("%d",tmp);
        }
        for(int j=0;j<siz;j++)
            printf(" %d",s[i][j]);
        if(i<k) printf("\n");
    }
	return 0;
}
