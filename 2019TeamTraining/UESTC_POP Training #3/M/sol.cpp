#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pc push_cack
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n,m,k;
int p[5];
int pos[5];
int ma[2005][2005];
int sum[2005][2005];
int r[2005],c[2005];
int ans;
int inv;
int lb;//left boundary
int rb;//right boundary
int up;//upper boundary
int low;//lower boundary
int a1,a2,b1,b2;
int now;
int check()
{
	now=lb;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=rb) continue;
		if(sum[a1][x]-sum[a1][lb]-(sum[a1-1][x]-sum[a1-1][lb])>0) continue;
		now=x;
	}
	b1=now+1;

	now=lb;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=rb) continue;
		if(sum[a2][x]-sum[a2][lb]-(sum[a2-1][x]-sum[a2-1][lb])>0) continue;
		now=x;
	}
	b2=now+1;
	if(pos[2]<pos[3]&&b1>=b2) return 0; 
	if(pos[2]>pos[3]&&b1<=b2) return 0;
	//printf("lb:%d rb:%d up:%d low:%d\n",lb,rb,up,low);
	return 1;
}
int double_up()
{
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=2) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=0) return 0;
	if(sum[up-1][rb-1]-sum[up-1][lb]<2) return 0;
	int num=sum[up-1][rb-1]-sum[up-1][lb];
	if(num<2) return 0;

	now=0;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=up) continue;
		if(sum[x][rb-1]-sum[x][lb]>num-2) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=up) continue;
		if(sum[x][rb-1]-sum[x][lb]>num-1) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;
	if(a1==a2) return 0;
	
	if(sum[up-1][rb]-sum[up-1][lb-1]-(sum[a1-1][rb]-sum[a1-1][lb-1])!=2) return 0;
	return check();
}
int double_mid()
{
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=4) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=2) return 0;
	int num=sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb];
	if(num!=2) return 0;

	now=up;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=low) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[up][rb-1]-sum[up][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=low) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[up][rb-1]-sum[up][lb])>1) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;
	if(a1==a2) return 0;

	return check();
}
int double_below()
{
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=2) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=0) return 0;
	if(sum[n][rb-1]-sum[n][lb]-(sum[low][rb-1]-sum[low][lb])<2) return 0;
	int num=sum[n][rb-1]-sum[n][lb]-(sum[low][rb-1]-sum[low][lb]);
	if(num<2) return 0; 

	now=low;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>n) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[low][rb-1]-sum[low][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>n) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[low][rb-1]-sum[low][lb])>1) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;
	if(a1==a2) return 0;

	if(sum[a2][rb]-sum[a2][lb-1]-(sum[low][rb]-sum[low][lb-1])!=2) return 0;
	return check();
}
int up_mid()
{
	if(sum[up-1][rb-1]-sum[up-1][lb]==0) return 0;
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=3) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=1) return 0;
	
