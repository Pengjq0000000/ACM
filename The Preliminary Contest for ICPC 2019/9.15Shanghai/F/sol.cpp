#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
__int128 aa;bool bb;char ch;
__int128 scan()
{
	while(ch=getchar(),(ch<'0'||ch>'9')&&ch!='-');
	ch=='-'?(bb=1,aa=0):(bb=0,aa=ch-48);
	while(ch=getchar(),(ch>='0'&&ch<='9'))
		aa=aa*10+ch-48;
	return (bb?(-aa):(aa));
}
__int128 n;
__int128 m;
__int128 dp[30][30];
vector<char>v;
int main()
{
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
        n=scan(); m =scan();
		memset(dp,0,sizeof dp);
		for(int j=1;j<=n;j++)
			dp[0][j]=1;
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n-i;j++)
				dp[i][j]+=dp[i-1][j]*j+dp[i-1][j+1];
		//printf("%lld\n",dp[n-1][1]);
		printf("Case #%d: ",cas);
		if(m==dp[n-1][1])
		{
			for(int i=0;i<n;i++)
				printf("%c",'A'+i);
		}
		else
		{
			v.clear();
			v.push_back('A');
			int now=1;
			for(int i=n-2;i>=0;i--)
			{
				for(int j=0;j<=now;j++)
				{
					if(j==now)
					{
						now++;
						v.push_back('A'+j);
						break;
					}
					else
					{
						if(m>dp[i][now]) m-=dp[i][now];
						else if(m<=dp[i][now])
						{
							v.push_back('A'+j);
							break;
						}
					}
				}
			}
			for(int i=0;i<v.size();i++)
				printf("%c",v[i]);
		}
		printf("\n");
	}
	return 0;
}


