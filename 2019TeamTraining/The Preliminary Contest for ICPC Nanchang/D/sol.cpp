#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char s[1007];
int table[10] = {6, 2, 5, 5, 4, 5, 6, 3, 7, 6};
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n, cnt = 0; scanf("%d", &n);
		scanf("%s", s);
		for (int i = 0; i < n; i++)
		{
			if (s[i] == '+') cnt += 2;
			else if (s[i] == '-') cnt++;
			else cnt += table[s[i] - '0'];
		}
		printf("%d\n", cnt);
	}
	return 0;
}
