#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node
{
	int x, y, id; 
	node(int x, int y, int id) : x(x), y(y), id(id) {}
	node(){}
	bool operator < (const node &rhs) const
	{
		if (x == rhs.x) return y < rhs.y;
		return x < rhs.x;
	}
}p[maxn];
int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		int n; scanf("%d", &n);
		for (int i = 1; i <= 3 * n; i++)
		{
			int x, y; scanf("%d%d", &x, &y);
			p[i] = node(x, y, i);
		}
		sort(p + 1, p + 1 + 3 * n);
		for (int i = 1; i <= 3 * n; i += 3)
		{
			printf("%d %d %d\n", p[i].id, p[i + 1].id, p[i + 2].id);
		}
	}
	return 0;
}
