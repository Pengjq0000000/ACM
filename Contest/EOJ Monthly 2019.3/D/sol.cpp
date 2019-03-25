#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int dx[4]={0, 0, 1, -1};
int dy[4]={1, -1, 0, 0};
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
	int tmp = abs(a - c) + abs(b - d);
	if (tmp & 1) puts("Lose");else puts("Win");
	return 0;
}
