#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 3e5 + 7;
struct node
{
    LL low, up;
    bool operator < (const node &rhs) const
    {
        return (low + up) > (rhs.low + rhs.up);
    }
}a[maxn];
LL anslow[maxn], ansup[maxn];
priority_queue<int>pq;
priority_queue<int, vector<int>, greater<int> >q;
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &a[i].low, &a[i].up);
    }
    sort(a + 1, a + 1 + n);
    LL sum = 0;
    for (int i = 1; i <= n; i++)
    {
        LL x = (a[i].up + a[i].low);
        while (pq.size() && pq.top() * 2 >= x)
        {
            sum -= pq.top();
            pq.pop();
        }
        anslow[i] = x * pq.size() - 2 * sum;

        pq.push(a[i].low);
        sum += a[i].low;
    }
    sum = 0;
    for (int i = n; i >= 1; i--)
    {
        LL x = (a[i].low + a[i].up);
        while (q.size() && q.top() * 2 <= x)
        {
            sum -= q.top();
            q.pop();
        }
        ansup[i] = 2 * sum - x * q.size();

        q.push(a[i].up);
        sum += a[i].up;
    }
    LL ans = 0;

    for (int i = 1; i <= n; i++)
    {
        //printf("%d: anslow=%lld ansup=%lld\n", i, anslow[i], ansup[i]);
        ans = max(ans, anslow[i] + ansup[i] + (a[i].up - a[i].low));
    }
    printf("%lld\n", ans);
	return 0;
}

