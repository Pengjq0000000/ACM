#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
priority_queue<pii>pq;
int main()
{
    int n; scanf("%d", &n);
    for (int i = 1, x, L, st, ed; i <= n; i++)
    {
        scanf("%d%d", &x, &L);
        st = x - L; ed = x + L;
        pq.push({-ed, st});
    } 
    int now = -1e9, ans = 0;
    for (int i = 1; i <= n; i++)
    {
        while (pq.size() && now > pq.top().sec) pq.pop();
        if (pq.size()) {now = -pq.top().fir; ans++; pq.pop();}
    }
    printf("%d\n", ans);
    return 0;
}