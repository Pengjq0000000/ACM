#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
#define ll long long
#define inf 0x3f3f3f3f
using namespace std;
int n,m;
int f[1000002][9];
int s[1000002][9];
void ini()
{
	for(int i=1;i<=1000000;i++)
	{
		for(int j=2;j<=10;j++)
		{
			int k=j-2;
			f[i][k]=f[i/j][k]+i%j;
			s[i][k]=s[i-1][k]+f[i][k];
		}
	}
}
int main()
{
	ini();
	int T,cas=0;
	scanf("%d",&T);
	while(T--)
	{
		cas++;
		scanf("%d%d",&n,&m);
		printf("Case #%d: %d\n",cas,s[n][m-2]);
	}
	return 0;
}


