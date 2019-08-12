#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pii pair<int, int>
#define fir first
#define sec second
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
vector<int>vec;
vector<pii>pos[maxn];
struct P{int x, y; }p[maxn];
int getid(int x) {return lower_bound(vec.begin(), vec.end(), x) - vec.begin() + 1;}
bool block[maxn][4];
int main()
{    
    int n;scanf("%d", &n);
    for (int i = 1, x, y; i <= n; i++)
    {
        scanf("%d%d", &x, &y);
        p[i].x = x + y; p[i].y = x - y;
        vec.pb(p[i].x); vec.pb(p[i].y);
    }
    sort(vec.begin(), vec.end());
    vec.erase(unique(vec.begin(), vec.end()), vec.end());
    for (int i = 1; i <= n; i++)
    {
        p[i].x = getid(p[i].x);
        p[i].y = getid(p[i].y);
        pos[p[i].x].pb({p[i].y, i});
    }
    int mi = 2e9 + 7, mx = -(2e9 + 7);
    int N = vec.size();
    for (int x = 1; x <= N; x++)
    {
        for (pii pt : pos[x])
        {
            if (pt.fir > mi) block[pt.sec][0] = 1;
            if (pt.fir < mx) block[pt.sec][1] = 1;
        }
        for (pii pt : pos[x]) mi = min(mi, pt.fir), mx = max(mx, pt.fir);
    }
    mi = 2e9 + 7, mx = -(2e9 + 7);
    for (int x = N; x >= 1; x--)
    {
        for (pii pt : pos[x])
        {
            if (pt.fir > mi) block[pt.sec][2] = 1;
            if (pt.fir < mx) block[pt.sec][3] = 1;
        }
        for (pii pt : pos[x]) mi = min(mi, pt.fir), mx = max(mx, pt.fir);
    }
    int ans = n;
    for (int i = 1; i <= n; i++)
    {
        bool flag = 1;
        for (int j = 0; j < 4; j++)
            if (!block[i][j]) {flag = 0; break;}
        ans -= flag;
    }
    printf("%d\n", ans);
	return 0; 
}
