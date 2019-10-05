#include<bits/stdc++.h>
#define lson (rt << 1)
#define rson (rt << 1 | 1)
using namespace std;
int g[300010][26],fail[300010],matching[300010];
char str[300010],s[300010];
int len,sz;
queue<int> q;
void build_ac(){
    int i,u,v;
    for(int i=0;i<26;++i){
        if(g[0][i])
            q.push(g[0][i]);
    }
    while(!q.empty()){
        u=q.front();
        q.pop();
        for(int i=0;i<26;++i){
            if(g[u][i]){
                v=g[u][i];
                q.push(v);
                fail[v]=g[fail[u]][i];
                matching[v]=max(matching[fail[v]],matching[v]);
            }
            else{
                g[u][i]=g[fail[u]][i];
            }
        }
    }
}

const int maxn = 3e5 + 7;
int p[maxn], dp[maxn];
int T[maxn << 2];
void pushup(int rt) {T[rt] = min(T[lson], T[rson]);}
void build(int rt, int l, int r)
{
    if (l == r) {T[rt] = dp[l]; return;}
    int mid = (l + r) / 2;
    build(lson, l, mid);
    build(rson, mid + 1, r);
    pushup(rt);
}
void update(int rt, int l, int r, int pos, int v)
{
    if (l == r) {T[rt] = v; return;}
    int mid = (l + r) / 2;
    if (pos <= mid) update(lson, l, mid, pos, v);
    else update(rson, mid + 1, r, pos, v);
    pushup(rt);
}
int query(int rt, int l, int r, int L, int R)
{
    if (L <= l && r <= R) return T[rt];
    int res = 0x3f3f3f3f, mid = (l + r) / 2;
    if (L <= mid) res = min(res, query(lson, l, mid, L, R));
    if (mid <  R) res = min(res, query(rson, mid + 1, r, L, R)); 
    return res;
}
int main(){
    int m;
    scanf("%d",&m);
    scanf("%s",str+1);
   int u=0;
    for(int i=1;i<=m;++i){
        scanf("%s",s);
        len=strlen(s);
        u=0;
        for(int i=0;i<len;++i){
            s[i]=s[i]-'a';
            if(!g[u][s[i]]){
                g[u][s[i]]=++sz;
            }
            u=g[u][s[i]];
        }
        matching[u]=len;
    }
    build_ac();
    len=strlen(str+1);
    u=0;
    for(int i=1;i<=len;++i){
        u=g[u][str[i]-'a'];
        p[i]=i-matching[u];
        //cout<<matching[u]<<endl;
    }
    memset(dp, 0x3f3f3f3f, sizeof(dp));
    dp[0] = 0;
    build(1, 0, len);
    for (int i = 1; i <= len; i++)
    {
        //printf("%d %d\n", p[i], i - 1);
        if (p[i] <= i - 1)
        {
            dp[i] = query(1, 0, len, p[i], i - 1) + 1;
            update(1, 0, len, i, dp[i]);
        }
    }
    printf("%d\n", dp[len] >= 0x3f3f3f3f ? -1 : dp[len]);
}
/*
3
abcaaa
a
aa
caa
*/