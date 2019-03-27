#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
const int det = 10000;
int hp[10007], pos[200007];
int cnt = 0;
void add(int x)
{
	++cnt;
	hp[cnt] = x; pos[x] = cnt;
	int now = cnt;
	while (now > 1 && hp[now] < hp[now / 2])
	{
		swap(pos[hp[now]], pos[hp[now / 2]]);
		swap(hp[now], hp[now / 2]);
		now /= 2;
	}
}
int main()
{
	int n, m; scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		int x; scanf("%d", &x); x += det;
		add(x);
	}
	//for (int i = 1; i <= n; i++) printf("%d ", hp[i]);puts("");
	while (m--)
	{
		int x, y; scanf("%d", &x); x += det;
		string a, b, c, d; cin >> a >> b >> c;
		if ((b[0] >= '0' && b[0] <= '9') || (b[0] == '-'))
		{
			cin >> d; y = stoi(b); y += det;
			if (abs(pos[x] - pos[y]) == 1 && min(pos[x], pos[y]) % 2 == 0) puts("T");
			else puts("F");
			continue;
		}
		if (c == "root") 
		{
			if (pos[x] == 1) puts("T");else puts("F");
		}
		else if (c == "parent")
		{
			cin >> d; scanf("%d", &y); y += det;
			if (pos[x] == pos[y] / 2) puts("T");else puts("F");
		}
		else if (c == "child")
		{
			cin >> d; scanf("%d", &y); y += det;
			if (pos[x] / 2 == pos[y]) puts("T");else puts("F");
		}
	}
	return 0;
}
