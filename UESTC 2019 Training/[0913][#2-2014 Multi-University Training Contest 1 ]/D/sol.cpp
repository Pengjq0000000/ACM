#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 1e5 + 7;
struct node
{
    int x, y;
    bool operator < (const node &rhs)
    {
        if (x == rhs.x) return y > rhs.y;
        return x > rhs.x;
    }
}work[maxn], task[maxn];
multiset<int>Y[107];
int main()
{
    int n, m;
    while (~scanf("%d%d", &n, &m))
    {
        for (int i = 0; i <= 100; i++) Y[i].clear();
        for (int i = 1; i <= n; i++)
        {
            scanf("%d%d", &work[i].x, &work[i].y);
            Y[work[i].y].insert(work[i].x);
        }
        for (int i = 1; i <= m; i++) scanf("%d%d", &task[i].x, &task[i].y);
        sort(task + 1, task + 1 + m);
        int cnt = 0;
        LL ans = 0;
        for (int i = 1; i <= m; i++)
        {
            for (int k = task[i].y; k <= 100; k++)
            {
                if (!Y[k].size()) continue;
                if ((*Y[k].rbegin()) < task[i].x) continue;

                Y[k].erase(Y[k].lower_bound(task[i].x));
                cnt++;
                ans += 500 * task[i].x + 2 * task[i].y;
                break;
            }
        }
        printf("%d %lld\n", cnt, ans);
    }
    return 0;
}
