#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int n, m, p;
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &p, &n, &m);
        int x = 0;
        LL tmp = 0;
        int up = sqrt(p) + 1;
        for (int i = 1; i <= up; i++)
        {
            tmp = ((tmp * 10) + 1) % p;
            if (tmp == 0)
            {
                x = i; break;
            }
        }
        printf("%d\n", x);
    }
	return 0;
}
