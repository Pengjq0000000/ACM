#include<bits/stdc++.h>
using namespace std;
const int MAXN = 50007;
struct node{int val, pos;};
deque<node>qmax, qmin;
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    long long ans = 0;
    for (int i = 1, j = 1, x; i <= n; i++)
    {
        scanf("%d", &x);
        while (qmax.size() && qmax.back().val <= x) qmax.pop_back();
        qmax.push_back({x, i});
        while (qmin.size() && qmin.back().val >= x) qmin.pop_back();
        qmin.push_back({x, i});
        while (qmax.front().val - qmin.front().val > k)
        {
            j++; 
            if (qmax.front().pos < j) qmax.pop_front();
            if (qmin.front().pos < j) qmin.pop_front();
        }
        ans += (i - j + 1);
    }
    printf("%lld\n", ans);
    return 0;
}