#include<bits/stdc++.h>
#define ll long long
#define pii pair<int, int>
#define fir first
#define sec second
using namespace std;
const int mod = 998244353;
inline int mul(int x, int y) {return (ll)x * y % mod;}
inline int add(int x, int y) {return x + y >= mod ? x + y - mod : x + y;}
inline int sub(int x, int y) {return x >= y ? x - y : x - y + mod;}
int mi[201];
inline int cal(int x)
{
    if (x <= 2) return 0;
    return sub(mi[x], add(1, add(x, x * (x - 1) / 2)));
}
int n, x[201], y[201];
pii get(int i, int j)
{
    int a = x[i] - x[j], b = y[i] - y[j];
    int g = __gcd(a, b);
    a /= g; b /= g;
    return {a, b};
}
int main()
{
    scanf("%d", &n); mi[0] = 1;
    for (int i = 1; i <= n; i++) 
    {
        scanf("%d%d", &x[i], &y[i]);
        mi[i] = mul(mi[i - 1], 2);
    }
    int ans = cal(n);
    for (int i = 1; i <= n; i++)
        for (int j = i + 1; j <= n; j++)
        {
            pii v1 = get(i, j);
            int cnt = 0;
            for (int k = j + 1; k <= n; k++) if (v1 == get(i, k)) cnt++;
            ans = sub(ans, sub(mi[cnt], 1));
        }
    printf("%d\n", ans);
    return 0;
}