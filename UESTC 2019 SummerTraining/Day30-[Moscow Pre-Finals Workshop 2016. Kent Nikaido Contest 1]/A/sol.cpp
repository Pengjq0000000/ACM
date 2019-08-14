#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
char mp[55][55];
int n, cnt[4];
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf(" %s", mp[i] + 1);
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (mp[i][j] == 'o') cnt[(i + j) % 4]++;
        }
    }
    int mi = 100000;
    for (int i = 0; i < 4; i++) mi = min(mi, cnt[i]);
    printf("%d\n", (mi & 1)); 
	return 0;
}
