#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
char c[2005][2005];
int vis[2005][2005];
int cas;
int dfs(int i,int j)
{
	vis[i][j]=cas;
	if(c[i][j]=='^'&&c[i+1][j+1]=='v'&&vis[i+1][j+1]<cas) return dfs(i+1,j+1)+1;
	if(c[i][j]=='v'&&c[i-1][j+1]=='^'&&vis[i-1][j+1]<cas) return dfs(i-1,j+1)+1;
	if(c[i][j]=='<'&&c[i+1][j+1]=='>'&&vis[i+1][j+1]<cas) return dfs(i+1,j+1)+1;
	if(c[i][j]=='>'&&c[i+1][j-1]=='<'&&vis[i+1][j-1]<cas) return dfs(i+1,j-1)+1;
	return 1;
}
bool check(int i,int j)
{
	if(vis[i][j]==cas) return 1;
	if(c[i][j]=='^'&&c[i+1][j-1]=='v'&&vis[i+1][j-1]<cas) return 1;
	if(c[i][j]=='v'&&c[i-1][j-1]=='^'&&vis[i-1][j-1]<cas) return 1;
	if(c[i][j]=='<'&&c[i-1][j+1]=='>'&&vis[i-1][j+1]<cas) return 1;
	if(c[i][j]=='>'&&c[i-1][j-1]=='<'&&vis[i-1][j-1]<cas) return 1;
	return 0;
}
int main()
{
	
	while(~scanf("%d%d",&n,&m))
	{
		cas++;
		for(int i=0;i<=n+1;i++)
			for(int j=0;j<=m+1;j++)
				c[i][j]=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				scanf(" %c",&c[i][j]);
		int ans=0;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			{
				if(check(i,j)) continue;
				ans+=dfs(i,j)/3;
			}
		printf("%d\n",ans);
	}
	return 0;
}