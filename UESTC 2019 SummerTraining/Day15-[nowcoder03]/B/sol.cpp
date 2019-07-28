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
int Max(int u,int v){return u>v?u:v;}
int Min(int u,int v){return u<v?u:v;}
int n;
char s[100010];
int t[200010],fir[200010],ans,cnt0,cnt1;
int main()
{
    scanf("%d",&n);
    scanf("%s",s+1);
    t[0]=100000;
    for(int i=1;i<=n;++i){
        s[i]-='0';
        if(s[i]==0) ++cnt0;
        else ++cnt1;
        if(s[i]==1) t[i]=t[i-1]+1;
        else t[i]=t[i-1]-1;
    }
    memset(fir,-1,sizeof fir);
    fir[100000]=0;
    ans=0;
    for(int i=0;i<=n;++i){
        if(fir[t[i]]==-1)
            fir[t[i]]=i;
        else{
            ans=Max(ans,i-fir[t[i]]);
        }
    }
    printf("%d %d\n",ans,2*Min(cnt1,cnt0));
}
