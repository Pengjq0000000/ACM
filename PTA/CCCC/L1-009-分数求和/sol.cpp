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
	LL a, b, c, d;
	int n; scanf("%d", &n);
	n--; scanf("%lld/%lld", &a, &b);
	while (n--)
	{
		scanf("%lld/%lld", &c, &d);
		LL tmp = __gcd(b, d);
		LL down = b * (d / tmp);
		LL up = a * (d / tmp) + c * (b / tmp);
		a = up; b = down;
	}	
	LL tmp = __gcd(a, b);
	a /= tmp; b /= tmp;
	if (a == 0) {printf("0\n"); return 0;}
	if (a / b) printf("%lld", a / b);
	if (a / b && a % b) printf(" ");
	if (a % b) printf("%lld/%lld", a % b, b);puts("");
	return 0;
}
