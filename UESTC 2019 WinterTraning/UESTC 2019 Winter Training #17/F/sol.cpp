#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 127;
int l[maxn], r[maxn];
int now;
map<LL, int>id;
void dfs(LL x)
{
    if (id.count(x) || x == 1) return;
    dfs(x - x / 2);
    dfs(x / 2);
    l[now] = id[x - x / 2];
    r[now] = id[x / 2];
    id[x] = now++;
}
int main()
{
    int T; scanf("%d", &T);
    while (T--)
    {
        LL n; scanf("%lld", &n);
        id.clear(); id[1] = 0; now = 1;
        dfs(n);
        printf("%d\n", now);
        printf("-1 -1\n");
        for (int i = 1; i < now; i++) printf("%d %d\n", l[i], r[i]);
        printf("%d\n", now - 1);
    }
    return 0;
}

