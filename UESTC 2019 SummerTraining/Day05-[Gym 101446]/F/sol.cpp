#include<bits/stdc++.h>
#define mod 1000000007
#define MOD(x) ((x)%mod)
#define pii pair<int,int>
#define mp(a,b) make_pair(a,b)
using namespace std;
int n,m;
int main()
{
	scanf("%d",&n);
	char s[1007];
	for (int i = 1; i <= n * (n - 1) / 2; i++)
	{
		int u, v; 	
		scanf("%d %d %s", &u, &v, s);
		if (strlen(s) == 1)
		{
			printf("%d %d %s\n", u, v, s);
		}
	} 
	return 0;
}