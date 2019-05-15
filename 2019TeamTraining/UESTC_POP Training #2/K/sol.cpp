#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 505;
char s[maxn];
bool isnum(char x)
{
	return (x >= '0' && x <= '9');
}
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf(" %s", s);
		int L = strlen(s);
		int flag = 0;
		for (int i = 0; i < L; i++)
		{
			if (s[i] == '?')
			{
				if (i > 0 && s[i - 1] == '0' && ((i > 1 && !isnum(s[i - 2])) || (i <= 1))) s[i] = '+';
				else s[i] = '1';
			}
			if (i > 0 && isnum(s[i]) && s[i - 1] == '0' && ((i > 1 && !isnum(s[i - 2])) || (i <= 1))) 
			{
				flag = 1;
				break;
			}
			if (i > 0 && !isnum(s[i]) && !isnum(s[i - 1]))
			{
				flag = 1;
				break;
			} 
		}
		if (!isnum(s[0]) || !isnum(s[L - 1])) flag = 1;
		if (flag) puts("IMPOSSIBLE");
		else printf("%s\n", s);
	}	
	return 0;
}
