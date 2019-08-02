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
	int p, n; scanf("%d%d", &n, &p);
    int x = n / (p - 1);
    if (n % (p - 1) == 0) x--;
    long double ans = (double)x / (double)(n + 1);
    ans *= (double)p;
    for (int i = 2; i <= x; i++)
    {
        ans *= (double)(n - p + i) / (double)(n + i);
    } 
    printf("%.12lf\n", (double)ans);
	return 0;
}
