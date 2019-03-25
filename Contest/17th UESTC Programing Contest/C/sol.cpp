#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn];
bool cmp (int a, int b) {return a > b;}
int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	sort(a + 1, a + 1 + n, cmp);
	if (k <= n) printf("%d", a[k]);
	else printf("0");
	return 0;
}
