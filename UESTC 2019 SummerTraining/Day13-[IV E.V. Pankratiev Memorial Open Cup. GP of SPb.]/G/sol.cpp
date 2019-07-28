#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int T;
int n1,m1,n2,m2;
int a1,b1,a2,b2;
int dx[8]={1,2,2,1,-1,-2,-2,-1};
int dy[8]={-2,-1,1,2,2,1,-1,-2};
int dp[55][55];
int num[8][55][55];
const int inf=1e9;
void dfs(int x,int y,int t,int px,int py,int k)
{
	if(dp[x][y]>t)
	{
		dp[x][y]=t;
		for(int i=0;i<8;i++)
			num[i][x][y]=num[i][px][py];
		num[k][x][y]++;
	}
	if(t==5) return;
	for(int i=0;i<8;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<15||ny<15) continue;
		if(nx>25||ny>25) continue;
		dfs(nx,ny,t+1,x,y,i);
	}
}
int ANS[8],ans,AANS,used[8];
int t1,t2,t3;
int deal(int sx,int sy,int tx,int ty){
	//cout<<sx<<" "<<sy<<" "<<tx<<" "<<ty<<endl;
	int a,b;
	memset(used,0,sizeof used);
	if(ty-sy>=0&&tx-sx>=0){
		if(ty-sy>=tx-sx){
			t1=3;t2=4;
			t3=2;
			a=ty-sy;
			b=tx-sx;
		}
		else{
			t1=2;t2=1;
			t3=3;
			b=ty-sy;
			a=tx-sx;
		}
	}
	else if(ty-sy>=0&&tx-sx<0){
		if(ty-sy>=sx-tx){
			t1=4;t2=3;
			t3=5;
			a=ty-sy;
			b=-tx+sx;
		}
		else{
			t1=5;t2=6;
			t3=4;
			b=ty-sy;
			a=-tx+sx;
		}
	}
	
	else if(ty-sy<0&&tx-sx<0){
		if(-ty+sy>=sx-tx){
			t1=7;t2=0;
			t3=6;
			a=-ty+sy;
			b=-tx+sx;
		}
		else{
			t1=6;t2=5;
			t3=7;
			b=-ty+sy;
			a=-tx+sx;
		}
	}
	else{
		if(-ty+sy>=tx-sx){
			t1=0;t2=7;
			t3=1;
			a=-ty+sy;
			b=tx-sx;
		}
		else{
			t1=1;t2=2;
			t3=0;
			b=-ty+sy;
			a=tx-sx;
		}
	}
	if(a==0&&b==0){
		return 0;
	}
	//cout<<a<<" "<<b<<endl;
	if(a>=b*2){
		if((a-(b*2))%4)
			return inf;
		used[t1]=b+(a-(b)*2)/4;
		used[t2]=(a-(b)*2)/4;
		//if(a==99&&b==3)cout<<used[t1]<<" "<<used[t2]<<endl;
		return b+(a-(b)*2)/2;
	}
	else{
		if((a+b)%3) return inf;
		if(((a+b)/3+a-b)%2) return inf;
		if(((a+b)/3+b-a)%2) return inf;
		used[t1]=((a+b)/3+a-b)/2;
		used[t3]=((a+b)/3+b-a)/2;
		return ((a+b)/3+a-b)/2+((a+b)/3+b-a)/2;
	}
}
int main()
{
	freopen("ndist.in","r",stdin);
	freopen("ndist.out","w",stdout);
	memset(dp,63,sizeof dp);
	dp[20][20]=0;
	dfs(20,20,0,0,0,0);
	/*
	for(int i=0;i<8;i++)
		printf("%d ",num[i][-2+20][1+20]);
	printf("\n");
	*/
	/*
	for(int i=15;i<=25;i++)
	{
		for(int j=15;j<=25;j++)
			printf("%d,",dp[i][j]);
		printf("\n");
	}
	*/
	scanf("%d",&T);
	while(T--)
	{
		int ans=inf;
		scanf("%d%d%d%d",&n1,&m1,&n2,&m2);
		a1=n1; b1=m1; a2=n2; b2=m2;
		for(int i=15;i<=25;++i){
			for(int j=15;j<=25;++j){
				int tmp=deal(n1+i-20,m1+(j-20),n2,m2);
				if(dp[i][j]+tmp<ans){
					//cout<<"START::"<<n1+i-20<<" "<<m1+(j-20)<<endl;
					//cout<<"START::"<<i<<" "<<j<<endl;
					//for(int kk=0;kk<8;++kk)
					//	cout<<num[kk][i][j];
					//cout<<endl;
					ans=dp[i][j]+tmp;
					for(int k=0;k<8;++k){
						ANS[k]=used[k]+num[k][i][j];
					}
				}
			}
		}
		AANS=0;
		for(int i=0;i<8;++i)
			if(ANS[i]) ++AANS;
		printf("%d %d\n",ans,AANS);
		for(int i=0;i<8;++i){
			if(!ANS[i])continue;
			printf("%d %d %d\n",dx[i],dy[i],ANS[i]);
		}
	}
	return 0;
}


