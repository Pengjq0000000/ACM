#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int n,m;
int a[505];
int now;
int b[2005][2005];
int main()
{
	scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d",&a[i]);
    m=n*2-1;
    for(int i=1;i<=m;i++)
        for(int j=1;j<=m;j++)
            b[i][j]=1;
    now=m-n+1;
    for(int i=1;i<=m;i++,now--)
    {
        if(now==0) now=m-n+1;
        for(int j=0;j<n;j++)
            b[i][now+j]=a[j];
    }
    now=m-n+1;
    for(int i=1;i<=m;i++,now--)
    {
        if(now==0) now=m-n+1;
        for(int j=0;j<n;j++)
            b[now+j][i]=a[j];
    }
    printf("%d\n",m);
    for(int i=1;i<=m;i++)
    {
        for(int j=1;j<=m;j++)
        {
            printf("%d ",b[i][j]);
        }
        printf("\n");
    }
	return 0;
}
