#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
char s[100];
LL mi[100],n,m;
LL v[1007];
int main()
{
    mi[0]=1;for (int i=1;i<=35;i++) mi[i]=mi[i-1]*2;
    int cas=0;
    while (1)
    {
        scanf("%lld",&n);if (n==-1) break;
        scanf("%lld",&m);scanf("%s",s);
        LL a=n,b=m;
        int tot=0;v[1]=0;
        while (n)
        {
            int pos=lower_bound(mi,mi+35,n)-mi;
            if (mi[pos]!=n) pos--;
            v[++tot]=mi[pos]*m;
            n-=mi[pos];
        }
        if (s[0]=='u') sort(v+1,v+1+tot);
        printf("Case %d: %lld x %lld = %lld",++cas,a,b,v[1]);
        if (a==0 || b==0) 
        {
            puts("");
            continue;
        }
        for (int i=2;i<=tot;i++) printf(" + %lld",v[i]);puts("");
    }
    return 0;
}

