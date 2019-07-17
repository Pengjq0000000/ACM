#include<bits/stdc++.h>
using namespace std;
long long aa;bool bb;char ch;
long long scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
int n,m,tot=1,last[4100],s,t;
struct E{
	int from,to,next,cost;
	long long flow;
} e[50000];
const long long Inf=(1LL<<60);
long long dist[4100],ans;
int pre[4100],vis[4100],q[401000],head,tail;
int b[4100];
void add(int u,int v,long long f,int w){
	e[++tot].next=last[u];
	last[u]=tot;
	e[tot].from=u;
	e[tot].to=v;
	e[tot].flow=f;
	e[tot].cost=w;
	e[++tot].next=last[v];
	last[v]=tot;
	e[tot].from=v;
	e[tot].to=u;
	e[tot].flow=0;
	e[tot].cost=-w;
}
bool SPFA()
{
	int u,v,i;  
    for(i=0;i<=t+1;++i) 
    {
        pre[i]=-1;
		vis[i]=0;
		dist[i]=Inf; 
	}
    dist[s]=0;
	vis[s]=1;
	q[1]=s;
	head=0;
	tail=1;
    while(head<tail)  
    {
        u=q[++head];
        
        for(i=last[u];i;i=e[i].next)  
        {
            v=e[i].to;
            
            if(e[i].flow>0&&dist[u]+e[i].cost<dist[v])  
            {
                dist[v]=dist[u]+e[i].cost;  
                pre[v]=i;
                if(!vis[v])  
                {
                    vis[v]=1;  
                    q[++tail]=v;  
                }
            }  
        }  
        vis[u]=0;  
    }
    return (dist[t]!=Inf);  
}
int main(){
	int u,v,c;
	scanf("%d%d",&n,&m);
	s=4010,t=4011;
	for(int i=1;i<=n;++i){
		scanf("%d",&b[i]);
		add(i+1,i,Inf,0);
	}
	for(int i=1;i<=n+1;++i){
		if(b[i]>b[i-1])
			add(s,i,b[i]-b[i-1],0);
		else
			add(i,t,b[i-1]-b[i],0);
	}
	for(int i=1;i<=m;++i){
		scanf("%d%d%d",&u,&v,&c);
		add(u,v+1,Inf,c);
	}
	while(SPFA())
	{
		long long tmp=Inf;
		for(int i=pre[t];i>0;i=pre[e[i].from])
			if(tmp>e[i].flow)
				tmp=e[i].flow;
		for(int i=pre[t];i>0;i=pre[e[i].from])
		{
			e[i].flow-=tmp;
			e[i^1].flow+=tmp;
			ans+=tmp*e[i].cost;
		}
	}
	cout<<ans<<endl;
}
