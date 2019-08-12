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
int s,t,n,m;
const int Inf=100000000;
struct E{
	int next,to,flow,id;
} e[800010],e2[800010];
int tot=1,tot2=0;
int vis[200010],q[2000100],d[200010],head,tail;
int last[200010],last2[200010],cur[200010];
int send[200010],ans[200010];
int Dec[200010],inc[200010],now[200010];
int used[200010];
int Min(int u,int v){return u<v?u:v;}
void add(int u,int v,int f,int id){
	e[++tot].next=last[u];
	last[u]=tot;
	e[tot].to=v;
	e[tot].flow=f;
	e[tot].id=id;
	e[++tot].next=last[v];
	last[v]=tot;
	e[tot].to=u;
	e[tot].flow=0;
	e[tot].id=id;
}
void add2(int u,int v){
	e2[++tot2].next=last2[u];
	last2[u]=tot2;
	e2[tot2].to=v;
}
bool BFS()
{
	memset(vis,0,sizeof(vis));
	q[1]=s;
	d[s]=0;
	vis[s]=1;
	head=0;
	tail=1;
	while(head<tail)
	{
		for(int i=last[q[++head]];i;i=e[i].next)
		{
			if(!vis[e[i].to]&&e[i].flow>0)
			{
				vis[e[i].to]=1;
				d[e[i].to]=d[q[head]]+1;
				q[++tail]=e[i].to;
			}
		}
	}
	return vis[t];
}
int DFS(int u,int a)
{
	if(u==t||a==0)
		return a;
	int f,flow=0;
	//if(cur[u]==0)
	//	cur[u]=last[u];
	for(int& i=cur[u];i;i=e[i].next)
	{
		if(d[u]+1==d[e[i].to]&&(f=DFS(e[i].to,Min(a,e[i].flow)))>0)
		{
			e[i].flow-=f;
			e[i^1].flow+=f;
			flow+=f;
			a-=f;
			if(a==0)
				break;
		}
	}
	return flow;
}
void dfs3(int u){
	//cout<<"do::"<<u-n+1<<endl;
	for(int i=last2[u];i;i=e2[i].next){
		dfs3(e2[i].to);
		ans[Dec[e2[i].to]]=n-1-now[e2[i].to];
		ans[inc[e2[i].to]]=n-(n-1-now[e2[i].to]);
		now[u]+=1+now[e2[i].to];
	}
}
void dfs2(int u){
	for(int i=last[u];i;i=e[i].next){
		if(e[i].to<n&&!used[e[i].to]){
			add2(u,send[e[i].to]);
			//cout<<u-n+1<<" "<<send[e[i].to]-n+1<<endl;
			used[e[i].to]=1;
			for(int j=last[e[i].to];j;j=e[j].next){
				if(e[j].to==send[e[i].to]) Dec[send[e[i].to]]=e[j].id;
				if(e[j].to==u) inc[send[e[i].to]]=e[j].id;
			}
			dfs2(send[e[i].to]);
		}
	}
}
int main(){
	int u,v,ret=0;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=m;++i){
		u=scan();v=scan();
		//scanf("%d%d",&u,&v);
		add(u,v+n-1,1,i);
	}
	s=n+n;t=s+1;
	for(int i=1;i<n;++i){
		add(s,i,1,0);
		add(i+n-1,t,1,0);
	}
	while(BFS())
	{
		memcpy(cur,last,sizeof(cur));
		ret+=DFS(s,Inf);
	}
	if(ret!=n-1){
		puts("-1");
		return 0;
	}
	for(int u=1;u<n;++u){
		for(int i=last[u];i;i=e[i].next){
			if(e[i].to!=s&&e[i].flow==0){
				send[u]=e[i].to;
			}
		}
	}
	//for(int i=1;i<n;++i)cout<<"send::"<<send[i]-n+1<<endl;
	dfs2(n+n-1);
	dfs3(n+n-1);
	if(tot2!=n-1){
		puts("-1");
		return 0;
	}
	for(int i=1;i<=m;++i){
		printf("%d\n",ans[i]);
	}
}
