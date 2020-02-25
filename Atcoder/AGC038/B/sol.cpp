#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
int a[MAXN], MIN[MAXN], MAX[MAXN];
int len[MAXN];
bool b[MAXN];
struct node{int pos, val;};
deque<node>qmin, qmax;

int f[MAXN];
int find(int x) {return x == f[x] ? x : f[x] = find(f[x]);}
void unite(int x, int y)
{
    x = find(x), y = find(y);
    if (x == y) return;
    if (x < y) swap(x, y);
    f[x] = y;
}
vector<int>vec;
int main()
{
    int n, k; scanf("%d%d", &n, &k);
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++) f[i] = i;
    for (int i = 1; i <= n; i++)
    {
        if (a[i] >= a[i - 1]) len[i] = len[i - 1] + 1;
        else len[i] = 1;
        if (len[i] >= k) b[i] = 1;
        if (b[i]) vec.push_back(i);
    }
    for (int i = 1; i < vec.size(); i++) unite(vec[i - 1], vec[i]);
    for (int i = 1; i <= n; i++) 
    {
        while (qmin.size() && qmin.front().pos < i - k) qmin.pop_front();
        while (qmin.size() && qmin.back().val >= a[i]) qmin.pop_back();
        qmin.push_back({i, a[i]});

        while (qmax.size() && qmax.front().pos < i - k) qmax.pop_front();
        while (qmax.size() && qmax.back().val <= a[i]) qmax.pop_back();
        qmax.push_back({i, a[i]});
        if (i > k)
        {
            if (qmin.front().val == a[i - k] && qmax.front().val == a[i]) unite(i - 1, i);
        }
    }
    int ans = 0;
    for (int i = k; i <= n; i++) if (find(i) == i) ans++;
    printf("%d\n", ans);
    return 0;
}