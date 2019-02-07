
#include<iostream>
#include<algorithm>
#include<cstring>
#include<cstdio>
#include<cmath>
#define LL long long
using namespace std;
const int mxn=100010;

struct edge{int v,nxt;}e[mxn<<1];
int hd[mxn],mct=0;
void add_edge(int u,int v){e[++mct].v=v;e[mct].nxt=hd[u];hd[u]=mct;}
//邻接表
struct node{
    int fa,son;
    int size,dep,top;
    int w,e;
}tr[mxn];
//树剖结点
struct segtree{
    LL smm,mk;
}st[mxn<<2];
int sz=0;
//线段树
int n,M,rt=1;
int w[mxn];//初始值
//
void DFS1(int u){
    tr[u].size=1;tr[u].son=0;
    for(int i=hd[u];i;i=e[i].nxt){
        int v=e[i].v;
        if(v==tr[u].fa)continue;
        tr[v].fa=u;
        tr[v].dep=tr[u].dep+1;
        DFS1(v);
        tr[u].size+=tr[v].size;
        if(tr[v].size>tr[tr[u].son].size)
            tr[u].son=v;
    }
    return;
}
void DFS2(int u,int top){//当前点，当前链的顶点
    tr[u].top=top;
    tr[u].w=++sz;//把树边挂上线段树
    if(tr[u].son){
        DFS2(tr[u].son,top);//扩展搭建重链
        for(int i=hd[u];i;i=e[i].nxt){
            int v=e[i].v;
            if(v!=tr[u].fa && v!=tr[u].son)
                DFS2(v,v);//搭建轻链
        }
    }
    tr[u].e=sz;//当前点对应的线段树结尾
    return;
}
void update(int L,int R,LL w,int l,int r,int k){//区间加值
     if(L<=l && r<=R){
         st[k].mk+=w;
         st[k].smm+=(r-l+1)*w;
         return;
    }
    int mid=(l+r)>>1;
    if(st[k].mk){
        st[k<<1].mk+=st[k].mk;
        st[k<<1].smm+=st[k].mk*(mid-l+1);
        st[k<<1|1].mk+=st[k].mk;
        st[k<<1|1].smm+=st[k].mk*(r-mid);
        st[k].mk=0;
    }
    if(L<=mid)update(L,R,w,l,mid,k<<1);
    if(R>mid)update(L,R,w,mid+1,r,k<<1|1);
    st[k].smm=(st[k<<1].smm+st[k<<1|1].smm);
    return;
}
int query(int L,int R,int l,int r,int k){
    if(L<=l && r<=R)return st[k].smm;
    int mid=(l+r)>>1;
    if(st[k].mk){
        st[k<<1].mk+=st[k].mk;
        st[k<<1].smm+=st[k].mk*(mid-l+1);
        st[k<<1|1].mk+=st[k].mk;
        st[k<<1|1].smm+=st[k].mk*(r-mid);
        st[k].mk=0;
    }
    LL res=0;
    if(L<=mid)res=(res+query(L,R,l,mid,k<<1));
    if(R>mid)res=(res+query(L,R,mid+1,r,k<<1|1));
    return res;
}
int Find(int x,int y){
    int f1=tr[x].top,f2=tr[y].top;
    int ans=0;
    while(f1!=f2){
        if(tr[f1].dep<tr[f2].dep){
            ans+=query(tr[f2].w,tr[y].w,1,n,1);
            y=tr[f2].fa;
            f2=tr[y].top;
        }
        else{
            ans+=query(tr[f1].w,tr[x].w,1,n,1);
            x=tr[f1].fa;
            f1=tr[x].top;
        }
        ans;
    }
    if(tr[x].dep<tr[y].dep)return ans+query(tr[x].w,tr[y].w,1,n,1);
    return ans+query(tr[y].w,tr[x].w,1,n,1);
}
void add(int x,int y,int k){//x到y的路径加k
    int f1=tr[x].top,f2=tr[y].top;
    while(f1!=f2){
        if(tr[f1].dep<tr[f2].dep){
            update(tr[f2].w,tr[y].w,k,1,n,1);
            y=tr[f2].fa;
            f2=tr[y].top;
        }
        else{
            update(tr[f1].w,tr[x].w,k,1,n,1);
            x=tr[f1].fa;
            f1=tr[x].top;
        }
    }
    if(tr[x].dep<tr[y].dep) update(tr[x].w,tr[y].w,k,1,n,1);
    else update(tr[y].w,tr[x].w,k,1,n,1);
    return;
}
//
int main(){
    scanf("%d%d",&n,&M);
    int x,y;
    for(int i=1;i<n;i++){
        scanf("%d%d",&x,&y);
        add_edge(x,y);
        add_edge(y,x);
    }
    sz=tr[0].size=tr[rt].dep=0;
    //
    DFS1(rt);
    DFS2(rt,rt);
    memset(w,sizeof(w),0);
    for(int i=1;i<=n;i++)
        update(tr[i].w,tr[i].w,w[i],1,n,1);
    while (M--)
    {
        int A,B,C,D;scanf("%d%d%d%d",&A,&B,&C,&D);
        add(A,B,1);
        printf("%d\n",Find(C,D));
        add(A,B,-1);
    }
    return 0;
}

