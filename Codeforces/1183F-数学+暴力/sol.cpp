#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 2e5 + 7;
set<int, greater<int> >s;
int main()
{
	int q; scanf("%d", &q);
	while (q--)
	{
		s.clear();
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			int x; scanf("%d", &x);
			s.insert(x);
		}
		int x = *s.begin();
		int ans = 0;
		if (s.find(x / 2) != s.end() && s.find(x / 3) != s.end() && s.find(x / 5) != s.end())
			if (x % 2 == 0 && x % 3 == 0 && x % 5 == 0)
					ans = max(ans ,x / 2 + x / 3 + x / 5);
		int cnt = 0;
		int sum = 0;
		while(!s.empty() && cnt < 3)
		{
			int now = *s.begin();
			//printf("%d\n", now);
			sum += now;
			cnt++;
			s.erase(now);
			for (int i = 2; i <= sqrt(now) + 1; i++)
			{
				if (now % i == 0) 
				{
					s.erase(i);
					if (s.find(i) != s.end()) s.erase(i);
					if (s.find(now / i) != s.end()) s.erase(now / i);
				}
			}
		}
		printf("%d\n", max(ans, sum));
	}
	return 0;
}
