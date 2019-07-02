#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
int a[maxn], b[maxn], posa[maxn], posb[maxn];
bool cmpa(int x, int y) {return a[x] == a[y] ? x > y : a[x] < a[y];}
bool cmpb(int x, int y) {return b[x] == b[y] ? x > y : b[x] < b[y];}
int n;
int c[maxn << 1];
inline int lowbit(int x) {return (x & (-x));}
void update(int x, int val)
{
	for (;x <= n; x += lowbit(x)) c[x] = max(c[x], val); 
}
int query(int x)
{
	int res = 0;
	for (; x; x -= lowbit(x)) res = max(res, c[x]);
	return res;
}

int main()
{
	int T; scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]), posa[i] = i;
		for (int i = 1; i <= n; i++) scanf("%d", &b[i]), posb[i] = i;
		for (int i = 0; i <= n; i++) c[i] = 0;
		sort(posa + 1, posa + 1 + n, cmpa);
		sort(posb + 1, posb + 1 + n, cmpb);
		int flag = 1;
		for (int i = 1; i <= n; i++)
		{
			if (a[posa[i]] != b[posb[i]]) {flag = 0; break;}
			if (query(posa[i]) > posb[i]) {flag = 0; break;}
			else update(posa[i], posb[i]);
		}
		if (flag) puts("YES"); else puts("NO");
	}
	return 0;
}
