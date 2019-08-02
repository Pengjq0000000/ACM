#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m,q;
int a[3][10005];
int b[3][10005];
int c[1005][1005];
int fa[1005*1005];
int ans[10005];
int cnt;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
inline int calc(int x,int y)
{
	return (x-1)*m+y;
}
inline int find(int x)
{
	return fa[x]==x?fa[x]:fa[x]=find(fa[x]);
}
void merge(int x,int y,int nx,int ny)
{
	if(nx==0||nx==n+1) return;
	if(ny==0||ny==m+1) return;
	if(c[nx][ny]) return;
	int u=calc(x,y);
	int v=calc(nx,ny);
	u=find(u); v=find(v);
	if(u!=v)
	{
		fa[u]=v;
		cnt--;
	}
}
int main()
{
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=q;i++)
	{
		scanf("%d%d%d%d",&a[1][i],&b[1][i],&a[2][i],&b[2][i]);
		if(a[1][i]==a[2][i]) for(int j=b[1][i];j<=b[2][i];j++) c[a[1][i]][j]++;
		else if(b[1][i]==b[2][i]) for(int j=a[1][i];j<=a[2][i];j++) c[j][b[1][i]]++;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int u=calc(i,j);
			fa[u]=u;
			if(c[i][j]) continue;
			cnt++;
			int v,x,y;
			merge(i,j,i-1,j);
			merge(i,j,i,j-1);
		}
	}
	for(int i=q;i>=1;i--)
	{
		ans[i]=cnt;
		if(a[1][i]==a[2][i])
			for(int j=b[1][i];j<=b[2][i];j++)
			{
				c[a[1][i]][j]--;
				if(c[a[1][i]][j]==0)
				{
					cnt++;
					for(int k=0;k<4;k++)
						merge(a[1][i],j,a[1][i]+dx[k],j+dy[k]);
				}
			}
		else if(b[1][i]==b[2][i])
			for(int j=a[1][i];j<=a[2][i];j++) 
			{
				c[j][b[1][i]]--;
				if(c[j][b[1][i]]==0)
				{
					cnt++;
					for(int k=0;k<4;k++)
						merge(j,b[1][i],j+dx[k],b[1][i]+dy[k]);
				}
			}
	}
	for(int i=1;i<=q;i++)
		printf("%d\n",ans[i]);
	return 0;
}


