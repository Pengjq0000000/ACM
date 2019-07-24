#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 10007;
int a[maxn];
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &a[i]);
        if (a[i] % 3 == 0 && a[i] % 5 != 0) printf("F");
        else printf("B");
    }
	return 0;
}
