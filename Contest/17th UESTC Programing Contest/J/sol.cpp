#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3007;
int a[maxn][maxn], mp[maxn][maxn];
int n, m, r[maxn][maxn];
void Manacher(int row)
{
	int len = (m << 1);
	int idx = 0, rig = 0;
	MEM(r[row], 0);
	for (int i = 0; i < len; i++)
	{
		if (i <= rig) r[row][i] = min(r[row][idx * 2 - i], rig - i);
		while (i - r[row][i] > 0 && i + r[row][i] < len 
				&& a[row][i - r[row][i] - 1] == a[row][i + r[row][i] + 1]) r[row][i]++;
		if (i + r[row][i] > rig) {rig = i + r[row][i]; idx = i;}
	}
}
void print()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (m << 1 | 1); j++) printf("%d ", a[i][j]); puts("");
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < (m << 1 | 1); j++) printf("%d ", r[i][j]); puts("");
	}
}
int tmp[maxn], tot = 0;
int lpos[maxn], rpos[maxn];
stack<int>st;
int getans()
{
	while (!st.empty()) st.pop();
	for (int i = 0; i < tot; i++)
	{
		while (!st.empty() && tmp[st.top()] >= tmp[i]) st.pop();
		if (st.empty()) lpos[i] = 0; else lpos[i] = st.top() + 1;
		st.push(i);		
	}
	while (!st.empty()) st.pop();
	for (int i = tot - 1; i >= 0; i--)
	{
		while (!st.empty() && tmp[st.top()] >= tmp[i]) st.pop();
		if (st.empty()) rpos[i] = tot - 1; else rpos[i] = st.top() - 1;
		st.push(i);
	}
	int res = 0;
	for (int i = 0; i < n; i++)
	{
		res = max(res, tmp[i] * (rpos[i] - lpos[i] + 1));
	}
	return res;
}
int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			a[i][j << 1] = 2e9;
			scanf("%d", &a[i][j << 1 | 1]);
		}
		a[i][m << 1] = 2e9;
		Manacher(i);
	}
	//print();
	int ans = 0;
	for (int j = 0; j < (m << 1); j ++)
	{
		tot = 0;
		for (int i = 0; i < n; i++) tmp[tot++] = r[i][j];
		ans = max(ans, getans());
	}
	printf("%d\n", ans);
	return 0;
}


