#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n;
int a[105],b[105];
int c[105][105][105];
int check(int x)
{
    if(x==0||x==2) return 1;
    return 0;
}
int main()
{
	int L,n;
    scanf("%d%d",&L,&n);
    for(int i=1;i<=n;i++)
        scanf("%d%d",&a[i],&b[i]);
    for(int i=1;i<=n;i++)
        c[1][a[i]][b[i]]=1;
    for(int k=1;k<=L-1+1;k++)
    {
        for(int j=1;j+k<=L-1+2;j++)
            printf("%d ",c[1][j][k]);
        printf("\n");
    }
    for(int i=2;i<=L;i++)
    {
        for(int k=1;k<=L-i+1;k++)
            for(int j=1;j+k<=L-i+2;j++)
                c[i][j][k]=check(c[i-1][j][k]+c[i-1][j][k]+c[i-1][j+1][k+1]);
                
        for(int k=1;k<=L-i+1;k++)
        {
            for(int j=1;j+k<=L-i+2;j++)
                printf("%d ",c[i][j][k]);
            printf("\n");
        }
    }
	return 0;
}
