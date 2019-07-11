#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int times = 2100, st;
int n,m,ans,maxe,a,b;
/*10 10
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
10 2
10 3
1 10 

10 9
1 6
6 9
9 10
10 3
3 2
2 7
7 5
5 8
8 4
6 7*/
int last[100010],tot=1;
struct E{
    int to,next,id,rd;
} e[400010],e2[400010];
int last2[100010],tot2=1;
int used[400100];
int vis[100010];
void add(int u,int v,int i){
    e[++tot].next=last[u];
    last[u]=tot;
    e[tot].to=v;
    e[tot].id=i;
}
void add2(int u,int v,int i){
    e2[++tot2].next=last2[u];
    last2[u]=tot2;
    e2[tot2].to=v;
    e2[tot2].id=i;
}
int impos[100010][6];
int pos1[100010],val1[100010];
unordered_map<int, int> val2[100010];
int pos2[100010];
int temp1,temp2;
int ttt=0;
void dfs(int u,int dep){
    
    vis[u]=1;
    int tmp=maxe,flag=0,v;
    for(int i=last[u];i;i=e[i].next){
        if(e[i].id>=ans) break;
        v=e[i].to;
        if(impos[v][4-dep]) continue;
        flag=1;
        if(v==b||vis[v]||used[i]) continue;
        /////
        ++ttt;
        if (ttt > 8e7)
        {
            if(ans==500000)
            puts("-1");
            else
            {
                printf("%d\n", ans);
            }
            exit(0);
        }
        /////
        //||impos[e[i].to][4-dep])continue;
        used[i]=used[i^1]=1;
        if(e[i].id>maxe)
            maxe=e[i].id;
        if(dep<2)
            dfs(v,dep+1);
        else{
            if(dep==2)
            {
                if(pos2[v]&&!vis[v]){
                    for (auto iter = val2[v].begin(); iter != val2[v].end(); iter++)
                    {
                        temp1=(iter->first);
                        temp2=(iter->second);
                        if(!vis[temp1]){
                            if(maxe<ans&&val1[temp1]<ans&&temp2<ans)
                                ans=max(max(val1[temp1],maxe),temp2);
                        }
                        ////////
                        ++ttt;
                        if (ttt > 8e7)
                        {
                            if(ans==500000)
                            puts("-1");
                            else
                            {
                                printf("%d\n", ans);
                            }
                            exit(0);
                        }
                        ///////
                    }
                }
            }
            /* 
            if(dep==3){
                if(pos[v]&&!vis[v]){
                    if(maxe<ans&&val[v]<ans)
                        ans=max(val[v],maxe);
                }
            }
            else if(dep==4){
                if(e[i].to==b){
                    if(maxe<ans)
                        ans=maxe;
                }
                else
                {
                    impos[e[i].to][0]=1;
                }
            }
            */
        }
        used[i]=used[i^1]=0;
        maxe=tmp;
    }
    if(!flag)
        impos[u][5-dep]=1;
    vis[u]=0;
}
int u[200010],v[200010];
int pp[200005];
int main()
{
    srand(998244353);
    //printf("st:%d\n", st);
	scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i){
        scanf("%d%d",&u[i],&v[i]);
    }
    for(int i=m;i>=1;--i){
        add(u[i],v[i],i);add(v[i],u[i],i);
    }
    for (int i = 1; i <= m; i++) pp[i] = i;
    int t=rand()%100;
    while(t--)
    random_shuffle(pp + 1, pp + 1 + m);

    for(int i=m;i>=1;--i){
        int x = pp[i];
        add2(u[x],v[x],x);add2(v[x],u[x],x);
    }

    scanf("%d%d",&a,&b);
    swap(a, b);
    int vv;

    for(int i=last2[b];i;i=e2[i].next)
    {
        vv=e2[i].to;
        pos1[vv]=1;
        val1[vv]=e2[i].id;
        for(int j=last2[vv];j;j=e2[j].next){
            if(e2[j].to==b)continue;
            pos2[e2[j].to]=1;
            val2[e2[j].to][vv]=e2[j].id;
        }
    }
    ans=500000;
    maxe=0;
    dfs(a,0);
    if(ans==500000)
        puts("-1");
    else
    {
        printf("%d\n", ans);
    }
    //printf("ed:%d\n",(int)clock());
	return 0;
}
