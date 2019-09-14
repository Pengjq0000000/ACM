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
int q[200010],head,tail,vis[200010],sz[200010];
int fa[200010];
int deg[200010],ans,max_sz,maxdeg;
int n,m,k;
int last[200010];
struct E{
	int next,to;
} e[2000010];
int tot;
void add(int u,int v){
	e[++tot].to=v;
	e[tot].next=last[u];
	last[u]=tot;
}
int find(int u){
	if(fa[u]==u)
		return u;
	return fa[u]=find(fa[u]);
}
void bfs(int u){
	int v,x,y;
	head=0;tail=1;
	q[1]=u;
	while(head<tail){
		u=q[++head];
		vis[u]=1;
		for(int i=last[u];i;i=e[i].next){
			v=e[i].to;
			if(vis[v]||sz[v]==0) continue;
			x=find(u);
			y=find(v);
			if(sz[y]&&x!=y){
				fa[x]=y;
				sz[y]+=sz[x];
			}
			vis[v]=1;
			q[++tail]=v;
		}
	}
}
int main(){
	int T,tmp;
	scanf("%d",&T);
	while(T--){
		scanf("%d%d%d",&n,&m,&k);
		
		for(int i=1;i<=n;++i){
			fa[i]=i;
			sz[i]=1;
			vis[i]=0;
			last[i]=0;
			deg[i]=0;
		}
		tot=0;
		int u,v,y;
		for(int i=1;i<=m;++i){
			scanf("%d%d",&u,&v);
			add(u,v);
			add(v,u);
			++deg[u];++deg[v];
		}
		for(int i=1;i<=k;++i){
			sz[scan()]=0;
		}
		for(int i=1;i<=n;++i){
			if(!vis[i]&&sz[i])
				bfs(i);
		}
		/*
		for(int i=1;i<=n;++i){
			cout<<i<<" "<<find(i)<<" "<<sz[find(i)]<<endl;
		}
		*/
		ans=sz[find(1)];
		maxdeg=1;max_sz=0;
		bool flag;
		for(int i=1;i<=n;++i){
			if(sz[i]==0){
				tmp=0;
				flag=0;
				for(int j=last[i];j;j=e[j].next){
					y=find(e[j].to);
					if(y!=find(1))
						tmp+=sz[find(e[j].to)];	
					else flag=1;
				}
				//cout<<i<<" "<<tmp<<" "<<deg[i]<<endl;
				if(flag&&tmp*maxdeg>=max_sz*deg[i]){
					maxdeg=deg[i];
					max_sz=tmp;
				}
			}
		}
		printf("%.8lf\n",(double)ans+(double)max_sz/maxdeg);
	}
}
