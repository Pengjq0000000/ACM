#include<bits/stdc++.h>
using namespace std;
vector<int>st[100010];
int g[100010][26];
int fail[100010],sz=0;
int dp[100010],pos[100010];
queue<int> q;
int n,m,len[100010];
char s[100010],t[100010];
bool vis[100010];
void Build_AC(){
    int i,u,v;
    for(i=0;i<26;++i){
        if(g[0][i])
            q.push(g[0][i]);
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(i=0;i<26;++i){
            if(g[u][i]){
                v=g[u][i];
                q.push(v);
                fail[v]=g[fail[u]][i];
                for (int x : st[v]) vis[x] = 1;
                for (int x : st[fail[v]]) 
                    if (!vis[x]) st[v].push_back(x), vis[x] = 1;
                for (int x : st[v]) vis[x] = 0;
                //sort(st[v].begin(),st[v].end());
                //st[v].erase(unique(st[v].begin(),st[v].end()),st[v].end());
                //bs[v]|=bs[fail[v]];
            }
            else{
                g[u][i]=g[fail[u]][i];
            }
        }
    }
}
int cnt[100010],fir[100010],id[100010];
int main(){
    scanf("%d%d",&n,&m);
    scanf("%s",s+1);
    int u;
    for(int i=1;i<=m;++i){
        scanf("%s",t+1);
        len[i]=strlen(t+1);
        u=0;
        for(int j=1;j<=len[i];++j){
            t[j]=t[j]-'a';
            if(!g[u][t[j]]){
                g[u][t[j]]=++sz;
            }
            u=g[u][t[j]];
        }
        cnt[u]++;
        if(cnt[u]==1)
        {
            id[i]=fir[u]=i;
            st[u].push_back(i);
        }
        else id[i]=fir[u];
    }
    Build_AC();
    u=0;

    for(int i=1;i<=n;++i){
        u=g[u][s[i]-'a'];
        for (int x : st[u]){
            if(pos[x]&&pos[x]>i-len[x])
                continue;
            dp[x]++;
            pos[x]=i;
        }
    }
    for(int i=1;i<=m;++i)
        printf("%d\n",dp[id[i]]);
}