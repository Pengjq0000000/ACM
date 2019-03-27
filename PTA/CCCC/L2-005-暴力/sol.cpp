#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
set<int>s[55];
double cal(int x, int y)
{
	if (s[x].size() > s[y].size()) swap(x, y);
	double cnt1 = 0, cnt2 = s[y].size();
	for (int tmp : s[x])
	{
		if (s[y].count(tmp)) cnt1++;else cnt2++;
	}
	return (cnt1 * 100.00 / cnt2);
}
int main()
{
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) 
	{
		int x; scanf("%d", &x);
		while (x--)
		{
			int tmp; scanf("%d", &tmp);
			s[i].insert(tmp);
		}
	}
	int m; scanf("%d", &m);
	while (m--)
	{
		int x, y; scanf("%d%d", &x, &y);
		printf("%.2lf%\n", cal(x, y));
	}
	return 0;
}
