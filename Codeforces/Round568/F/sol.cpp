#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = (1 << 9);
const int INF = 1e9 + 2;
int num[maxn];
pii cost[maxn][2];
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 0; i < maxn; i++) cost[i][0].fir = cost[i][1].fir = INF;
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x);
		int sta = 0;
		for (int j = 1; j <= x; j++)
		{
			int y; scanf("%d", &y); y--;
			sta |= (1 << y);
		}
		for (int bits = 0; bits < maxn; bits++)
		{
			if ((bits | sta) == bits) num[bits]++;
		}
	}
	for (int i = 1; i <= m; i++)
	{
		int x, ct; scanf("%d%d", &ct, &x);
		int sta = 0;
		for (int j = 1; j <= x; j++)
		{
			int y; scanf("%d", &y); y--;
			sta |= (1 << y);
		}
		if (ct < cost[sta][0].fir) {cost[sta][1] = cost[sta][0]; cost[sta][0] = make_pair(ct, i);}
		else if (ct < cost[sta][1].fir) cost[sta][1] = make_pair(ct, i);
	}
	pii ans = make_pair(0, 2e9 + 7);
	pii res, tmp;
	for (int A = 0; A < maxn; A++)
		for (int B = 0; B < maxn; B++)
		{
			if (cost[A][0].fir == INF || cost[B][0].fir == INF) continue;
			if (A == B && (cost[A][1].sec == INF)) continue;
			int C = (A | B);
			pii now = make_pair(-num[C], 0);
			if (A == B) 
			{
				now.sec = cost[A][0].fir + cost[A][1].fir;
				tmp = make_pair(cost[A][0].sec, cost[A][1].sec);
			}
			else 
			{
				now.sec = cost[A][0].fir + cost[B][0].fir; 
				tmp = make_pair(cost[A][0].sec, cost[B][0].sec);
			}
			if (now < ans)
			{
				ans = now;
				res = tmp;
			}
		}
	printf("%d %d\n", res.fir, res.sec);
	return 0;
}
