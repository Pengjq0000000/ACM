#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
long long n,m,L;
long long ans;
struct EM{
    long long a,b,id,room;
} em[100010];
struct RM{
    long long pos,c,v,id;
} rm[100010];
bool cmpem(EM u,EM v){
    return ((u.a-u.b)>(v.a-v.b));
}
bool cmprm(RM u,RM v){
    return u.pos<v.pos;
}
bool cmp2(RM u,RM v){
    return u.id<v.id;
}
bool cmp3(EM u,EM v){
    return u.room<v.room;
}
int main()
{
    scanf("%lld%lld%lld",&n,&m,&L);
    for(int i=1;i<=n;++i){
        scanf("%lld%lld",&rm[i].pos,&rm[i].c);
        rm[i].v=0;
        rm[i].id=i;
    }
    sort(rm+1,rm+n+1,cmprm);
    for(int i=1;i<=m;++i){
        scanf("%lld%lld",&em[i].a,&em[i].b);
        em[i].id=i;
    }
    sort(em+1,em+1+m,cmpem);
    int i,j=1,k;
    for(i=1;i<=m;++i)
    {
        if(em[i].a<em[i].b)
            break;
        while(rm[j].v==rm[j].c)
            ++j;
        em[i].room=rm[j].id;
        rm[j].v++;
        ans+=em[i].a*rm[j].pos*2+em[i].b*(L-rm[j].pos)*2;
    }
    k=i;j=n;
    for(i=m;i>=k;--i)
    {
        while(rm[j].v==rm[j].c)
            --j;
        em[i].room=rm[j].id;
        rm[j].v++;
        ans+=em[i].a*rm[j].pos*2+em[i].b*(L-rm[j].pos)*2;
    }
    cout<<ans<<endl;
    sort(rm+1,rm+n+1,cmp2);
    sort(em+1,em+m+1,cmp3);
    k=1;
    for(int i=1;i<=n;++i)
    {
        printf("%lld",rm[i].v);
        for(int j=1;j<=rm[i].v;++j,++k)
            printf(" %lld",em[k].id);
        puts("");
    }
	return 0;
}
