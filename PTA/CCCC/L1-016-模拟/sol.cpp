#include<bits/stdc++.h>
#define LL long long
#define MEM(x, y) memset(x, y, sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int t[18] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
int M[11] = {1, 0, 10, 9, 8, 7, 6, 5, 4, 3, 2};
char s[107][20];
vector<int>wa;
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf(" %s", s[i]); int L = strlen(s[i]);
		int res = 0;
		for (int j = 0; j < L - 1; j++)
		{
			int tmp = s[i][j] - '0';
			if (s[i][j] == 'X') {wa.pb(i); res = -1; break;}
			res += tmp * t[j];
		}
		if (res == -1) continue;
		int tmp = s[i][L - 1] - '0';
		if (s[i][L - 1] == 'X') tmp = 10;
		if (M[res % 11] != tmp) wa.pb(i);
	}
	for (int pos : wa) printf("%s\n", s[pos]);
	if (!wa.size()) puts("All passed");
	return 0;
}
