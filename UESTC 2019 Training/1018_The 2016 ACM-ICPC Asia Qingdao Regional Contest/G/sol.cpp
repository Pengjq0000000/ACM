#include<bits/stdc++.h>
#define eps 1e-6
using namespace std;
struct E{
    int from,to,flow,next;
    double cost;
} e[100100];
int tot,last[110];
int head,tail,q[1000010];
int pre[110],vis[110];
double dis[110];
int s,t,n,m;
const double Inf=1000000000;
void add(int u,int v,int f,double c){
    e[++tot].from=u;
    e[tot].to=v;
    e[tot].next=last[u];
    e[tot].flow=f;
    e[tot].cost=c;
    last[u]=tot;
    e[++tot].from=v;
    e[tot].to=u;
    e[tot].next=last[v];
    e[tot].flow=0;
    e[tot].cost=-c;
    last[v]=tot;
}
bool SPFA(){
    int u,v,i;
    for(i=0;i<=t+1;++i)
    {
        pre[i]=vis[i]=0;
        dis[i]=-Inf;
    }
    dis[s]=0;vis[s]=1;q[1]=s;
    head=0;tail=1;
    while(head<tail){
        u=q[++head];
        for(i=last[u];i;i=e[i].next){
            v=e[i].to;
            if(e[i].flow>0&&dis[u]+e[i].cost>dis[v]){
                dis[v]=dis[u]+e[i].cost;
                //cout<<u<<" "<<v<<" "<<dis[v]<<endl;
                pre[v]=i;
                if(!vis[v]){
                    vis[v]=1;
                    q[++tail]=v;
                }
            }
        }
        vis[u]=0;
    }
    return dis[t]!=-Inf;
}
int main(){
    int u,v,c;
    double p;
    double ans;
    int T;
    scanf("%d",&T);
    while(T--){
        tot=1;
        scanf("%d%d",&n,&m);
        s=n+1;t=s+1;
        for(int i=0;i<=t+1;i++) last[i]=0;
        for(int i=1;i<=n;++i){
            scanf("%d%d",&u,&v);
            if(u>v)
                add(s,i,u-v,0);
            if(v>u)
                add(i,t,v-u,0);
        }
        for(int i=1;i<=m;++i){
            scanf("%d%d%d%lf",&u,&v,&c,&p);
            if(c<1)continue;
            add(u,v,1,0);
            if(c>1)
                add(u,v,c-1,log(1-p));
        }
        ans=0;
        int tmp;
        while(SPFA()){
            tmp=Inf;
            for(int i=pre[t];i>0;i=pre[e[i].from])
                if(tmp>e[i].flow)
                    tmp=e[i].flow;
            for(int i=pre[t];i>0;i=pre[e[i].from]){
                e[i].flow-=tmp;
                e[i^1].flow+=tmp;
                ans+=e[i].cost*tmp;
            }
            //cout<<"tmp:"<<tmp<<endl;
        }
        //cout<<ans<<endl;
        printf("%.2lf\n",1-exp(ans));
    }
}