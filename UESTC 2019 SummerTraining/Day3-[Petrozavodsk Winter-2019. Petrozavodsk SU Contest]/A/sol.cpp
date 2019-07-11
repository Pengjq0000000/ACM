#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
int ask(int x, int y)
{
    printf("Q %d %d\n", x, y);
    fflush(stdout);
    int res; scanf("%d", &res);
    return res;
}
void gotit(int x, int y)
{
    printf("A %d %d\n", x, y);
    fflush(stdout);
}
int tot = 0;
pair<int, int>table[20000];
vector<int> pdis[20000];
int cal(int x, int y)
{
    if (x < 0 || x > 100 || y < 0 || y > 100) return -1;
    return x * x + (y - 677) * (y - 677);
}
int main()
{
	int dis = ask(0, 677);
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (x * x + (y - 677) * (y - 677) == dis)
            {
                table[++tot] = (make_pair(x, y));
                pdis[tot].pb(cal(x - 1, y));
                pdis[tot].pb(cal(x + 1, y));
                pdis[tot].pb(cal(x, y - 1));
                pdis[tot].pb(cal(x, y + 1));
            }
        }
    }
    int newdis = ask(0, 677);
    for (int i = 1; i <= tot; i++)
    {
        for (int dd : pdis[i])
        {
            if (dd == newdis)
            {
                gotit(table[i].first, table[i].second);
                return 0;
            }
        }
    }
	return 0;
}
