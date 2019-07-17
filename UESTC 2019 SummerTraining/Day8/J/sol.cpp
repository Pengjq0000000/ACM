#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n, a[100];
bool check(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if (i == 1 && (x < 3 * a[1] || x <= a[1])) return false;
        else if (x <= a[i]) return false;
    }
    return true;
}
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d", &n); for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        for (int x = 2; x <= 40; x += 2)
        {
            if (check(x))
            {
                printf("%d\n", x);
                break;
            }
        }
    }
	return 0;
}
