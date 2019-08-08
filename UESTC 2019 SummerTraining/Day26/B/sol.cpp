#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
LL a[100];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; scanf("%d", &n);
        for (int i = n; i >= 0; i--) scanf("%lld", &a[i]);
        if (n < 2) 
        {
            puts("Yes"); continue;
        }
        if (n > 2) 
        {
            puts("No"); continue;
        }
        if (n == 2)
        {
            LL A = a[2], B = a[1], C = a[0];
            LL det = B * B - 4 * A * C;
            if (det >= 0) puts("No");else puts("Yes");
            continue;
        }
    }
	return 0;
}
