#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const double Inf=1e16;
const double eps = 1e-8;
const int MAXN=600;
inline double MIN(double u,double v){return u<v?u:v;}
struct E{
    int to,next,fr;
    double flow;
} e[100007];
int last[MAXN],tot;
void add(int u,int v,double flow){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
    e[tot].fr=u;
    e[tot].flow=flow;
}
int s,t;
int vis[MAXN],d[MAXN],q[1000000],head,tail;
int cur[MAXN];
int n,m;
bool BFS(){
    for(int i=1;i<=n+2;++i)
        vis[i]=d[i]=0;
    q[1]=s;
    head=0;tail=1;
    vis[s]=1;d[s]=0;
    while(head<tail){
        for(int i=last[q[++head]];i;i=e[i].next){
            if(!vis[e[i].to]&&e[i].flow>eps){
                vis[e[i].to]=1;
                d[e[i].to]=d[q[head]]+1;
                q[++tail]=e[i].to;
            }
        }
    }
    return vis[t];
}
double DFS(int u,double a){
    if(u==t||a==0) return a;
    double f,flow=0;
    for(int &i=cur[u];i;i=e[i].next){
        if(d[u]+1==d[e[i].to]&&(f=DFS(e[i].to,MIN(a,e[i].flow)))>eps){
            e[i].flow-=f;
            e[i^1].flow+=f;
            flow+=f;
            a-=f;
            if(a==0)break;

        }
    }
    return flow;
}
int u[10011],v[10011],a[10011],b[10011],c[10011],col[10000];
double ss[MAXN],tt[MAXN];
double ans;
void init(){
    tot=1;
    for(int i=1;i<=n+2;++i){
        last[i]=0;
        ss[i]=tt[i]=0;
    }
    ans=0;
    s=n+1;t=n+2;
}
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF){
        init();
        for(int i=1;i<=m;++i){
            scanf("%d%d%d%d%d",&u[i],&v[i],&a[i],&b[i],&c[i]);
            ss[u[i]]+=a[i]/4-(double)c[i]/6;
            tt[u[i]]+=c[i]/3-a[i]/4;
            ss[v[i]]+=a[i]/4-(double)c[i]/6;
            tt[v[i]]+=c[i]/3-a[i]/4;
            add(u[i],v[i],(double)c[i]/6+a[i]/4);
            add(v[i],u[i],(double)c[i]/6+a[i]/4);
            ans+=c[i]*2/3+a[i]/2;
            //cout<<ans<<endl;
        }
//cout<<ans<<endl;
        for(int i=1;i<=n;++i){
            if(ss[i]<-eps&&tt[i]<-eps){
                if(ss[i]<tt[i])
                {
                    ans-=ss[i];
                    add(i,t,Inf);add(t,i,0);
                }
                else
                {
                    ans-=tt[i];
                    add(s,i,Inf);add(i,s,0);
                }
                continue;
            }
            if(ss[i]>-eps&&tt[i]>-eps){
                {add(s,i,ss[i]);add(i,s,0);add(i,t,tt[i]);add(t,i,0);}
                continue;
            }
            if(ss[i]<-eps){ans-=ss[i];add(i,t,Inf);add(t,i,0);}
            if(tt[i]<-eps){ans-=tt[i];add(s,i,Inf);add(i,s,0);}
        }
//cout<<ans<<endl;
//cout<<tt[3]<<endl;
//for(int i=1;i<=n;++i)cout<<ss[i]<<" ";
//cout<<endl;

//for(int i=1;i<=n;++i)cout<<tt[i]<<" ";
//cout<<endl;
        while(BFS()){
            for(int i=1;i<=n+2;++i)
                cur[i]=last[i];
            ans-=DFS(s,Inf);
        }
        ans=(long long)(ans+0.1);
        /*
        ans=0;
        for(int i=2;i<=tot;++i){
            if(e[i].flow<eps)continue;
            if(e[i].fr==s){
                col[e[i].to]=1;
            }
            if(e[i].to==t){
                col[e[i].fr]=2;
            }
        }
        for(int i=1;i<=n;++i)cout<<col[i]<<" ";cout<<endl;
        long long ANS=0;
        for(int i=1;i<=m;++i){
            if(col[u[i]]!=col[v[i]])
                ANS+=b[i];
            else if(col[u[i]]==1)
                ANS+=a[i];
            else
                ANS+=c[i];
        }
*/
        printf("%lld\n",(long long )ans);
    }
	return 0;
}
