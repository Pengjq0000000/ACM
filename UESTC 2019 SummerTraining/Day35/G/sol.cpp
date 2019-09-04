#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define pb push_back
#define pii pair<int, int>
#define fir first
#define sec second
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 50000 + 7;
const LL base1 = 100;
const LL mod1 = 1000000007;
char s[maxn][10];
LL h1[maxn][70];
LL val1[maxn];
int pos[maxn][70];
struct node{
    LL hval; int id; int sta;
    bool operator < (const node &rhs) const
    {
        return hval < rhs.hval;
    }
}t[maxn * 70];
int dis[70];
int lowbit(int x) {return (x & (-x));}
int table[70];
bool cmp(int x, int y) {return dis[x] < dis[y];}
int main()
{
    freopen("similar.in", "r", stdin);
    freopen("similar.out", "w", stdout);
	int n, k; scanf("%d%d", &n, &k);
    int bits = (1 << k);
    int tot = 0;
    for (int i = 1; i <= n; i++)
    {
        for (int kk = 0; kk < k; kk++)
            while(s[i][kk]=getchar(),s[i][kk]<33||s[i][kk]>126);
        LL tmp1 = base1;
        for (int j = 0; j < k; j++)
        {
            val1[j] = tmp1 * (s[i][j] - 30);
            tmp1 = tmp1 * base1;
        }
        for (int sta = 1; sta < bits; sta++)
        {
            int lb = lowbit(sta);
            h1[i][sta] = h1[i][sta ^ lb] + val1[__builtin_ctz(lb)];
            t[++tot] = {h1[i][sta], i, sta};
        }
    }
    sort(t + 1, t + 1 + tot);
    for (int i = 1; i <= tot; i++)
    {
        pos[t[i].id][t[i].sta] = i;
    }
    for (int sta = 0; sta < bits; sta++)
    {
        int x = 0;
        for (int j = 0; j < k; j++)
            if (!((sta >> j) & 1)) x++;
        dis[sta] = x;
    }
    dis[0] = k;
    for (int i = 0; i < bits; i++) table[i] = i;
    sort(table, table + bits, cmp);
    for (int i = 1; i <= n; i++)
    {
        int ans = k, name = 1;
        if (i == 1) name = 2;
        for (int j = 0; j < bits - 1; j++)
        {
            int sta = table[j];
            int p = pos[i][sta];
            if (t[p - 1].hval == h1[i][sta])
            {
                ans = dis[sta], name = t[p - 1].id;
                break;
            }
            else if (t[p + 1].hval == h1[i][sta])
            {
                ans = dis[sta], name = t[p + 1].id;
                break;
            }
        }
        printf("%d %d\n", ans, name);
    }
	return 0;
}
