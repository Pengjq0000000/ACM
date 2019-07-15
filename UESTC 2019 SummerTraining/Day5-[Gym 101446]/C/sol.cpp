#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e6 + 7;
vector<int>pos[maxn + 1007];
bitset<maxn>sta, lsta, rsta;
int q[maxn], cnt[maxn];
int main()
{
	int n, m, k, l, h;  scanf("%d%d%d%d%d", &n, &m, &k, &l, &h);
    for (int i = 1; i <= k; i++) scanf("%d", &q[i]);
    while (l--)
    {
        int x, y; scanf("%d%d", &x, &y);
        pos[y].pb(x);
    }
    sta.set();
    for (int i = m + 1; i <= m + h + 1; i++)
    {
        for (int x : pos[i]) 
        {
            cnt[x]++; sta[x] = 0;
        }
    } 
    while (--m)
    {
        lsta = (sta << 1);
        rsta = (sta >> 1);
        for (int x : pos[])
        sta = (sta | lsta | rsta);
    }
	return 0;
}
