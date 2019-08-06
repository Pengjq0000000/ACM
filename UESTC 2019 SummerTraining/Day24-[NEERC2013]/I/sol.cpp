#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,k;
char a[4000005];
int b[5005];
int len,now;
int num;
int c[5005];
struct edge
{
	int to,next;
}e[250005];
int cnt;
int head[5005];
void ins(int u,int v)
{
	cnt++;
	e[cnt].to=v;
	e[cnt].next=head[u];
	head[u]=cnt;
}
bool is_num(char x)
{
	if('0'<=x&&x<='9') return 1;
	return 0;
}
void deal()
{
	int x=0;
	bool sign=0;
	while(a[now]==' ') now++;
	if(now>=len) return;
	while(is_num(a[now]))
	{
		x=x*10+a[now]-'0';
		now++;
		sign=1;
	}
	if(sign) c[++num]=x;
	now++;
}
bitset<5005>dp[5005];
bool vis[5005];
void dfs(int u)
{
	dp[u][u]=1;
	vis[u]=1;
	for(int i=head[u];i;i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v]) dfs(v);
		dp[u]|=dp[v];
	}
}
int ans,id;
int cal(int x)
{
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(dp[x][i]==1) cnt++;
	return cnt;
}
int main()
{
	freopen("i.in","r",stdin);
	scanf("%d%d",&n,&k);
	for(int i=1;i<=k;i++)
		scanf("%d",&b[i]);
	for(int i=1;i<=n;i++)
	{
		int tmp;
		scanf(" %d",&tmp);
		cin.getline(a,4e6,'\n');
		len=strlen(a);
		now=0; num=0;
		while(now<len) deal();
		int u,v;
		for(int j=1;j<=num;j++)
		{
			u=tmp; v=c[j];
			ins(u,v);
		}
		/*printf("%d",tmp);
		for(int j=1;j<=num;j++)
			printf(" %d",c[j]);
		printf("\n");*/
	}
	for(int j=1;j<=k;j++)
	{
		int v=b[j];
		if(!vis[v]) dfs(v);
		int count=cal(v);
		if(ans<count)
		{
			ans=count;
			id=v;
		}
		else if(ans==count) id=min(id,v);
	}
	//printf("%d\n",ans);
	printf("%d\n",id);
	return 0;
}


