#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int T,n,m;
long long A,B,C;
struct fraction
{
    long long son,mom;
    fraction() {}
    fraction(long long son,long long mom):son(son),mom(mom){}
    bool friend operator < (fraction a,fraction b)
    {
        if(a.mom<0) a.son=-a.son,a.mom=-a.mom;
        if(b.mom<0) b.son=-b.son,b.mom=-b.mom;
        return a.son*b.mom<b.son*a.mom;
    }
    bool friend operator <= (fraction a,fraction b)
    {
        if(a.mom<0) a.son=-a.son,a.mom=-a.mom;
        if(b.mom<0) b.son=-b.son,b.mom=-b.mom;
        return a.son*b.mom<=b.son*a.mom;
    }
}F[100005];
int cnt;
struct point
{
    long long a,b;
    fraction f;
    bool friend operator < (point x,point y)
    {
        return x.f<y.f;
    }
}p[100005];
bool deal()
{
    cnt=0;
    fraction tmp;
    
    if(A==0&&C-B==0) return 1;
    tmp=(fraction){C-B,A};
    if(tmp<p[1].f) F[++cnt]=tmp;
    
    for(int i=1;i<n;i++)
    {
        A-=2*p[i].a; B-=2*p[i].b;
        if(A==0&&C-B==0) return 1;
        tmp=(fraction){C-B,A};
        if(p[i].f<=tmp&&tmp<p[i+1].f) F[++cnt]=tmp;
    }
    
    A-=2*p[n].a; B-=2*p[n].b;
    if(A==0&&C-B==0) return 1;
    tmp=(fraction){C-B,A};
    if(p[n].f<=tmp) F[++cnt]=tmp;
    return 0;
}
int main()
{
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%lld",&n,&C);
        A=0; B=0;
        for(int i=1;i<=n;i++)
        {
            scanf("%lld%lld",&p[i].a,&p[i].b);
            if(p[i].a>0)
            {
                p[i].a*=-1;
                p[i].b*=-1;
            }
            if(p[i].a==0)
            {
                B+=abs(p[i].b);
                n--;
                i--;
                continue;
            }
            p[i].f.son=-p[i].b;
            p[i].f.mom=p[i].a;
            A+=p[i].a;
            B+=p[i].b;
        }
        sort(p+1,p+1+n);
        
        if(deal())
        {
            printf("-1\n");
            continue;
        }
        
        printf("%d",cnt);
        for(int i=1;i<=cnt;i++)
        {
            if(F[i].son==0)
            {
                printf(" 0/1");
                continue;
            }
            long long g=__gcd(F[i].son,F[i].mom);
            F[i].son/=g; F[i].mom/=g;
            if(F[i].mom<0ll) F[i].son*=-1, F[i].mom*=-1;
            printf(" %lld/%lld",F[i].son,F[i].mom);
        }
        printf("\n");
    }
    return 0;
}