//
	int num=sum[up-1][rb-1]-sum[up-1][lb];
	now=0;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=up) continue;
		if(sum[x][rb-1]-sum[x][lb]>num-1) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;

	num=sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb];
	now=up;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=low) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[up][rb-1]-sum[up][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;

	if(sum[up-1][rb]-sum[up-1][lb-1]-(sum[a1-1][rb]-sum[a1-1][lb-1])!=1) return 0;
	return check();
//
}
int mid_below()
{
	if(sum[n][rb-1]-sum[n][lb]-sum[low][rb-1]+sum[low][lb]==0) return 0;
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=3) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=1) return 0;
//
	int num=sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb];
	now=up;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=low) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[up][rb-1]-sum[up][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;

	num=sum[n][rb-1]-sum[n][lb]-(sum[low][rb-1]-sum[low][lb]);
	now=low;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>n) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[low][rb-1]-sum[low][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;

	if(sum[a2][rb]-sum[a2][lb-1]-(sum[low][rb]-sum[low][lb-1])!=1) return 0;
	return check();
//
}
int two_side()
{
	if(sum[up-1][rb-1]-sum[up-1][lb]==0) return 0;
	if(sum[n][rb-1]-sum[n][lb]-sum[low][rb-1]+sum[low][lb]==0) return 0;
	if(sum[low][rb]-sum[low][lb-1]-sum[up-1][rb]+sum[up-1][lb-1]!=2) return 0;
	if(sum[low-1][rb-1]-sum[low-1][lb]-sum[up][rb-1]+sum[up][lb]!=0) return 0;
//
	int num=sum[up-1][rb-1]-sum[up-1][lb];
	now=0;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>=up) continue;
		if(sum[x][rb-1]-sum[x][lb]>num-1) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a1=now+1;

	num=sum[n][rb-1]-sum[n][lb]-(sum[low][rb-1]-sum[low][lb]);
	now=low;
	for(int i=1024;i>=1;i>>=1)
	{
		int x=now+i;
		if(x>n) continue;
		if(sum[x][rb-1]-sum[x][lb]-(sum[low][rb-1]-sum[low][lb])>0) continue;
		now=x;
	}
	if(sum[now+1][rb-1]-sum[now+1][lb]-(sum[now][rb-1]-sum[now][lb])!=1) return 0;
	a2=now+1;

	if(sum[up-1][rb]-sum[up-1][lb-1]-(sum[a1-1][rb]-sum[a1-1][lb-1])!=1) return 0;
	if(sum[a2][rb]-sum[a2][lb-1]-(sum[low][rb]-sum[low][lb-1])!=1) return 0;
	return check();
//
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d%d",&n,&m,&k);
		for(int i=1;i<=4;i++)
		{
			scanf("%d",&p[i]);
			pos[p[i]]=i;
		}
		if(pos[1]>pos[4]) inv=1;
		else inv=0; 
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d",&r[i],&c[i]);
			ma[r[i]][c[i]]=1;
		}
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+ma[i][j];
		for(int i=1;i<=k;i++)
		{
			for(int j=1;j<=k;j++)
			{
				if(c[i]>=c[j]) continue;
				if(r[i]==r[j]) continue;
				int a=min(pos[2],pos[3]);
				int b=max(pos[2],pos[3]);
				if(!inv)
				{
					lb=c[i];
					rb=c[j];
					up=r[i];
					low=r[j];
					if(a<pos[1]&&b<pos[1]) ans+=double_up();
					else if(a<pos[1]&&b>pos[1]&&b<pos[4]) ans+=up_mid();
					else if(a<pos[1]&&b>pos[4]) ans+=two_side();
					else if(a>pos[1]&&a<pos[4]&&b>pos[4]) ans+=mid_below();
					else if(a>pos[4]&&b>pos[4]) ans+=double_below();
					else if(a>pos[1]&&a<pos[4]&&b>pos[1]&&b<pos[4]) ans+=double_mid();
					//printf("%d %d %d\n",ans,i,j);
				}
				else
				{
					lb=c[i];
					rb=c[j];
					up=r[j];
					low=r[i];
					if(a<pos[4]&&b<pos[4]) ans+=double_up();
					else if(a<pos[4]&&b>pos[4]&&b<pos[1]) ans+=up_mid();
					else if(a<pos[4]&&b>pos[1]) ans+=two_side();
					else if(a>pos[4]&&a<pos[1]&&b>pos[1]) ans+=mid_below();
					else if(a>pos[1]&&b>pos[1]) ans+=double_below();
					else if(a>pos[4]&&a<pos[1]&&b>pos[4]&&b<pos[1]) ans+=double_mid();
					//printf("%d %d %d\n",ans,i,j);
				}
			}
		}
		printf("%d\n",ans);
		ans=0;
		for(int i=1;i<=k;i++)
			ma[r[i]][c[i]]=0;
	}
	return 0;
}
