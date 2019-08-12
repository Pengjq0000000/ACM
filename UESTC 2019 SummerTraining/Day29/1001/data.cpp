#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5;
LL random(LL x)
{
    return (LL)rand() * rand() % x;
}
int main()
{
    srand(unsigned(time(0)));
    printf("%d\n", 100);
    for (int k = 1; k <= 100; k++)
	{
        LL a = random(10000000), b = random(10000000);
        printf("%lld %lld %lld\n", a, b, a + b);
    }
	return 0;
}
