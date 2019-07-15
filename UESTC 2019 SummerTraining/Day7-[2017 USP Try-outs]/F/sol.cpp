#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL R; 
int cal(int x, int y)
{
    LL dis = x * x + y * y;
    for (int i = 1; i <= 10; i++)
    {
        LL DIS = (LL)i * i * R * R;
        if (DIS >= dis) return (10 - i + 1);
    }
    return 0;
}
int main()
{
    scanf("%lld", &R);
    int ans = 0;
    for (int i = 1; i <= 3; i++)
    {
        int x, y; scanf("%d%d", &x, &y);
        ans += cal(x, y);
    }
    printf("%d\n", ans);
	return 0;
}
