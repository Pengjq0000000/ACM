#include<iostream>
#include<algorithm>
#include<cmath>
#define LL long long
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back

using namespace std;

int c[107][107];
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        int n;scanf("%d",&n);
        for (int i=1;i<=n;i++)
            for (int j=1;j<=n;j++)
                scanf("%d",&c[i][j]);
        for (int i=1;i<=n;i++)
        {
            c[i][0]=1-c[i][1];
            c[i][n+1]=1-c[i][n];
            c[0][i]=1-c[1][i];
            c[n+1][i]=1-c[n][i];
        }
        int flg=0;
        for (int i=1;i<=n;i++)
        {
            if (flg) break;
            for (int j=1;j<=n;j++) 
            {
                if (flg) break;
                for (int k=0;k<4;k++)
                {
                    int x=i+dx[k],y=j+dy[k];
                    if (c[x][y]==c[i][j])
                    {
                        flg=1;break;
                    }
                }
            }
        }
        if (flg) puts("No");
        else puts("Yes");
    }
    return 0;
}
