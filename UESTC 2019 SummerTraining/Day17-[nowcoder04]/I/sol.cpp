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
const int MAXN=200010;
struct PAM
{
    int next[MAXN][26],fail[MAXN],cnt[MAXN]
,len[MAXN],s[MAXN],last,n,p;
    void init()
    {
        p=1;
        len[0]=0;
        len[1]=-1;
        last=n=0;
        s[0]=-1;
        fail[0]=1;
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
 
    
struct sam{
    int l[800010],fa[800010],to[800010][27];
    int cnt,last;
    long long sz;
    int p,np,q,nq;
    sam()    {last=++cnt;}
 void extend(int c)   {
        p=last;
        last=np=++cnt;
        l[np]=l[p]+1;
        for(;p&&!to[p][c];p=fa[p])
            to[p][c]=np;
        if(!p)        {
            fa[np]=1;
        }
        else        {
            q=to[p][c];
            if(l[p]+1==l[q])            {
                fa[np]=q;
            }
            else
            {
                nq=++cnt;
                l[nq]=l[p]+1;
                memcpy(to[nq],to[q],sizeof(to[q]));
                fa[nq]=fa[q];
                fa[np]=fa[q]=nq;
                for(;to[p][c]==q;p=fa[p])
                    to[p][c]=nq;
            }
        }
        sz+=l[np]-l[fa[np]];
    }
} sam;
char s[200010];
int main()
{
    long long size1,size2,size3,ans;
    scanf("%s",s+1);
    long long len=strlen(s+1);
    pam.init();
    for(int i=1;i<=len;++i){
        pam.add(s[i]);
        sam.extend(s[i]-'a');
    }
    size1=pam.p-1;
    size2=sam.sz;
    sam.extend('z'+1-'a');
     
    for(int i=len;i>=1;--i){
        sam.extend(s[i]-'a');
    }
    size3=sam.sz-(long long)(len+1)*(len+1);
    ans=size2-(size2-(size3+size1)/2);
    cout<<ans<<endl;
}
