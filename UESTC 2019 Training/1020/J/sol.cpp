#include<bits/stdc++.h>
using namespace std;
int dep,sum[100010],lastpos[100010];
long long ans[100010];
int n,p[100010],a[100010];
int last[100010],tot;
struct E{
    int next,to;
} e[100010];
void add(int u,int v){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
}
void dfs(int u){
    //cout<<u<<endl;
    ++dep;
    int tmp=lastpos[a[u]];
    if(!tmp){
        ans[u]+=sum[dep-1];
        lastpos[a[u]]=dep;
        sum[dep]=sum[dep-1]+1;
    }
    else{
        ans[u]+=sum[dep-1]-sum[tmp-1];
        lastpos[a[u]]=dep;
        sum[dep]=sum[dep-1];
    }
    for(int i=last[u];i;i=e[i].next){
        ans[e[i].to]+=ans[u];
        dfs(e[i].to);
    }
    lastpos[a[u]]=tmp;
    --dep;
}
int main(){
    //int a,b;
    //cin>>a>>b;
    //cout<<a+b<<endl;
    while(scanf("%d",&n)!=EOF){
        
        for(int i=1;i<=n;++i){
            last[i]=lastpos[i]=0;
            ans[i]=0;
            sum[i]=0;
        }
        tot=0;
        for(int i=2;i<=n;++i){
            scanf("%d",&p[i]);
            add(p[i],i);
        }
        
        for(int i=1;i<=n;++i){
            scanf("%d",&a[i]);
        }
        
        dfs(1);
        for(int i=2;i<=n;++i){
            printf("%lld\n",ans[i]);
        }
    }
}