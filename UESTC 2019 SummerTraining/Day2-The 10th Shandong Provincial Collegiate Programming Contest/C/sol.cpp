#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
vector<pii>pos;
int main()
{
	int T; scanf("%d", &T);
    while (T--)
    {
        int n; LL k; scanf("%d%lld", &n, &k);
        LL nowx = 0, nowy = 0;
        LL ans = 0;
        pos.clear();
        for (int i = 1; i <= n; i++) 
        {
            char ch; scanf(" %c", &ch);
            if (ch == 'R') nowx++;
            else if (ch == 'L') nowx--;
            else if (ch == 'U') nowy++;
            else if (ch == 'D') nowy--;
            pos.pb(make_pair(nowx, nowy));
            ans = max(ans, abs(nowx) + abs(nowy));
        }
        int sz = pos.size();
        for (int i = 0; i < sz; i++)
        {
            pii p = pos[i];
            LL nx = p.fir + (k - 1) * nowx;
            LL ny = p.sec + (k - 1) * nowy;
            ans = max(ans, abs(nx) + abs(ny));
        }
        printf("%lld\n", ans);
    }
	return 0;
}
