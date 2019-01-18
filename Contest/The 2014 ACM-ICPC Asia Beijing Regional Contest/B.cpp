#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
struct node 
{
    int id,num;
    bool operator < (const node &rhs) const
    {
        return num>rhs.num;
    }
}c[10];
int n,m,k,flg,mp[10][10];

int check(int x,int y,int color)
{
    if (x-1>=1 && mp[x-1][y]==color) return 0;
    if (y-1>=1 && mp[x][y-1]==color) return 0;
    return 1;
}
void print()
{
    for (int i=1;i<=n;i++)
    {
        printf("%d",mp[i][1]);
        for (int j=2;j<=m;j++) printf(" %d",mp[i][j]);
         printf("\n");
    }
}

void dfs(int x,int y,int cnt)
{
    if (flg) return;
    if (y>m) {y=1;x++;}
    if (x>n)
    {
        flg=1;return;
    }
    for (int i=1;i<=k;i++)
    {
        if (c[i].num>(n*m-cnt+1)/2) return;
        if (!c[i].num) continue;
        if (check(x,y,c[i].id)) 
        {
            mp[x][y]=c[i].id;c[i].num--;
            dfs(x,y+1,cnt+1);
            if (flg) return;
            mp[x][y]=0;c[i].num++;
        }
    }
}

int main()
{
    int T,cas=0;scanf("%d",&T);
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        for (int i=1;i<=k;i++) scanf("%d",&c[i].num),c[i].id=i;
        sort(c+1,c+1+k);
        flg=0;
        printf("Case #%d:\n",++cas);
        dfs(1,1,0);
        if (!flg) puts("NO");
        else 
        {
            puts("YES");
            print();
        }
    }
    return 0;
}
