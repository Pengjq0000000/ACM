#include<bits/stdc++.h>
#define LL long long
#define MEM(x,y) memset(x,y,sizeof(x))
#define MOD(x) ((x)%mod)
#define mod 1000000007
#define pb push_back
#define STREAM_FAST ios::sync_with_stdio(false)
using namespace std;
const int maxn = 250000 + 7;
struct node
{
    int a, b;
    bool operator < (const node &rhs) const
    {
        return a - b < rhs.a - rhs.b;
    }
}x[maxn];

struct big
{
    int val, id;
    bool operator < (const big &rhs) const 
    {
        return val < rhs.val;
    }
};
struct small
{
    int val, id;
    bool operator < (const small &rhs) const 
    {
        return val > rhs.val;
    }
};
priority_queue<big>a_now, b_now;
priority_queue<small>a_can, b_can;
LL ans[maxn];
int main()
{
	int n; scanf("%d", &n);
	for (int i =1; i <= 2 * n; i++) scanf("%d%d", &x[i].a, &x[i].b);
	sort(x + 1, x + 1 + 2 * n);
    LL res = 0;
    for (int i = 1; i <= n; i++) 
    {
        res += x[i].a;
        a_now.push({x[i].a, i});
    }
    for (int i = n + 1; i <= 2 * n; i++) 
    {
        res += x[i].b;
        b_now.push({x[i].b, i});
    }
    ans[n] = res;
    for (int k = n - 1; k >= 1; k--)
    {
        int id_a = a_now.top().id;
        res -= a_now.top().val;
        a_now.pop();
        int id_b = b_now.top().id;
        res -= b_now.top().val;
        b_now.pop();

        a_can.push({x[id_b].a, id_b});
        b_can.push({x[id_a].b, id_a});

        bool flag = 1;
        while (flag)
        {
            flag = 0;
            while (a_can.size() && a_now.top().val > a_can.top().val)
            {
                flag = 1;
                int ex_a = a_can.top().id; a_can.pop();
                int out_a = a_now.top().id; a_now.pop();
                res -= x[out_a].a; res += x[ex_a].a;
                a_now.push({x[ex_a].a, ex_a});
                b_can.push({x[out_a].b, out_a});
            }
            while (b_can.size() && b_now.top().val > b_can.top().val)
            {
                flag = 1;
                int ex_b = b_can.top().id; b_can.pop();
                int out_b = b_now.top().id; b_now.pop();
                res -= x[out_b].b; res += x[ex_b].b;
                b_now.push({x[ex_b].b, ex_b});
                a_can.push({x[out_b].a, out_b});
            }
        }
        ans[k] = res;
    }
    for (int i = 1; i <= n; i++) printf("%lld\n", ans[i]);
	return 0;
}
