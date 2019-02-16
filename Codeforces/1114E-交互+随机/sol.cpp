#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e6+7;
int vis[maxn],a[maxn];

int table[100]={0,14,24,9,19};

int random(int x) {return rand()*rand()%x+1;}
int ask(int pos)
{
    printf("? %d\n",pos);
    fflush(stdout);
    int x;scanf("%d",&x);
    return x;
    //return table[pos];
}
int check(int x)
{
    printf("> %d\n",x);
    fflush(stdout);
    int b;scanf("%d",&b);
    return b;
    //return x<24;
}
void done(int x,int d)
{
    printf("! %d %d\n",x,d);
    fflush(stdout);
}
int main()
{
    int n;scanf("%d",&n);
    //int n=4;
    int l=0,r=1e9,cnt=0;
    while (l<r)
    {
        cnt++;
        int mid=(l+r)/2;
        if (check(mid)) l=mid+1;
        else r=mid;
    }
    int mx=l,tot=0,gcd=0;
    for (int k=0;k<min(n,60-cnt);k++)
    {
        int x=random(n);
        while (vis[x]) x=random(n);
        a[++tot]=ask(x);vis[x]=1;
        for (int i=1;i<tot;i++) gcd=__gcd(gcd,abs(a[tot]-a[i]));
    }
    //for (int i=1;i<=tot;i++) printf("%d ",a[i]);puts("");
    done(mx-(n-1)*gcd,gcd);
    return 0;
}

