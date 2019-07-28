#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n;
int a[100005];
int b[100005];
char dp[100005][5][5][5];
vector<int>v[100005];
int cnt;
int s[500][3];
bool yeah[5][5][5];
void dabiao(int i,int j,int k)
{
    /*int num[5]={0,0,0,0,0};
    num[i]++; num[j]++; num[k]++;
    if(num[0]>1||num[1]>1) return;
    if(i>=2&&j==i+1) return;
    if(i>=2&&k==i+2) return;
    if(j>=2&&k==j+1) return;
    if(i!=2&&j!=3&&k!=4) return;*/
    cnt++;
    s[cnt][0]=i,s[cnt][1]=j,s[cnt][2]=k;
    yeah[i][j][k]=1;
}
bool check(int m,int x,int y,int z)
{
    int c[4];
    c[0]=v[m][x],c[1]=v[m+1][y],c[2]=v[m+2][z];
    sort(c,c+3);
    if(c[0]==-1) return 0;
    if(b[m]==c[1]) return 1;
    return 0;
}
void dfs(int m,int x,int y,int z)
{
    if(!check(m,x,y,z))
    {
        dp[m][x][y][z]=2;
        return;
    }
    if(m==1)
    {
        dp[m][x][y][z]=1;
        return;
    }
    for(int i=0;i<5;i++)
    {
        if(!yeah[i][x][y]) continue;
        if(dp[m-1][i][x][y]==0)
            dfs(m-1,i,x,y);
        if(dp[m-1][i][x][y]==1)
        {
            dp[m][x][y][z]=1;
            return;
        }
    }
    dp[m][x][y][z]=2;
}
void dfs2(int m,int x,int y,int z)
{
    for(int i=0;i<5;i++)
    {
        if(!yeah[i][x][y]) continue;
        if(dp[m][i][x][y]!=1) continue;
        a[m]=v[m][i];
        if(m>1) dfs2(m-1,i,x,y);
        return;
    }
}
void construct()
{
    //printf("YES\n");
    for(int t=1;t<=cnt;t++)
    {
        int i,j,k;
        i=s[t][0],j=s[t][1],k=s[t][2];
        if(dp[n-2][i][j][k]!=1) continue;
        a[n-2]=v[n-2][i];
        a[n-1]=v[n-1][j];
        a[n]=v[n][k];
        dfs2(n-3,i,j,k);
        break;
    }
    /*printf("%d\n",n);
    for(int i=1;i<=n-2;i++)
    {
        printf("%d",b[i]);
        if(i<n-2) printf(" ");
        else printf("\n");
    }
    printf("%d\n",n);*/
    for(int i=1;i<=n;i++)
    {
        printf("%d",a[i]);
        if(i<n) printf(" ");
        else printf("\n");
    }
}
void ini()
{
    for(int i=1;i<=n;i++)
        v[i].clear();
    for(int i=1;i<=n;i++)
        for(int j=1;j<=cnt;j++)
            dp[i][s[j][0]][s[j][1]][s[j][2]]=0;
}
int main()
{
    //freopen("i.in","r",stdin);
    //freopen("i.out","w",stdout);
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            for(int k=0;k<5;k++)
                dabiao(i,j,k);
    int T;
    scanf("%d",&T);
    //printf("%d\n",T);
    while(T--)
    {
        scanf("%d",&n);
        ini();
        for(int i=1;i<=n-2;i++)
            scanf("%d",&b[i]);
        for(int i=1;i<=n;i++)
        {
            v[i].push_back(0);
            v[i].push_back(1000000000);
            if(1<=i&&i<=n-2) v[i].push_back(b[i]);
                else v[i].push_back(-1);
            if(2<=i&&i<=n-1) v[i].push_back(b[i-1]);
                else v[i].push_back(-1);
            if(3<=i&&i<=n) v[i].push_back(b[i-2]);
                else v[i].push_back(-1);
        }
        int ans=0;
        for(int t=1;t<=cnt;t++)
        {
            int i,j,k;
            i=s[t][0],j=s[t][1],k=s[t][2];
            if(dp[n-2][i][j][k]==0)
                dfs(n-2,i,j,k);
            if(dp[n-2][i][j][k]==1)
            {
                ans=1;
                break;
            }
        }
        if(ans) construct();
        else printf("-1\n");
    }
    return 0;
}
