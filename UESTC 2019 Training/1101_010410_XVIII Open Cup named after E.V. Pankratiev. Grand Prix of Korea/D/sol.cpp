#include<bits/stdc++.h>
using namespace std;
char s[1000010];
int len,nxt[1000010][27],last[27];
int ans,now,u,cnt;
int main(){
    scanf("%s",s+1);
    len=strlen(s+1);
    for(int j='a';j<='z';++j)
        nxt[len][j-'a']=last[j-'a']=1000000000;
    
    for(int i=len-1;i>=0;--i){
        last[s[i+1]-'a']=i+1;
        for(int j='a';j<='z';++j)
            nxt[i][j-'a']=last[j-'a'];
        //cout<<i<<" "<<nxt[i]['a'-'a']<<" "<<nxt[i][1]<<endl;
    }
    now=1;
    ans=1;
    while(now<len){
        //cout<<now<<endl;
        u=0;
        for(cnt=1;now+cnt<=len;++cnt){
            if(nxt[u][s[now+cnt]-'a']<=now)
                u=nxt[u][s[now+cnt]-'a'];
            else
                break;
        }
        //cout<<"CNT::"<<cnt<<endl;
        --cnt;
        if(cnt==0){
            ++ans;
            ++now;
        }
        else{
            ++ans;
            now+=cnt;
        }
    }
    cout<<ans<<endl;
}