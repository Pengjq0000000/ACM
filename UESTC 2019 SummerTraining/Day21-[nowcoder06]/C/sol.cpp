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
 
const int MAXN=100010; 
const int N=26; 
struct PAM
{
    int next[MAXN][N],fail[MAXN],cnt[MAXN]
,len[MAXN],s[MAXN],last,n,p;
    void init()
    {
        p=1;
        len[0]=0;
        len[1]=-1;
        last=n=0;
        s[0]=-1;
        fail[0]=1;
        memset(next,0,sizeof next);
    }
    int get_fail(int x)
    {
        while(s[n-len[x]-1]!=s[n])
            x=fail[x];
        return x;
    }
    void add(int c)
    {
        c-='a';
        s[++n]=c;
        int cur=get_fail(last);
        if(!next[cur][c])
        {
            len[++p]=len[cur]+2;
            fail[p]=next[get_fail(fail[cur])][c];
            next[cur][c]=p;
        }
        last=next[cur][c];
        ++cnt[last];
    }
    void count()
    {
        for(int i=p;i>=0;--i)
            cnt[fail[i]]+=cnt[i];
    }
} pam;
long long ans,dp[200010],len,T;
//int head,tail,u,v,q[200010];
int vis[200010];
char s[200010];
void dfs(int u){
    int v,w;
    for(int i=0;i<26;++i){
        if(pam.next[u][i]){
            v=pam.next[u][i];
            dp[v]=dp[u]+1;
            w=v;
            vis[v]=v;
            //cout<<vis[pam.fail[v]]<<"\t";
            while(!vis[pam.fail[w]]){
                vis[pam.fail[w]]=v;
                ++dp[v];
                w=pam.fail[w];
            }
            //cout<<(char)(i+'a')<<endl;
            dfs(v);
            vis[v]=0;
            w=v;
            while(vis[pam.fail[w]]==v){
                vis[pam.fail[w]]=0;
                w=pam.fail[w];
            }
            //cout<<(char)(i+'a')<<v<<" "<<dp[v]<<endl;
            ans+=dp[v]-1;
        }
    }
}
int main()
{
    scanf("%d",&T);
    for(int cas=1;cas<=T;++cas){
        pam.init();
        scanf("%s",s+1);
        len=strlen(s+1);
        for(int i=1;i<=len;++i){
            pam.add(s[i]);
        }
        ans=0;
        vis[0]=vis[1]=1;
        dfs(1);
        dfs(0);
        printf("Case #%d: %lld\n",cas,ans);
    }
}
