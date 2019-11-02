#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
const int maxn = 5007;
struct node
{
    int id,p,r;
    bool operator < (const node &rhs) const
    {
        return r<rhs.r;
    }
}room[maxn];

struct NODE
{
    int id,num;
    NODE(int id,int num):id(id),num(num){}
    NODE(){}
    bool operator < (const NODE &rhs) const
    {
        return num>rhs.num;
    }
}p[maxn];

int ans[maxn],vis[maxn];
int main()
{
    int n,m;scanf("%d%d",&n,&m);
    for (int i=1;i<=n;i++)
    {
        int x;scanf("%d",&x);
        p[i]=NODE(i,x);
    }
    for (int i=1;i<=m;i++) scanf("%d",&room[i].p),room[i].id=i;
    for (int i=1;i<=m;i++) scanf("%d",&room[i].r);
    
    sort(room+1,room+1+m);
    sort(p+1,p+1+n);
    
    int cnt=0;
    for (int i=1;i<=m;i++)
    {
        for (int j=1;j<=n;j++)
        {
            if (!vis[j] && p[j].num<=room[i].p)
            {
                vis[j]=1;
                ans[p[j].id]=room[i].id;
                cnt++;
                break;
            }
        }
    }
    
    if (cnt<n) printf("impossible");
    else 
    {
        for (int i=1;i<n;i++) printf("%d ",ans[i]);
        printf("%d",ans[n]);
    }
    
    
    
    
    return 0;
}
