#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
	int n; char ch;
	scanf("%d %c", &n, &ch);
	for (int i = 1; i <= (n + 1) / 2; i++)
	{
		for (int j = 1; j <= n; j++) printf("%c", ch);
		puts("");
	}
	return 0;
}
