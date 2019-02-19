#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
int a[maxn], num[maxn], bad[maxn], nxt[maxn];
int b[maxn], up[maxn], down[maxn];
vector<int>v;
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);

    int tot = 0;
    for (int i = 2; i <= n; i++) if (a[i - 1] > a[i]) b[++tot] = i - 1;
    b[++tot] = n;
    int j = 1;
    for (int i = 1; i <= n; i++)
    {
        up[i] = b[j];
        if (i == b[j]) j++;
    }

    tot = 0;
    for (int i = 2; i <= n; i++) if (a[i - 1] <= a[i]) b[++tot] = i - 1;
    b[++tot] = n;
    j = 1;
    for (int i = 1; i <= n; i++)
    {
        down[i] = b[j];
        nxt[i] = max(up[i], down[i]);
        if (i == b[j]) j++;
    }
    //for (int i = 1; i <= n; i++) printf("%d ", nxt[i]);puts("");

    for (int d = 2; d <= n; d++)
    {
        int now = 0, last = 0;
        int cnt = 0, tmp = 0;
        while (now + 1 <= n)
        {
            now++;
            now = nxt[now]; cnt++;
            if (now - last < d && now < n)
            {
                tmp += min(n, d + last) - now;
                now = min(n, d + last);
            }
            last = now;
        }
        num[d] = cnt;
        bad[d] = tmp;
    }



    int q; scanf("%d", &q);
    while (q--)
    {
        int x; scanf("%d", &x);
        printf("%d %d\n", num[x], bad[x]);
    }


    return 0;
}
/*
15
2 4 4 3 -1 -2 -2 5 6 5 4 3 2 3 4
3
3
4
5

*/

