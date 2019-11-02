#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;
LL dist[26][26];
LL num[30],C[50][50];
LL ans;
char s[30];

void init()
{
    C[1][0]=C[1][1]=1;
    for (int i=2;i<30;i++)
    {
        C[i][0]=1;
        for (int j=1;j<30;j++) C[i][j]=MOD(C[i-1][j]+C[i-1][j-1]);
    }
}

LL quick(LL x,LL n)
{
    LL res=1,base=x;
    while (n)
    {
        if (n&1) res=MOD(res*base);
        base=MOD(base*base);
        n>>=1;
    }
    return res;
}

int n;


int cnt[30];
struct node
{
    LL d;
    int num;
    node(LL d,int num):d(d),num(num){}
    node(){}
};
vector<node>v;




void dfs(int now,int x,LL lcm,LL head)
{
    if (x>n) return;
    if (now==v.size())
    {
        ans=MOD(ans+MOD(MOD(head*num[x])*lcm));
        return;
    }
    LL tmp=__gcd(lcm,v[now].d);
    for (int i=0;i<=v[now].num;i++)
    {
        if (i==0) dfs(now+1,x+i,lcm,MOD(head*C[v[now].num][i]));
        if (i>0) dfs(now+1,x+i,lcm/tmp*v[now].d,MOD(head*C[v[now].num][i]));
    }
}




int main()
{
    int T;scanf("%d",&T);
    init();
    while (T--)
    {
        scanf("%d",&n);
        scanf("%s",s);
        MEM(dist,0x3f3f3f3f);
        for (int i=0;i<26;i++)
        {
            dist[i][s[i]-'a']=1;
        }
        for (int k=0;k<26;k++)
            for (int i=0;i<26;i++)
                for (int j=0;j<26;j++)
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);

        MEM(cnt,0);
        for (int i=0;i<26;i++) cnt[dist[i][i]]++;
        v.clear();
        for (int i=1;i<=26;i++)
        {
            if (cnt[i]==0) continue;
            v.pb(node(i,cnt[i]));
        }
        MEM(num,0);int up=min(26,n);

        num[1]=1;
        for (int x=2;x<=up;x++)
        {
            LL tmp=0;
            for (int i=1;i<x;i++)
            {
                tmp=MOD(tmp+C[x][i]*num[i]);
            }
            num[x]=MOD(quick(x,n)-tmp+mod);
        }
        ans=0;
        dfs(0,0,1,1);
        printf("%lld\n",ans);

    }
    return 0;
}

/*
2
2
abcdefghijklmnpqrstuvwxyzo
1
abcdefghijklmnopqrstuvwxyz
*/

