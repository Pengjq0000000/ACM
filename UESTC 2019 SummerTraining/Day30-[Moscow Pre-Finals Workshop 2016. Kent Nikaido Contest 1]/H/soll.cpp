#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int cal(int n, int m)
{
    if ((n & m) == m) return 1;
    return 0;
}

int main()
{
    int N, tot; scanf("%d%d", &N, &tot);
    int res = 1 - (N & 1);
    for (int i = 1; i <= tot; i++)
    {
        int j, k;
        scanf("%d%d", &j, &k);
        res = (res + cal(N - 1, j - k) * cal(N - 1 - j + k, k - 1)) % 2;
    }
    if (res % 2 == 1) puts("Iori");
    else puts("Yayoi");
	return 0;
}
