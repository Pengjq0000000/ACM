#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 2e5 + 7;
const int mod = 1e9 + 7;
priority_queue<int>pq;
int p[MAXN], q[MAXN], r[MAXN];
bool cmp(int &a, int &b) {return a > b;}
int main()
{
    ll ans = 0;
    int X, Y, A, B, C; scanf("%d%d%d%d%d", &X, &Y, &A, &B, &C);
    for (int i = 1; i <= A; i++) scanf("%d", &p[i]);
    for (int i = 1; i <= B; i++) scanf("%d", &q[i]);
    for (int i = 1; i <= C; i++) scanf("%d", &r[i]);
    sort(p + 1, p + 1 + A, cmp);
    sort(q + 1, q + 1 + B, cmp);
    sort(r + 1, r + 1 + C, cmp);
    for (int i = 1; i <= X; i++) pq.push(-p[i]), ans += p[i];
    for (int i = 1; i <= Y; i++) pq.push(-q[i]), ans += q[i];
    for (int i = 1; i <= C; i++)
        if (pq.top() + r[i] > 0) ans += r[i] + pq.top(), pq.pop();
    printf("%lld\n", ans);
    return 0;
}