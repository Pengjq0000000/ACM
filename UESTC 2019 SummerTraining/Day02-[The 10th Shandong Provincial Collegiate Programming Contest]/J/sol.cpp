#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e6 + 7;
struct E
{
    int next,tox,toy,fromx,fromy,w;
} e[maxn];
int last[400][400];
int tot;
stack<int> Stack;
int n;
int T;
int a[400][400],b[400][400],c[400][400];
int cnt;
    long long ans;
bool used[maxn];
void add(int a,int b,int c,int d,int w){
    ++cnt;
    e[++tot].next=last[a][b];
    last[a][b]=tot;
    e[tot].fromx=a;
    e[tot].fromy=b;
    e[tot].tox=c;
    e[tot].toy=d;
    e[tot].w=w;
    used[tot]=0;
    e[++tot].next=last[c][d];
    last[c][d]=tot;
    e[tot].fromx=c;
    e[tot].fromy=d;
    e[tot].tox=a;
    e[tot].toy=b;
    e[tot].w=w;
    used[tot]=0;
}
void Euler(int x,int y){
    int u,v,tmp,i;
    u=x;v=y;
    //cout<<"DEBUG::"<<last[1][1]<<endl;
    while(1){
        while(last[u][v]){
            i=last[u][v];
            if(used[i]){
                last[u][v]=e[i].next;
                continue;
            }
            used[i]=used[i^1]=1;
            Stack.push(i);
            last[u][v]=e[i].next;
            u=e[i].tox;v=e[i].toy;
        }
        printf("%d %d",u,v);
        if(u!=n||v!=n) printf(" ");
        if(Stack.empty()) break;
        tmp=Stack.top();
        u=e[tmp].fromx;
        v=e[tmp].fromy;
        Stack.pop();
    }
    printf("\n");
}
long long dist[400][400];
bool vis[400][400];
struct Node{
    int Px,Py;
    long long key2;
    bool operator >(const Node &a)const{
        return key2>a.key2;
    }
};
priority_queue<Node,vector<Node>,greater<Node> > Q;
void Dijk(){
    Q.push((Node){1,1,0});
    dist[1][1]=0;
    vis[1][1]=1;
    Node u;
    while(!Q.empty()){
        u=Q.top();
        Q.pop();
        if(vis[u.Px][u.Py])
            continue;
        vis[u.Px][u.Py]=1;
        for(int i=last[u.Px][u.Py];i;i=e[i].next){
            if(dist[e[i].tox][e[i].toy]>u.key2+e[i].w){
                dist[e[i].tox][e[i].toy]=u.key2+e[i].w;
                Q.push((Node){e[i].tox,e[i].toy,dist[e[i].tox][e[i].toy]});
            }
        }
    }
    ans-=dist[n][n];
    int x=n,y=n;
    while(1){
        if(x==1)
            break;
        for(int i=last[x][y];i;i=e[i].next){
            if(dist[e[i].tox][e[i].toy]==dist[x][y]+e[i].w){
                used[i]=used[i^1]=1;
                x=e[i].tox;
                y=e[i].toy;
                --cnt;
                break;
            }
        }
    }
}
int main()
{
    int tmp;
	scanf("%d",&T);
    while(T--){
        tot=1;
        cnt=1;
        //memset(last,0,sizeof last);
        scanf("%d",&n);
        ans=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=i;++j)
            {
                last[i][j]=0;
                dist[i][j]=1e17;
                vis[i][j]=0;
            }
        for(int i=1;i<n;++i){
            for(int j=1;j<=i;++j){
                scanf("%d",&a[i][j]);
                ans+=a[i][j];
                add(i,j,i+1,j,a[i][j]);
            }
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<=i;++j){
                scanf("%d",&b[i][j]);
                ans+=b[i][j];
                add(i,j,i+1,j+1,b[i][j]);
            }
        }
        for(int i=1;i<n;++i){
            for(int j=1;j<=i;++j){
                scanf("%d",&c[i][j]);
                ans+=c[i][j];
                add(i+1,j,i+1,j+1,c[i][j]);
            }
        }
        Dijk();
        printf("%lld\n%d\n", ans, cnt);
        Euler(n,n);
    }
	return 0;
}
