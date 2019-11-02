#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 1e5+7;
char s[maxn],t[maxn];
LL dist[400][400];
int main()
{
    scanf(" %s",s);
    scanf(" %s",t);
    
    for (int i=0;i<=150;i++)
        for (int j=0;j<=150;j++)
            dist[i][j]=1e8;
    for (int i=0;i<=150;i++) dist[i][i]=0;
    int n;scanf("%d",&n);
    for (int i=1;i<=n;i++)
    {
        char u,v;LL w;
        scanf(" %c %c %lld",&u,&v,&w);
        //printf("%d %d\n",u,v);
        dist[u][v]=min(dist[u][v],w);
    }
    for (int k=0;k<=150;k++)
        for (int i=0;i<=150;i++)
            for (int j=0;j<=150;j++)
                dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
    
    
    LL res=0;
    int L=strlen(s);
    for (int i=0;i<L;i++)
    {
        if (dist[s[i]][t[i]]>=1e8)
        {
            res=-1;break;
        }
        res+=dist[s[i]][t[i]];
        
    }
    printf("%lld\n",res);
    return 0;
}
