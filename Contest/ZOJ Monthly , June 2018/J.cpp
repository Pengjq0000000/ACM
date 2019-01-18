#include <bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%1000000007)

using namespace std;
const int maxn = 100007;
LL  n,arr[maxn], c[maxn];

int lowbit(int x)
{
    return x & (-x);
}

int query(int x)
{
    int res = 0;
    for(; x > 0; x -= lowbit(x)) res += c[x];
    return(res);
}

void update(int x, int val)
{
    for(; x <= n; x += lowbit(x)) c[x] += val;
}

int main()
{
    int T;scanf("%d",&T);
    while (T--)
    {
        scanf("%lld", &n);
        MEM(c, 0);
        LL tmp = n * (n - 1) / 2;
        for (int i=1;i<=n;i++)
        {
            //int x;scanf("%d",&x);
            //arr[x]=i;
        }
        for(int i = 1; i <= n; i++)
        {
            scanf("%lld",&arr[i]);
            update(arr[i], 1);
            tmp = tmp - query(arr[i] - 1);
        }
        LL ans = tmp;
        for(int i = 1; i <= n; i++)
        {
            //printf("%lld\n",tmp);
            tmp = tmp - arr[i] + (n - arr[i] + 1);
            ans = min(ans, tmp);
        }
        printf("%lld\n", ans);
    }
    return 0;
}
