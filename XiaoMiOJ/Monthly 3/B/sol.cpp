#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
#include <map>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define max(a,b) (a>b?a:b)
using namespace std;
const int maxn=250005;
struct node {
    int x,y,l;
}k[maxn];
int t,m,n,lm,d[4][2]={1,0,-1,0,0,1,0,-1};
char mm[105][105];
void add(int u,int v,int w){
    k[lm].x=u;
    k[lm].y=v;
    k[lm].l=w;
    lm++;
}
void bfs(int s,int x,int y){
    node a,b;
    a.x=x,a.y=y,a.l=0;
    int vis[105][105]={0};
    vis[a.x][a.y]=1;
    queue<node>qu;
    qu.push(a);
    while(!qu.empty()){
        a=qu.front();
        qu.pop();
        if((mm[a.x][a.y]>='1'&&mm[a.x][a.y]<='9')||mm[a.x][a.y]=='S'){
            if(a.l)add(s,a.x*100+a.y,a.l);
        }
        b.l=a.l+1;
        for(int i=0;i<4;i++){
            b.x=a.x+d[i][0];
            b.y=a.y+d[i][1];
            if(b.x>=0&&b.x<n&&b.y>=0&&b.y<m&&!vis[b.x][b.y]&&mm[b.x][b.y]!='#'){
                vis[b.x][b.y]=1;
                qu.push(b);
            }
        }
    }
}
void make_adge(){
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            if(mm[i][j]!='#'&&mm[i][j]!='.')
                bfs(i*100+j,i,j);
}

int r[10005];
int fi(int n){
    return r[n]=r[n]==n?n:fi(r[n]);
}
int cmp(node x,node y){
    return x.l<y.l;
}
void solve(){
    int vis[10005];
    for(int i=0;i<10000;i++){
        r[i]=i;
        vis[i]=0;
    }
    sort(k,k+lm,cmp);
    int out=0;
    for(int i=0;i<lm;i++){
        int fx=fi(k[i].x);
        int fy=fi(k[i].y);
        if((mm[k[i].x/100][k[i].x%100]-'0')+2==vis[k[i].x])continue ;
        if((mm[k[i].y/100][k[i].y%100]-'0')+2==vis[k[i].y])continue ;
        if(mm[k[i].x/100][k[i].x%100]=='S'&&vis[k[i].x])continue;
        if(mm[k[i].y/100][k[i].y%100]=='S'&&vis[k[i].y])continue;
        if(fx!=fy){
            r[fx]=fy;
            vis[k[i].x]++;
            vis[k[i].y]++;
            out+=k[i].l;
            printf("%d %d -> %d %d\n", k[i].x/100, k[i].x%100, k[i].y/100, k[i].y%100);
        }
    }
    int ans=0;
    for(int i=0;i<10000;i++){
        if((mm[i/100][i%100]>='1'&&mm[i/100][i%100]<='9')||mm[i/100][i%100]=='S'){
            if(fi(i)==i){
                ans++;
            }
        }
    }
    if(ans!=1)out=-1;
    cout<<out<<endl;
}
int main(){
//    freopen("test0.in","r",stdin);
//  freopen("out.txt","w",stdout);
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        memset(mm,0,sizeof(mm));
        for(int i=0;i<n;i++){
            scanf("%s",mm[i]);
        }
        lm=0;
        make_adge();
        solve();
    }
    return 0;
}

