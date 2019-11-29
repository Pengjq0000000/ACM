#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 7;
struct line 
{
    int l, r, d;
    bool operator < (const line &rhs) const 
    {
        return r < rhs.l;
    }
    void merge(line x) {l = min(l, x.l); r = max(r, x.r);}
}b[MAXN];
set<line>s;
int m, n, k, t; 
int cnt[MAXN];
bool check(int x)
{
    s.clear();
    for (int i = 1; i <= k; i++)
    {
        if (b[i].d <= x) continue;
        line temp = b[i];
        while (1)
        {
            auto it = s.find(temp);
            if (it == s.end()) break;
            temp.merge(*it); s.erase(it);
        }
        s.insert(temp);
    }
    int sum = 0;
    for (line temp : s) sum += temp.r - temp.l + 1;
    return sum * 2 + n + 1 <= t;
}
int main()
{
    scanf("%d%d%d%d", &m, &n, &k, &t);
    for (int i = 1, x; i <= m; i++) scanf("%d", &x), cnt[x]++;
    for (int i = 1; i <= 200000; i++) cnt[i] += cnt[i - 1];
    for (int i = 1; i <= k; i++) scanf("%d%d%d", &b[i].l, &b[i].r, &b[i].d);
    int l = 1, r = 200000;
    while (l < r)
    {
        int mid = (l + r) / 2;
        if (check(mid)) r = mid;
        else l = mid + 1;
    } 
    printf("%d\n", m - cnt[l - 1]);
    return 0;
}