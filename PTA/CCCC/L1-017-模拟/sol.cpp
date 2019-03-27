#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char s[57];
int main()
{
	double base = 1, cnt = 0;
	scanf("%s", s);
	int L = strlen(s);
	if (s[0] == '-') base *= 1.5;
	if ((s[L - 1] - '0') % 2 == 0) base *= 2.0;
	for (int i = 0; i < L; i++) if (s[i] == '2') cnt++; 
	if (s[0] == '-') L--;
	double ans = cnt / (double) L * base;
	printf("%.2lf%\n", ans * 100.00);
	return 0;
}
