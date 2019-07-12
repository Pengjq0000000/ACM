#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
char s[maxn];
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int k; scanf("%d", &k);
        scanf(" %s", s + 1);
        int n, m; scanf("%d%d", &n, &m);
        for (int i = 1; i <= m; i++)
        {
            int u, v; scanf("%d%d", &u, &v);
        }
        int dt = m - n + 2;
        char ch = s[(dt - 1) % k + 1];
        printf("%c\n", ch == '1' ? '2' : '1');
    }
	return 0;
}
