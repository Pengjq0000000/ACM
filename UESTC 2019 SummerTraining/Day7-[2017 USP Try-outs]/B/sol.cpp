#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
char s[maxn];
int main()
{
	int n; scanf("%d", &n);
    if ((n % 4 == 1) || (n % 4 == 2)) 
    {
        puts("-1");
        return 0;
    }
    if (n % 4 == 3)
    {
        printf("++-");
        n -= 3;
    }
    for (int i = 1; i <= n / 2; i += 2)
    {
        s[i] = '-'; s[n - i + 1] = '-';
        s[i + 1] = '+'; s[n - i] = '+';
    }
    for (int i = 1; i <= n; i++) printf("%c", s[i]);
	return 0;
}
