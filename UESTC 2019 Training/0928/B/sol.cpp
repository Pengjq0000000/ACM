#include<bits/stdc++.h>
#define mkp make_pair
#define ls c[x][0]
#define rs c[x][1]
using namespace std;
const int N=1e5+5,M=5e6+5;
struct Node{int x, y, t, v;} a[M];
map<pair<int,int >, int > mp;
int n,Q,op[M];
int scan(){
    int ret=0;
    char ch;
    while(ch=getchar(),ch>'9'||ch<'0');
    ret=ch-'0';
    while(ch=getchar(),ch<='9'&&ch>='0') {ret=ret*10+ch-'0';}
    return ret;
}
struct Dt{
        int t,id,bh;
        Dt(int a=0,int b=0,int c=0):t(a),id(b),bh(c){}
};
struct LCT{
    int tot,fa[N],c[N][2],sta[N],top;
    int del_pl[N],del_top;
    bool rev[N];
    Dt vl[N],mn[N];

    Dt Mn(Dt x,Dt y){
        if(!x.t)
            return y;
        if(!y.t)
            return x;
        return x.t<y.t?x:y;
    }
    int New(){
        int ret=(del_top?del_pl[del_top--]:++tot);
        c[ret][0]=c[ret][1]=fa[ret]=0;
        return ret;
    }
    bool isroot(int x){
        //cout<<c[fa[0]][1]<<" "<<x<<endl;
        return c[fa[x]][0]!=x&&c[fa[x]][1]!=x;
    }
    void pshp(int x){
        mn[x]=Mn(vl[x],Mn(mn[ls],mn[rs]));
    }
    void Rev(int x){
        if(!rev[x])return;
        rev[x]=0;
        rev[ls]^=1;
        rev[rs]^=1;
        swap(ls,rs);
    }
    void rotate(int x){
        int y=fa[x],z=fa[y],d=(x==c[y][1]);
        if(!isroot(y))c[z][y==c[z][1]]=x;
        fa[x]=z;
        fa[y]=x;
        fa[c[x][!d]]=y;
        c[y][d]=c[x][!d];
        c[x][!d]=y;
        pshp(y);pshp(x);
    }
    void splay(int x){
        sta[top=1]=x;
        for(int k=x;!isroot(k);k=fa[k])sta[++top]=fa[k];
        
        for(int i=top;i;i--)Rev(sta[i]);
        while(!isroot(x)){
            int y=fa[x],z=fa[y];
            if(!isroot(y))
                ((x==c[y][0])^(y==c[z][0]))?rotate(x):rotate(y);
            rotate(x);
        }
    }
    void access(int x){
        for(int t=0;x;rs=t,pshp(x),t=x,x=fa[x])splay(x);
    }
    void mkrt(int x){
        access(x);splay(x);
        rev[x]^=1;
    }
    void link(int x,int y){
        mkrt(x);
        fa[x]=y;
    }
    void cut(int x,int y){
        mkrt(x);access(y);splay(y);
        c[y][0]=0;pshp(y);fa[x]=0;
    }
    bool chk(int x,int y){
        mkrt(x);access(y);splay(y);
        while(c[y][0])y=c[y][0];
        return x==y;
    }
    void ins(Node cr,int id){
        int x=cr.x,y=cr.y;
        if(chk(x,y)){
            splay(x);
            Dt tp=mn[x];
            if(tp.t>cr.t) return;
            Node k=a[tp.id];
            int bh=tp.bh;
            cut(k.x,bh);
            cut(k.y,bh);
            del_pl[++del_top]=bh;
        }
        int nw=New();
        mn[nw]=vl[nw]=Dt(cr.t,id,nw);
        link(cr.x,nw);link(cr.y,nw);
    }
    int qry(int x,int y){
        if(!chk(x,y))return 0;
        splay(x);return mn[x].t;
    }
} lct[10];
int main(){
    int x,y;
    //cout<<scan()<<endl;
    scanf("%d%d",&n,&Q);
    //n=scan();
    //cout<<n<<endl;
    for(int k=0;k<10;++k){
        for(int i=1;i<=n;++i)
            lct[k].mn[i]=lct[k].vl[i]=Dt(0,0,0);
        lct[k].tot=n;
        
    }
    for(int i=1;i<=Q;++i){
        op[i]=scan();
        x=scan()+1;y=scan()+1;
        if(x>y)swap(x,y);
        if(op[i]==0){a[i].v=scan();mp[mkp(x,y)]=i;a[i].x=x;a[i].y=y;a[i].t=Q+1;}
        else if(op[i]==1)a[mp[mkp(x,y)]].t=i;
        else a[i].x=x,a[i].y=y;
    }
    for(int i=1;i<=Q;++i){
        if(op[i]==0){
            for(int j=a[i].v;j<=9;++j){
                //cout<<j<<endl;
                lct[j].ins(a[i],i);
            }
        }
        int l,r,mid;
        if(op[i]==2){
            l=0,r=10;
            while(l<r){
                mid=(l+r)/2;
                if(lct[mid].qry(a[i].x,a[i].y)>i)
                    r=mid;
                else l=mid+1;
            }
            //cout<<(lct[9].qry(a[i].x,a[i].y)>i)<<endl;
            if(l==10)puts("-1");
            else printf("%d\n",l);
        }
    }
}