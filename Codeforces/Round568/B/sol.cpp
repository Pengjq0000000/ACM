#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
int nums[maxn], numt[maxn];
char s[maxn], t[maxn], ss[maxn], tt[maxn];
int main()
{
	int n; scanf("%d", &n);
	while (n--)
	{
		scanf(" %s", s); scanf(" %s", t);
		int ls = strlen(s), lt = strlen(t);
		//for (int i = 0; i < max(ls, lt); i++) nums[i] = numt[i] = 0;
		int tots = 0, tott = 0;
		for (int i = 0; i < ls; i++)
		{
			if (i == 0) 
			{
				ss[tots++] = s[i];
				nums[tots - 1] = 1;
				continue;
			}
			if (s[i] != s[i - 1]) {ss[tots++] = s[i]; nums[tots - 1] = 1;}
			else if (s[i] == s[i - 1]) nums[tots - 1]++;
		}
		for (int i = 0; i < lt; i++)
		{
			if (i == 0) 
			{
				tt[tott++] = t[i];
				numt[tott - 1] = 1;
				continue;
			}
			if (t[i] != t[i - 1]) {tt[tott++] = t[i]; numt[tott - 1] = 1;}
			else if (t[i] == t[i - 1]) numt[tott - 1]++;
		}
		//printf("%s,%s\n", ss, tt);
		if (tots != tott) {puts("NO"); continue;}
		int flag = 1;
		for (int i = 0; i < tots; i++)
		{
			if (ss[i] != tt[i] || (ss[i] == tt[i] && nums[i] > numt[i]))
			{
				flag = 0;
				break;
			} 
		}
		if (flag) puts("YES");else puts("NO");
	}
	return 0;
}
