#include<bits/stdc++.h>
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int N = 5e4 + 7;
int a[N], b[N], cnt[210][210];
struct query{int x, y, id, op;};
vector<query>Q[N];
int ans[N];
int main()
{
    int n, q, MAX = 0; scanf("%d%d", &n, &q);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]), MAX = max(MAX, a[i]);
    for (int i = 1, x, y, l, r; i <= q; i++) 
    {
        scanf("%d%d%d%d", &l, &r, &x, &y);
        l++; r++;
        Q[r].push_back({x, y, i, 1});
        Q[l - 1].push_back({x, y, i, -1});
    } 
    int S = sqrt(MAX) + 1;
    for (int i = 1; i <= n; i++)
    {
        b[a[i]]++;
        for (int j = 1; j <= S; j++) cnt[j][a[i] % j]++;
        for (query tmp : Q[i])
        {
            int x = tmp.x, y = tmp.y, id = tmp.id, op = tmp.op;
            if (y <= S) ans[id] += op * cnt[y][x];
            else for (int j = x; j <= MAX; j += y) ans[id] += op * b[j];
        }
    }
    for (int i = 1; i <= q; i++) printf("%d\n", ans[i]);
    return 0;
}