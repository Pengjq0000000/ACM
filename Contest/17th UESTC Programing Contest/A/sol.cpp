#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int cntx[105], cnty[105], sumx[105], sumy[105];
int main()
{
	int n, m, k; scanf("%d%d%d", &n, &m, &k);
	int tot = k * k;
	for (int i = 1; i <= tot; i++)
	{
		int x, y; scanf("%d%d", &x, &y);
		cntx[x]++; cnty[y]++;
	}
	sumx[0] = sumy[0] = 0;
	int num = 0;
	for (int i = 1; i <= n; i++) 
	{
		sumx[i] = sumx[i - 1] + cntx[i];
		if (sumx[i] % k == 0 && sumx[i] != sumx[i - 1]) {num++; printf("%d ", i);}
		if (num == k - 1) break;
	}
	puts("");
	num = 0;
	for (int i = 1; i <= m; i++) 
	{
		sumy[i] = sumy[i - 1] + cnty[i];
		if (sumy[i] % k == 0 && sumy[i] != sumy[i - 1]) {num++; printf("%d ", i);}
		if (num == k - 1) break;
	}
	puts("");
	return 0;
}
