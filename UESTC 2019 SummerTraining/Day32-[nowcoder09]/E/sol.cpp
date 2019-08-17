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
__int128 ans=0;
__int128 sumsz2,sz[100010],fa[100010];
__int128 n,m;
int find(int u){
    if(u==fa[u])
        return u;
    return fa[u]=find(fa[u]);
}
int main(){
    int u,v,x,y;
    long long nn, mm;
    scanf("%lld%lld",&nn,&mm);
    n=nn;m=mm;
    ans=(n*(n-1)*(n-2)*(n-3)/24);
    printf("%lld\n",(long long)ans);
    for(int i=1;i<=n;++i)fa[i]=i,sz[i]=1;
    sumsz2=n;
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u,&v);
        x=find(u);y=find(v);
        if(x==y){
            printf("%lld\n",(long long)ans);
            continue;
        }
        ans=ans-sz[x]*sz[y]*((n-sz[x]-sz[y])*(n-sz[x]-sz[y])-(sumsz2-sz[x]*sz[x]-sz[y]*sz[y]))/2;
        sumsz2=sumsz2-sz[x]*sz[x]-sz[y]*sz[y]+(sz[x]+sz[y])*(sz[x]+sz[y]);
        fa[x]=y;
        sz[y]+=sz[x];
        printf("%lld\n",(long long)ans);
    }
}