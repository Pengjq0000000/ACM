#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int a[1007];
int main()
{
	int n; scanf("%d", &n);
	char ch; scanf(" %c", &ch);
	int now = 0;
	while (1)
	{
		++now; a[now] = 2 * now - 1;
		if (2 * now * now - 1 > n) break;
	}
	int blank = 0;
	for (int i = now - 1; i > 1; i--)
	{
		for (int j = 0; j < blank; j++) printf(" ");
		for (int j = 0; j < a[i]; j++) printf("%c", ch); n -= a[i];
		//for (int j = 0; j < blank; j++) printf(" ");
		blank++; puts("");
	}
	for (int i = 1; i < now; i++)
	{
		for (int j = 0; j < blank; j++) printf(" ");
		for (int j = 0; j < a[i]; j++) printf("%c", ch); n -= a[i];
		//for (int j = 0; j < blank; j++) printf(" ");
		blank--; puts("");
	}
	now--;
	printf("%d\n", n);
	return 0;
}
