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
int n,m;
int occ[100];
int pos[100][10010];
char s[3],t[10010],ans[10010];
int len;
int main(){
    //scanf("%d",&T);
    //while(T--)
    {
        scanf("%d%d",&n,&m);
        memset(occ,-1,sizeof occ);
        for(int i=1;i<=n;++i)
        for(int j='a'-'a';j<='z'-'a';++j)
            pos[j][i]=0;
        bool flag=0;
        int cnt,now;
        for(int i=1;i<=m*(m-1)/2;++i){
            scanf("%s",s);
            scanf("%d",&len);
            scanf("%s",t+1);
            cnt=0;now=0;
            for(int j=1;j<=len;++j){
                if(t[j]==s[0]){
                    pos[s[0]-'a'][++now]+=cnt;
                    cnt=0; 
                }
                else{
                    ++cnt;
                }
            }
            if(occ[s[0]-'a']==-1)occ[s[0]-'a']=now;
            else if(occ[s[0]-'a']!=now){flag=1;break;}
            cnt=0;now=0;
            for(int j=1;j<=len;++j){
                if(t[j]==s[1]){
                    pos[s[1]-'a'][++now]+=cnt;
                    cnt=0; 
                }
                else{
                    ++cnt;
                }
            }
            if(occ[s[1]-'a']==-1)occ[s[1]-'a']=now;
            else if(occ[s[1]-'a']!=now){flag=1;break;}
        }
        if(flag){puts("-1");return 0;}
        int tmp=0;
        for(int i=0;i<='z'-'a';++i){
            tmp=0;
            for(int j=1;j<=occ[i];++j){
                if(tmp+pos[i][j]+1>n){flag=1;break;}
                if(ans[tmp+pos[i][j]+1]){flag=1;break;}
                 
                ans[tmp+pos[i][j]+1]=i+'a';
                tmp=tmp+pos[i][j]+1;
            }
            if(flag)break;
        }
        if(flag||strlen(ans+1)!=n){puts("-1");return 0;}
        printf("%s\n",ans+1);
    }
}