#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n,ans[505];
int dp[505][505][2];
int fa[505],ss[505],son[505][2],rt;
queue<int> q;
void dfs(int u,int num,int clo){
    //cout<<u<<" "<<num<<" "<<clo<<endl;
    ans[u]=clo;
    if(clo==1){
        if(son[u][1]){
            if(dp[son[u][0]][num-1][1]&&dp[son[u][1]][num-1][1]){
                dfs(son[u][0],num-1,1);
                dfs(son[u][1],num-1,1);
                return;
            }
            if(dp[son[u][0]][num-1][1]&&dp[son[u][1]][num-1][0]){
                dfs(son[u][0],num-1,1);
                dfs(son[u][1],num-1,0);
                return;
            }
            if(dp[son[u][0]][num-1][0]&&dp[son[u][1]][num-1][1]){
                dfs(son[u][0],num-1,0);
                dfs(son[u][1],num-1,1);
                return;
            }
            if(dp[son[u][0]][num-1][0]&&dp[son[u][1]][num-1][0]){
                dfs(son[u][0],num-1,0);
                dfs(son[u][1],num-1,0);
                return;
            }
        }
        else if(son[u][0]){
            if(num==1){
                if(dp[son[u][0]][0][0]){
                    dfs(son[u][0],0,0);
                    return;
                }
            }
            else if(num==0){
                if(dp[son[u][0]][0][0]){
                    dfs(son[u][0],0,0);
                    return;
                }
            }
            else return;
        }
        else{
            return;
        }
    }
    if(clo==0){
        if(son[u][1]){
            if(dp[son[u][0]][num][1]&&dp[son[u][1]][num][1]){
                dfs(son[u][0],num,1);
                dfs(son[u][1],num,1);
                return;
            }
        }
        else if(son[u][0]){
            return;
        }
        else{
            return;
        }
    }
}
int main()
{
    int u,v,w;
	scanf("%d",&n);
    for(int i=1;i<=n;i++)
    {
        scanf("%d",&u);
        fa[i]=u;
        ++ss[u];
        if(son[u][0])son[u][1]=i;
        else son[u][0]=i;
        //ins(u,i);
    }
    for(int i=1;i<=n;++i){
        if(fa[i]==0) rt=i;
        if(son[i][0]==0&&son[i][1]==0){
            q.push(i);
            //cout<<i<<endl;
        }
    }
    //cout<<"ROOT"<<rt<<endl;
    while(!q.empty()){
        u=q.front();
        //cout<<u<<endl;
        q.pop();
        for(int i=0;i<=500;++i){
            if(son[u][1]){
                v=son[u][0];w=son[u][1];
                if(dp[v][i][1]&&dp[w][i][1]){
                    dp[u][i][0]=dp[u][i+1][1]=1;
                }
                if(dp[v][i][0]&&dp[w][i][1]){
                    dp[u][i+1][1]=1;
                }
                if(dp[v][i][1]&&dp[w][i][0]){
                    dp[u][i+1][1]=1;
                }
                if(dp[v][i][0]&&dp[w][i][0]){
                    dp[u][i+1][1]=1;
                }
            }
            else if(son[u][0]){
                v=son[u][0];
                if(dp[v][0][0]){
                    dp[u][1][1]=1;
                }
            }
            else{
                dp[u][0][0]=1;
                dp[u][1][1]=1;
            }
        }
        //if(u==2)cout<<dp[2][2][1]<<endl;
        if(u==rt)continue;
        (--ss[fa[u]]);
        if(ss[fa[u]]==0)
            q.push(fa[u]);
    }
    int flag=0;
    for(int i=0;i<=500;++i){
        if(dp[rt][i][1])
        {
            flag=1;
            dfs(rt,i,1);
            break;
        }
        if(dp[rt][i][0])
        {
            flag=1;
            dfs(rt,i,0);
            break;
        }
    }
    if(flag==0){
        puts("Impossible");
    }
    else{
        for(int i=1;i<=n;++i)
        {
            if(ans[i]==0)cout<<"R";
            else cout<<"B";
        }
    }
	return 0;
}
