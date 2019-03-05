#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)

using namespace std;
const int maxn = 1e5 + 7;
const int N = 100000;
int n, c[maxn], ans[maxn];
struct P
{
    int x, y; 
    bool operator < (const P &rhs) const
    {
        if (y == rhs.y) return x < rhs.x;
        return y < rhs.y;
    }
}p[maxn];
int lowbit(int x) {return x & (-x);}
void update(int x, int val)
{
    for (; x <= N; x += lowbit(x)) c[x] += val;
}
int getsum(int x)
{
    int res = 0;
    for (; x; x -= lowbit(x)) res += c[x];
    return res;
}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) scanf("%d%d", &p[i].x, &p[i].y);
    sort(p + 1, p + 1 + n);
    for (int i = 1; i <= n; i++)
    {
        int tmp = getsum(p[i].x);
        ans[tmp]++;
        update(p[i].x, 1);
    } 
    for (int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}

