#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e4 + 7;
char s[maxn];
set<char>vis;
int main()
{
	char ch; int L = 0;
	while (scanf("%c", &ch) != EOF)
	{
		if (ch == '\n' || ch == '\r') break;
		s[L++] = ch;
	}
	while (scanf("%c", &ch) != EOF)
	{
		vis.insert(ch);
	}
	for (int i = 0; i < L; i++)
	{
		if (!vis.count(s[i])) printf("%c", s[i]);
	}
	puts("");
	return 0;
}
