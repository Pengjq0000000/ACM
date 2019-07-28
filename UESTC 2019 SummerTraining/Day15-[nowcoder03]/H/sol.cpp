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
int T;
struct P{
    int x,y;
} p[10010];
int n;
bool cmp(P u,P v){return u.x==v.x?u.y>v.y:u.x<v.x;}
/*1 4 0 1 -1 0 1 0 0 -1*/
int main()
{
    scanf("%d",&T);
    while(T--){
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d%d",&p[i].x,&p[i].y);
        sort(p+1,p+n+1,cmp);
        if(p[n/2].x<p[n/2+1].x){
            printf("%d %d %d %d\n",p[n/2].x,p[n/2].y-10000000,p[n/2+1].x,p[n/2+1].y+10000000);
            continue;
        }
        else{
            printf("%d %d %d %d\n",p[n/2].x-1,p[n/2].y-10000000,p[n/2+1].x+1,p[n/2+1].y+10000000);
            continue;
        }
    }
     
}
