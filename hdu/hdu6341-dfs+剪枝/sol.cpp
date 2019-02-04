#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;

struct node {int x,y;node(){}node(int x,int y):x(x),y(y){}}pos[4][5][5];
int mp[20][20];
int visx[17][17],visy[17][17],tag[17][17];
int ans;
void ini()
{
    for (int i=1;i<=4;i++)
        for (int j=1;j<=4;j++)
            pos[0][i][j]=node(i,j);
    int xx=1,yy=0;
    for (int j=4;j>=1;j--)
        for (int i=1;i<=4;i++)
            {
                yy++;if (yy>4) xx++,yy=1;
                pos[1][i][j]=node(xx,yy);
            }
    for (int k=2;k<=3;k++)
        for (int i=1;i<=4;i++)
            for (int j=1;j<=4;j++)
            {
                pos[k][i][j].x=pos[k-1][pos[1][i][j].x][pos[1][i][j].y].x;
                pos[k][i][j].y=pos[k-1][pos[1][i][j].x][pos[1][i][j].y].y;
            }
    /*
    for (int k=0;k<4;k++)
    {
        for (int i=1;i<=4;i++)
        {
            for (int j=1;j<=4;j++) printf("%d %d,",pos[k][i][j].x,pos[k][i][j].y);
            printf("\n");
        }
        printf("\n");
    }
    */
}

void dfs(int x,int y,int cnt)
{
    if (cnt>=ans) return;
    if (y>4) {x++;y=1;}
    if (x>4)
    {
        ans=min(ans,cnt);
        return ;
    }
    
    int tmpx=4*(x-1),tmpy=4*(y-1);
    for (int k=0;k<4;k++)
        {
            for (int i=tmpx+1;i<=tmpx+4;i++)
                for (int j=tmpy+1;j<=tmpy+4;j++)
                    tag[i][j]=0;
            int flg=0;
            for (int i=tmpx+1;i<=tmpx+4;i++)
                for (int j=tmpy+1;j<=tmpy+4;j++)
                {
                   int xx=pos[k][i-tmpx][j-tmpy].x+tmpx;
                   int yy=pos[k][i-tmpx][j-tmpy].y+tmpy;
                    if (visx[i][mp[xx][yy]]) {flg=1;break;}
                    if (visy[j][mp[xx][yy]]) {flg=1;break;}
                    visx[i][mp[xx][yy]]=1;
                    visy[j][mp[xx][yy]]=1;
                    tag[i][j]=1;
                }
            if (!flg) dfs(x,y+1,cnt+k);
            for (int i=tmpx+1;i<=tmpx+4;i++)
                for (int j=tmpy+1;j<=tmpy+4;j++)
                {
                    int xx=pos[k][i-tmpx][j-tmpy].x+tmpx;
                    int yy=pos[k][i-tmpx][j-tmpy].y+tmpy;
                    if (tag[i][j]) 
                        visx[i][mp[xx][yy]]=visy[j][mp[xx][yy]]=tag[i][j]=0;
                }
        }
}

int main()
{
    ini();
    int T;scanf("%d",&T);
    while (T--)
    {
        for (int i=1;i<=16;i++)
            for (int j=1;j<=16;j++)
            {
                char c;scanf(" %c",&c);
                if ('0'<=c && c<='9') mp[i][j]=c-'0';
                else mp[i][j]=c-'A'+10;
            }
        ans=1e9;
        dfs(1,1,0);
        printf("%d\n",ans);
    }
    return 0;
}
