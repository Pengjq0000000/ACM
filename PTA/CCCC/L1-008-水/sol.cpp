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
	int x, y, sum = 0, cnt = 0; scanf("%d%d", &x, &y);
	for (int i = x; i <= y; i++)
	{
		sum += i; cnt++; printf("%5d", i); 
		if (cnt % 5 == 0) printf("\n");
	}
	if (cnt % 5 != 0) printf("\n");
	printf("Sum = %d\n", sum);
	return 0;
}
