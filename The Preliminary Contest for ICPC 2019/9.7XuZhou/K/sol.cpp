#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int> 
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1007;
const int det = 1e6 + 1;
pii p[maxn];
int n;
unordered_map<LL, int>cnt;
int main()
{
	scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &p[i].first, &p[i].second);
    }
    sort(p + 1, p + 1 + n);
    n = unique(p + 1, p + 1 + n) - (p + 1);
    
    int tmp = 0;
    for (int i = 1; i < n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            int midx = p[i].first + p[j].first, midy = p[i].second + p[j].second;
            LL id = (LL)midx * (2 * det + 10) + midy;
            cnt[id] += 2;
            tmp = max(tmp, cnt[id]);
        }
    for (int i = 1; i <= n; i++)
    {
        LL id = (LL)p[i].first * (2 * det + 10) + p[i].second;
        cnt[id * 2]++;
        tmp = max(tmp, cnt[id * 2]);
    }
    int ans = n - tmp;
    printf("%d\n", ans);
    
	return 0;
}
