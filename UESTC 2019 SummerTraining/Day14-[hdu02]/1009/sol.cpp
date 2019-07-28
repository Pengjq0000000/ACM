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

const int MAXN=300100;  
const int N=26;  
struct PAM
{
    int next[MAXN][N],fail[MAXN],cnt[MAXN]
,len[MAXN],s[MAXN],last,n,p,nn;
    void init()
    {
        p=1;
        len[0]=0;
        len[1]=-1;
        last=n=0;
        s[0]=-1;
        fail[0]=1;
        
        for(int i=0;i<=nn+2;++i){
            for(int j=0;j<26;++j)
                next[i][j]=0;
            cnt[i]=0;
        }
        
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
            cnt[p]=0;
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
int llen;
int f[25][300505];
int root=1;
struct E{
    int to,next;
} e[310000];
int tot=0,last[300505];
int len[300505],cnt[300505],ans[300505];
void add(int u,int v){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
}
int vis[300115];
void dfs(int u){
    vis[len[u]+10]++;
    if(vis[(len[u]+1)/2+10]) ans[len[u]]+=cnt[u];
    //cout<<u<<endl;
    //cout<<last[u]<<endl;
    for(int i=last[u];i;i=e[i].next){
        //dep[e[i].to]=1+dep[u];
        if(len[e[i].to]!=-2)continue;
        len[e[i].to]=pam.len[i];
        cnt[e[i].to]=pam.cnt[e[i].to];
        //f[0][e[i].to]=u;
        //for(int j=1;j<=20;j++)
        //    f[j][e[i].to]=f[j-1][f[j-1][e[i].to]];
        dfs(e[i].to);
    }
    vis[len[u]+10]--;
    /*int x=u;
    for(int i=20;i>=0;i--){
        if(len[f[i][x]]<(len[u]+1)/2) continue;
        x=f[i][x];
        if(len[x]==(len[u]+1)/2) break;
    }
    if(len[x]==(len[u]+1)/2) ans[len[u]]+=cnt[u];*/
}
void init()
{
    for(int i=0;i<=llen+10;++i){
        ans[i]=0;
        last[i]=0;
        len[i]=-2;
    }
    tot=0;
}
char s[300505];
int main()
{
    while(scanf("%s",s+1)!=EOF){
        llen=strlen(s+1);
        pam.nn=llen;
        pam.init();
        for(int i=1;i<=llen;++i){
            pam.add(s[i]);
        }
        pam.count();
        init();
        //for(int i=0;i<=pam.p;++i)cout<<pam.fail[i];
        //cout<<endl;
        for(int i=0; i<=pam.p; i++)
        {
            //cout<<pam.cnt[i]<<endl;
            if(i==1) continue;
            //cout<<pam.fail[i]<<" "<<i<<endl;
            add(pam.fail[i],i);
        }
        len[root]=-1;
        cnt[root]=1;
        //dep[root]=0;
        dfs(root);
        //cout<<"ads";
        /*
        for(int i=1;i<=7;++i)cout<<cnt[i]<<" ";
        cout<<endl;
        
        for(int i=1;i<=7;++i)cout<<len[i]<<" ";
        cout<<endl;
        */
        printf("%d",llen);
        for(int i=2;i<=llen;++i){
            printf(" %d",ans[i]);
        }
        puts("");
    }
}
