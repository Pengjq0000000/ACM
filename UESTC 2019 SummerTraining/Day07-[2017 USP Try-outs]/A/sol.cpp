#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n,m,k;
int tot=0;
int last[50001];
int col[50001];
struct E
{
    int next,to;
} e[1000001];
void add(int u,int v){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
}
void dfs(int u){
    for(int i=last[u];i;i=e[i].next){
        int v=e[i].to;
        if(col[v]==-1){
            col[v]=(col[u]+1)%k;
            dfs(v);
        }
    }
}
int main()
{
    int u,v;
	scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        add(u,v);add(v,u);
    }
    if(k==1&&m!=0){
        puts("-1");
        return 0;
    }
    memset(col,-1,sizeof col);
    for(int i=1;i<=n;++i){
        if(col[i]!=-1)continue;
        col[i]=0;
        dfs(i);
    }
    for(int i=1;i<=n;++i)
        printf("%d\n",col[i]+1);
	return 0;
}
/*
3 3 3
1 2
2 3
1 3
 */