#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define mp(a, b) make_pair(a, b)
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int C[30][30], sum[30][30];
vector<pii>ans;
void init()
{
    for (int i = 0; i <= 20; i++) sum[i][0] = C[i][0] = 1;
    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= i; j++)
            {
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
                sum[i][j] = sum[i][j - 1] + C[i][j];
            }
}
int main()
{
    init();
	int n, k; scanf("%d%d", &n, &k);
    int tot = 1;
    for (int i = 1; i <= n; i++) tot *= 2;
    tot--;
    k = tot - k;
    for (int i = n - 1; i >= 0; i--)
    {   
        if (k == 0) break;
        int j = 0;
        while (k >= sum[i][j] && j <= i)
        {
            ans.pb(mp(i + 1, j + 1));
            j++;
        }
        k -= sum[i][j - 1];
    }
    printf("%d\n", (int)ans.size());
    for (pii x : ans) printf("%d %d\n", x.first, x.second);
	return 0;
}