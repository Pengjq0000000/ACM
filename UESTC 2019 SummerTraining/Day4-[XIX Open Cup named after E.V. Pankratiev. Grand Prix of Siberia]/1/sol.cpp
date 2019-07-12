#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
bool cmp(LL a, LL b) {return abs(a) > abs(b);}
LL a[maxn];
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%lld", &a[i]);
    sort(a + 1, a + 1 + n, cmp);
    if (a[n] == 0 && a[n - 1] != 0)
    {
        puts("No"); return 0;
    }
    if (a[n] == 0 && a[n - 1] == 0)
    {
        puts("Yes"); puts("0");
        return 0;
    }
    LL tmp = a[1];
    for (int i = 2; i <= n; i++)
    {
        if (tmp % a[i] == 0) tmp /= a[i];
        else 
        {
            puts("No"); return 0;
        }
    }
    if (tmp == 1) 
    {
        puts("Yes");
        printf("%lld\n", a[1]);
    }
    else puts("No");
	return 0;
}
