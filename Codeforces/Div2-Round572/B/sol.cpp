#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
int a[maxn], b[maxn];
int main()
{
	int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    sort(a + 1, a + 1 + n);
    int l = 1, r = n;
    for (int i = n; i >= 1; i -= 2)
    {
        b[l++] = a[i]; b[r--] = a[i - 1];
    }
    if (n & 1) b[(n + 1) / 2] = a[1];
    int flag = 1;
    for (int i = 2; i < n; i++) 
        if (b[i] >= b[i - 1] + b[i + 1]) flag = 0;
    if (b[1] >= b[n] + b[2]) flag = 0;
    if (b[n] >= b[n - 1] + b[1]) flag = 0;
    if (!flag) {puts("NO"); return 0;}
    puts("YES");
    for (int i = 1; i <= n; i++) printf("%d ", b[i]);
	return 0;
}
