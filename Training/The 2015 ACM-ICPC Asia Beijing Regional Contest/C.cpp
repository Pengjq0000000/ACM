#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
int dp[1000000],a[10],b[10];
struct node
{
    int sta,dep;
    node(){}
    node(int sta,int dep):sta(sta),dep(dep){}
};
queue<node>q;

int toint(int *a)
{
    int res=0;
    for (int i=1;i<=6;i++) res=res*7+a[i];
    return res;
}

int toarr(int tmp)
{
    for (int i=6;i>=1;i--)
    {
        a[i]=tmp%7;
        tmp/=7;
    }
}

void bfs()
{
    int s=toint(a);
    q.push(node(s,0));
    while (!q.empty())
    {
        node now=q.front();q.pop();
        if (dp[now.sta]!=-1) continue;
        dp[now.sta]=now.dep;
        toarr(now.sta);
        for (int i=1;i<=6;i++)
        {
            for (int j=1;j<=6;j++)
            {
                if (i==j) continue;
                for (int k=1;k<=6;k++)
                {
                    if (a[k]==i) b[k]=j;
                    else b[k]=a[k];
                }
                int to=toint(b);
                if (dp[to]==-1) q.push(node(to,now.dep+1));
            }
        }
    }
}
char s[1000],p[1000];
int main()
{
    MEM(dp,-1);for (int i=1;i<=6;i++) a[i]=i;
    bfs();
    int low=0,up=0;
    for (int i=1;i<=6;i++) up=up*7+6;
    for (int i=1;i<=6;i++) low=low*7+1;
    /*
    for (int i=low;i<=up;i++)
    {
        if (dp[i]==-1) continue;
        toarr(i);
        for (int i=1;i<=6;i++) printf("%d",a[i]);
        printf(":%d\n",dp[i]);
    }
    */
    while (scanf("%s %s",s,p)!=EOF)
    {
        int ans=1e9,res=1e9;
        for (int i=low;i<=up;i++)
        {
            if (dp[i]==-1) continue;
            res=dp[i];
            toarr(i);
            int L=strlen(p);
            for (int j=0;j<L;j++)
            {
                if (s[j]!=a[p[j]-'0']+'0') res++;
            }
            ans=min(ans,res);
        }
        printf("%d\n",ans);
    }
    
    return 0;
}
