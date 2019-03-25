#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;

int main()
{
	int n; scanf("%d", &n);
	int up = sqrt(n);
	int ans = 0, head = 0;
	for (int i = 2; i <= up; i++)
	{
		int m = n;
		int tmp = i, cnt = 0; 
		while (m % tmp == 0) {m /= tmp; tmp++; cnt++;}
		if (cnt > ans) {ans = cnt; head = i;}
	}	
	if (ans == 0) {ans = 1; head = n;}
	printf("%d\n", ans);
	printf("%d", head);
	for (int j = 1; j < ans; j++) printf("*%d", head + j); puts("");
	return 0;
}
