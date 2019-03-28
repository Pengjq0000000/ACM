#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int n, lrd[maxn], ldr[maxn];
int l[maxn], r[maxn];
int dfs(int lrd_st, int lrd_ed, int ldr_st, int ldr_ed)
{
	if (lrd_st > lrd_ed) return 0;
	if (lrd_st == lrd_ed) return lrd[lrd_st]; 
	int rt = lrd[lrd_ed];
	for (int i = ldr_st; i <= ldr_ed; i++)
		if (ldr[i] == rt)
		{
			int cnt = i - ldr_st;
			l[rt] = dfs(lrd_st, lrd_st + cnt - 1, ldr_st, i - 1);
			r[rt] = dfs(lrd_st + cnt, lrd_ed - 1, i + 1, ldr_ed);
		}
	return rt;
}
queue<int>q;
int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) scanf("%d", &lrd[i]);
	for (int i = 1; i <= n; i++) scanf("%d", &ldr[i]);
	int root;
	printf("%d", root = dfs(1, n, 1, n));
	q.push(root);
	while (!q.empty())
	{
		int x = q.front();q.pop();
		if (x != root) printf(" %d", x);
		if (l[x]) q.push(l[x]); 
		if (r[x]) q.push(r[x]);
	}
	return 0;
}
