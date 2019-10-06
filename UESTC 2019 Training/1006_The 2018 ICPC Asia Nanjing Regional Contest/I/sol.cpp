#include<bits/stdc++.h>
using namespace std;
struct E{
    int to,flow,next;
} e[750010];
int last[2010],cur[2010],vis[2010],d[2010],q[2010];
int head,tail;
int n,m,k,s,t,poi;
int ans=0;
const int INF=1000000;
int tot;
void add(int u,int v,int f){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
    e[tot].flow=f;
    
    e[++tot].next=last[v];
    last[v]=tot;
    e[tot].to=u;
    e[tot].flow=0;
}
bool BFS(){
    int u,v;
    memset(vis,0,sizeof vis);
    q[1]=s;
    d[s]=0;
    vis[s]=1;
    head=0,tail=1;
    while(head<tail){
        u=q[++head];
        for(int i=last[u];i;i=e[i].next){
            v=e[i].to;
            if(!vis[v]&&e[i].flow>0){
                vis[v]=1;
                d[v]=d[u]+1;
                q[++tail]=v;
            }
        }
    }
    return vis[t];
}
int DFS(int u,int a){
    int v;
    if(u==t||a==0) return a;
    int f,flow=0;
    if(cur[u]==0)
        cur[u]=last[u];
    for(int& i=cur[u];i;i=e[i].next){
        v=e[i].to;
        if(d[u]+1==d[v]&&(f=DFS(e[i].to,min(a,e[i].flow)))>0){
            e[i].flow-=f;
            e[i^1].flow+=f;
            flow+=f;
            a-=f;
            if(a==0) break;
        }
    }
    return flow;
}
int main()
{
    int num,u,v;
    scanf("%d%d%d",&n,&m,&k);
    tot=1;
    s=n+m+1;
    poi=s+1;
    t=poi+1;
    add(s,poi,k);
    for(int i=1;i<=n;++i){
        add(s,i,1);
        add(poi,i,1);
        scanf("%d",&num);
        for(int j=1;j<=num;++j){
            scanf("%d",&u);
            add(i,u+n,1);
        }
    }
    for(int i=1;i<=m;++i)
        add(i+n,t,1);
    while(BFS()){
        memset(cur,0,sizeof cur);
        ans+=DFS(s,INF);
    }
    cout<<ans<<endl;
}
