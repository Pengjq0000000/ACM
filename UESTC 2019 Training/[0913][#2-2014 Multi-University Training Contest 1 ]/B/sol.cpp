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
const int Inf=1000000000;
int s,t,n,m,k;
char mp[100][100];
int ans;
int pre[1000],vis[1000],dist[1000];
int tot,last[1000];
struct E{
	int from,to,cost,flow,next;
} e[100000];
int q[100000],head,tail;
void add(int u,int v,int f,int c){
	++tot;
	e[tot].next=last[u];
	last[u]=tot;
	e[tot].from=u;
	e[tot].to=v;
	e[tot].flow=f;
	e[tot].cost=c;
	++tot;
	e[tot].next=last[v];
	last[v]=tot;
	e[tot].from=v;
	e[tot].to=u;
	e[tot].flow=0;
	e[tot].cost=-c;
}
int SPFA()
{
	int u,v,i;  
    for(i=0;i<=t+1;++i) 
    {
        pre[i]=-1;
		vis[i]=0;
		dist[i]=-Inf; 
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
            
            if(e[i].flow>0&&dist[u]+e[i].cost>dist[v])  
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
    return dist[t];  
}

int main(){
	int T,tmp;
	scanf("%d",&T);
	for(int cas=1;cas<=T;++cas){
		ans=0;
		scanf("%d%d%d",&n,&m,&k);
		for(int i=0;i<n;++i){
			scanf("%s",mp[i]);
		}
		s=n*m*2;
		t=s+1;
		tot=1;
		memset(last,0,sizeof last);
		for(int i=0;i<n*m;++i){
			add(s,i,1,0);
			add(i+n*m,t,1,0);
		}
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				for(int x=j+1;x<m;++x){
					tmp=x-j-1-(mp[i][j]==mp[i][x]?mp[i][j]-'0':0);
					add(i*m+j,i*m+x+n*m,1,-tmp);
					//cout<<i*m+j<<" "<<i*m+x<<" "<<tmp<<endl;
				}
				for(int x=i+1;x<n;++x){
					tmp=x-i-1-(mp[i][j]==mp[x][j]?mp[i][j]-'0':0);
					add(i*m+j,x*m+j+n*m,1,-tmp);
					//cout<<i*m+j<<" "<<x*m+j<<" "<<tmp<<endl;
				}
			}
		}
		int cnt=0;
		while(cnt<n*m-k&&SPFA()!=-Inf)
		{
			++cnt;
			tmp=Inf;
			for(int i=pre[t];i>0;i=pre[e[i].from])
				if(tmp>e[i].flow)
					tmp=e[i].flow;
			for(int i=pre[t];i>0;i=pre[e[i].from])
			{
				//cout<<e[i].from<<" "<<e[i].to<<endl;
				e[i].flow-=tmp;
				e[i^1].flow+=tmp;
				ans+=tmp*e[i].cost;
			}
			//cout<<cnt<<" "<<ans<<endl;
		}
		//cout<<cnt<<endl;
		if(cnt<n*m-k){
			printf("Case %d : -1\n",cas);
		}
		else{
			while(SPFA()>0){
				tmp=Inf;
				for(int i=pre[t];i>0;i=pre[e[i].from])
					if(tmp>e[i].flow)
						tmp=e[i].flow;
				for(int i=pre[t];i>0;i=pre[e[i].from])
				{
					//cout<<e[i].from<<" "<<e[i].to<<endl;
					e[i].flow-=tmp;
					e[i^1].flow+=tmp;
					ans+=tmp*e[i].cost;
				}
			}
			printf("Case %d : %d\n",cas,ans);
		}
	}
}