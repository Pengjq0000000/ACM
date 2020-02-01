#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int MAXN = 3e5 + 7;
ll all[MAXN], val[MAXN], ans, sum[MAXN];
int n, a[MAXN];
vector<int>p;
void deal()
{
    for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] ^ val[a[i]];
    p.clear(); for (int i = 1; i <= n; i++) if (a[i] == 1) p.push_back(i);
    p.push_back(n + 1);
    for (int j = 0; j < (int)p.size() - 1; j++)
    {
        int st = p[j], ed = p[j + 1];
        for (int r = st, len = 0, l; r < ed; r++)
        {
            len = max(len, a[r]);
            l = r - len + 1;
            if (l >= 1 && (sum[r] ^ sum[l - 1]) == all[len]) ans++;
        }
    }
}
ll random() {return (ll)rand() << 15 | rand();}
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) val[i] = random() << 31 | random(), all[i] = all[i - 1] ^ val[i];
    for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
    deal();
    for (int i = 1; i <= n / 2; i++) swap(a[i], a[n + 1 - i]);
    deal();
    for (int i = 1; i <= n; i++) if (a[i] == 1) ans--;
    printf("%lld\n", ans);
    return 0;
}