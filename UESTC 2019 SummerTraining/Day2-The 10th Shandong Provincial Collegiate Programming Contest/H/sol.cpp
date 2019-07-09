#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int T,n;
struct edge
{
    int l,r;
    bool friend operator < (edge a,edge b)
    {
        if(a.l==b.l) return a.r<b.r;
        return a.l<b.l;
    }
}e[100005];
priority_queue<int,vector<int>,greater<int> >q;
int ans;
void ini()
{
    while(!q.empty())
        q.pop();
    ans=0;
}
int main()
{
	scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<=n;i++)
            scanf("%d%d",&e[i].l,&e[i].r);
        sort(e+1,e+1+n);
        int now=0,i=1;
        while((!q.empty())||i<=n)
        {
            if((q.empty())&&i<=n) now=e[i].l;
            while(e[i].l==now&&i<=n)
                q.push(e[i++].r);
            now++,ans++,q.pop();
            while((!q.empty())&&q.top()<now) q.pop();
        }
        printf("%d\n",ans);
    }
	return 0;
}
