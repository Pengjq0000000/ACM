#include<bits/stdc++.h>
#define LL long long
using namespace std;
const int N = 1e5 + 7;
int a[N], pos[N];
bool b[N], vis[N]; 
LL C[N], sum[N];
vector<int>vec[N];
map<int, int>id;
set<int>s;
bool check(int x)
{
    while (x) {int d = x % 10; if (d != 4 && d != 7) return false; x /= 10;}
    return true;
}
int main()
{
    for (int i = 1; i <= 100001; i++) C[i] = (LL)i * (i - 1) / 2, sum[i] = sum[i - 1] + C[i];
    int n, tot = 0, cnt = 0; scanf("%d", &n);
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d", &a[i]); b[i] = check(a[i]);
        if (!b[i]) continue;
        if (!id.count(a[i])) id[a[i]] = ++tot;
        vec[id[a[i]]].push_back(i);
        pos[++cnt] = i;
    }
    LL ans = 0; int now = 1; 
    pos[cnt + 1] = n + 1;
    for (int i = 1; i <= n; i++)
    {
        if (b[i]) now++;
        else ans += C[i] * (pos[now] - i);
    }
    for (int i = 1; i <= cnt; i++)
    {
        s.clear(); s.insert(0);
        for (int k = 1; k <= tot; k++) vis[k] = 0;
        LL tmp = 0;
        for (int j = i; j <= cnt; j++)
        {
            int now = id[a[pos[j]]];
            if (!vis[now])
            {
                vis[now] = 1;
                for (int p : vec[now]) 
                {
                    if (p >= pos[i]) break;
                    s.insert(p); auto it = s.find(p);
                    int posr, posl;
                    it--; posl = *it; it++;
                    it++;
                    if (it != s.end()) 
                    {   
                        posr = *it;
                        tmp -= C[(posr - posl - 1) + 1];
                        tmp += C[(p - posl - 1) + 1] + C[(posr - p - 1) + 1];
                    }
                    else tmp += C[(p - posl - 1) + 1];
                }
            }
            int l2 = pos[i] - pos[i - 1];
            int r2 = pos[j + 1] - pos[j];
            ans += tmp * l2 * r2;
            auto it = s.end(); it--; int p = *it;
            ans += (sum[(pos[i] - p - 1) + 1] - sum[(pos[i - 1] - p - 1) + 1]) * r2;
        }
    }
    printf("%lld\n", ans);
    return 0;
}