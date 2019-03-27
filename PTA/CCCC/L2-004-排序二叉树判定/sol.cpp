#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
bool flag;
int a[maxn], n, l[maxn], r[maxn];
vector<int>ans;
int dfs(int st, int ed)
{
	if (st > ed) return 0;
	if (st == ed) return st;
	int mid = st + 1;
	if (flag)
	{
		while (a[mid] < a[st] && mid < ed) mid++;
		if (a[mid] >= a[st]) mid--;
		l[st] = dfs(st + 1, mid);
		for (int i = mid + 1; i <= ed; i++) 
			if (a[i] < a[st]) {printf("NO\n"); exit(0);}
		r[st] = dfs(mid + 1, ed);
	}
	else
	{
		while (a[mid] >= a[st] && mid < ed) mid++;
		if (a[mid] < a[st]) mid--;
		l[st] = dfs(st + 1, mid);
		for (int i = mid + 1; i <= ed; i++) 
			if (a[i] >= a[st]) {printf("NO\n"); exit(0);}
		r[st] = dfs(mid + 1, ed);
	}
	return st;
}
void print(int x)
{
	if (l[x]) print(l[x]);
	if (r[x]) print(r[x]);
	ans.pb(a[x]);
}
int main()
{
	scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	flag = (a[1] > a[2]);
	dfs(1, n);
	puts("YES");
	print(1);
	for (int i = 0; i < ans.size(); i++) 
	{
		if (i == 0) printf("%d", ans[i]);
		else printf(" %d", ans[i]);
	}
	puts("");
	
	return 0;
}
